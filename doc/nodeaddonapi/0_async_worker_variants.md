# AsyncProgressWorker

`Napi::AsyncProgressWorker` 使用 `Napi::ThreadSafeFunction` 扩展了 `Napi::AsyncWorker`, 使得 worker thread 能在执行中给 event loop threads 消息.

执行中, `Napi::AsyncProgressWorker::ExecutionProgress::Send` 发消息, `Napi::AsyncProgressWorker::OnProgress`接受.

## Methods

[`Napi::AsyncWorker`][] provides detailed descriptions for most methods.

### OnProgress

`Napi::AsyncProgress[Queue]Worker::ExecutionProcess::Signal` 也可引发执行, 但是 `data` parameter will be `nullptr`.

```cpp
virtual void Napi::AsyncProgressWorker::OnProgress(const T* data, size_t count)
```

# AsyncProgressWorker::ExecutionProcess

## Methods

### Send

`Napi::AsyncProgressWorker::ExecutionProcess::Send` takes two arguments, 一个数据指针, `size_t` 指针指向的数据个数.

数据使用了线程间复制, `Napi::AsyncProgressWorker::ExecutionProcess::Send` 调用后即可释放数据

多次调用, 可能发生 `Napi::AsyncProgressWorker::OnProgress` 只收到最后一次数据的情况. 如果需要保证 `OnProgress` for every `Send` call, 应使用 `Napi::AsyncProgressQueueWorker`

```cpp
void Napi::AsyncProgressWorker::ExecutionProcess::Send(const T* data, size_t count) const;
```

### Signal

触发 `Napi::AsyncProgressWorker::OnProgress` with `nullptr` as the `data` parameter.

```cpp
void Napi::AsyncProgressWorker::ExecutionProcess::Signal();
```

## Example

During the worker thread execution, the first argument of `Napi::AsyncProgressWorker::Execute` 可用于报告进展

```cpp
#include <napi.h>

#include <chrono>
#include <thread>

using namespace Napi;

class EchoWorker : public AsyncProgressWorker<uint32_t>
{
    public:
        EchoWorker(Function& okCallback, std::string& echo)
        : AsyncProgressWorker(okCallback), echo(echo) {}

        ~EchoWorker() {}

        // This code will be executed on the worker thread
        void Execute(const ExecutionProgress& progress) {
            // Need to simulate cpu heavy task
            // Note: This Send() call is not guaranteed to trigger an equal
            // number of OnProgress calls
            for (uint32_t i = 0; i < 100; ++i) {
              progress.Send(&i, 1)
            }
        }

        void OnError(const Error &e) {
            HandleScope scope(Env());
            // Pass error onto JS, no data for other parameters
            Callback().Call({String::New(Env(), e.Message())});
        }

        void OnOK() {
            HandleScope scope(Env());
            // Pass no error, give back original data
            Callback().Call({Env().Null(), String::New(Env(), echo)});
        }

        void OnProgress(const uint32_t* data, size_t /* count */) {
            HandleScope scope(Env());
            // Pass no error, no echo data, but do pass on the progress data
            Callback().Call({Env().Null(), Env().Null(), Number::New(Env(), *data)});
        }

    private:
        std::string echo;
};
```

```cpp
#include <napi.h>

// Include EchoWorker class
// ..

using namespace Napi;

Value Echo(const CallbackInfo& info) {
    // We need to validate the arguments here
    std::string in = info[0].As<String>();
    Function cb = info[1].As<Function>();
    EchoWorker* wk = new EchoWorker(cb, in);
    wk->Queue();
    return info.Env().Undefined();
}

// Register the native method for JS to access
Object Init(Env env, Object exports)
{
    exports.Set(String::New(env, "echo"), Function::New(env, Echo));

    return exports;
}

// Register our native addon
NODE_API_MODULE(nativeAddon, Init)
```

```js
const { nativeAddon } = require("binding.node");

const exampleCallback = (errorResponse, okResponse, progressData) => {
  // Use the data accordingly
  // ...
};

// Call our native addon with the parameters of a string and a function
nativeAddon.echo("example", exampleCallback);
```

# AsyncProgressQueueWorker

能够保证每一次 send 都触发, 并且保证顺序.

# AsyncProgressQueueWorker::ExecutionProcess

## Example

```cpp
#include <napi.h>

#include <chrono>
#include <thread>

using namespace Napi;

class EchoWorker : public AsyncProgressQueueWorker<uint32_t> {
    public:
        EchoWorker(Function& okCallback, Function& errorCallback, Function& progressCallback, std::string& echo)
        : AsyncProgressQueueWorker(okCallback), echo(echo) {
            // Set our function references to use them below
            this->errorCallback.Reset(errorCallback, 1);
            this->progressCallback.Reset(progressCallback, 1);
        }

        ~EchoWorker() {}

        // This code will be executed on the worker thread
        void Execute(const ExecutionProgress& progress) {
            // Need to simulate cpu heavy task to demonstrate that
            // every call to Send() will trigger an OnProgress function call
            for (uint32_t i = 0; i < 100; ++i) {
              progress.Send(&i, 1);
            }
        }

        void OnOK() {
            HandleScope scope(Env());
            // Call our onOkCallback in javascript with the data we were given originally
            Callback().Call({String::New(Env(), echo)});
        }

        void OnError(const Error &e) {
            HandleScope scope(Env());

            // We call our callback provided in the constructor with 2 parameters
            if (!this->errorCallback.IsEmpty()) {
                // Call our onErrorCallback in javascript with the error message
                this->errorCallback.Call(Receiver().Value(), {String::New(Env(), e.Message())});
            }
        }

        void OnProgress(const uint32_t* data, size_t /* count */) {
            HandleScope scope(Env());

            if (!this->progressCallback.IsEmpty()) {
                // Call our onProgressCallback in javascript with each integer from 0 to 99 (inclusive)
                // as this function is triggered from the above Send() calls
                this->progressCallback.Call(Receiver().Value(), {Number::New(Env(), *data)});
            }
        }

    private:
        std::string echo;
        FunctionReference progressCallback;
        FunctionReference errorCallback;

};
```

```cpp
#include <napi.h>

// Include EchoWorker class
// ..

using namespace Napi;

Value Echo(const CallbackInfo& info) {
    // We need to validate the arguments here.
    std::string in = info[0].As<String>();
    Function errorCb = info[1].As<Function>();
    Function okCb = info[2].As<Function>();
    Function progressCb = info[3].As<Function>();
    EchoWorker* wk = new EchoWorker(okCb, errorCb, progressCb, in);
    wk->Queue();
    return info.Env().Undefined();
}

// Register the native method for JS to access
Object Init(Env env, Object exports)
{
    exports.Set(String::New(env, "echo"), Function::New(env, Echo));

    return exports;
}

// Register our native addon
NODE_API_MODULE(nativeAddon, Init)
```

```js
const { nativeAddon } = require("binding.node");

const onErrorCallback = (msg) => {
  // Use the data accordingly
  // ...
};

const onOkCallback = (echo) => {
  // Use the data accordingly
  // ...
};

const onProgressCallback = (num) => {
  // Use the data accordingly
  // ...
};

// Call our native addon with the parameters of a string and three callback functions
nativeAddon.echo("example", onErrorCallback, onOkCallback, onProgressCallback);
```

[`Napi::AsyncWorker`]: ./async_worker.md
