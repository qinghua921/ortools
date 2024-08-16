# AsyncWorker

`Napi::AsyncWorker` 抽象类用于简化 event loop, worker threads 间的数据交换.
简化 creating and executing 异步操作.

调用 `Napi::AsyncWorker::Queue` 后. 当有线程可用时, 将执行 `Napi::AsyncWorker::Execute`.

`Napi::AsyncWorker::Execute` 执行完毕会调用 `Napi::AsyncWorker::OnOK` or `Napi::AsyncWorker::OnError`.

`Napi::AsyncWorker::OnOK` or `Napi::AsyncWorker::OnError` 完结后, `Napi::AsyncWorker` 实例销毁.

多数情况下, 需要实现 `Napi::AsyncWorker::Execute`

## Methods

### Queue

压入待执行代码

```cpp
void Napi::AsyncWorker::Queue();
```

### Cancel

取消执行, 注意: 已经开始执行时, 无法取消. 取消成功后, `OnOK` nor `OnError` 也被取消.

```cpp
void Napi::AsyncWorker::Cancel();
```

### Receiver

```cpp
Napi::ObjectReference& Napi::AsyncWorker::Receiver();
```

结果接受对象

### Callback

```cpp
Napi::FunctionReference& Napi::AsyncWorker::Callback();
```

除非覆写 `Napi::AsyncWorker::OnOK` or
`Napi::AsyncWorker::OnError`, 此方法会收到结果

### SuppressDestruct

```cpp
void Napi::AsyncWorker::SuppressDestruct();
```

阻止析构 `Napi::AsyncWorker` 直到调用 `Napi::AsyncWorker::OnOK`.

### SetError

运行时设定异常, `Napi::AsyncWorker::OnError` 将会调用.

```cpp
void Napi::AsyncWorker::SetError(const std::string& error);
```

### Execute

此方法中, 不能使用 node-addon-api 的代码, 也禁止与 JavaScript 交互

```cpp
virtual void Napi::AsyncWorker::Execute() = 0;
```

### OnOK

默认调用 `AsyncWorker` 创建时给的 `Callback`. `Callback` 默认没有参数. 可覆写 `GetResult()` 给 `Callback` 传参.

```cpp
virtual void Napi::AsyncWorker::OnOK();
```

### GetResult

默认返回 empty vector

```cpp
virtual std::vector<napi_value> Napi::AsyncWorker::GetResult(Napi::Env env);
```

### OnError

默认调用 `Callback`, 且用 error 作为第一个参数.

```cpp
virtual void Napi::AsyncWorker::OnError(const Napi::Error& e);
```

### OnWorkComplete

在 JavaScript thread 运行. 默认调用 `Napi::AsyncWorker::OnOk` or `Napi::AsyncWorker::Error`. 如使用了 `SuppressDestruct()`, 再调用
`Napi::AsyncWorker::Destroy`

```cpp
virtual void OnWorkComplete(Napi::Env env, napi_status status);
```

### OnExecute

在 work thread 运行. 默认 call `Napi::AsyncWorker::Execute`
and 处理 C++ exceptions( 如果 cpp exceptions were enabled).

有 `napi_env` 参数. 但是禁止使用.

```cpp
virtual void OnExecute(Napi::Env env);
```

### Destroy

如没有调用过 `SuppressDestruct()`, `OnError()` or `OnOK()` 后, 会调用它. 默认使用 `delete` 释放该实例.

```cpp
virtual void Napi::AsyncWorker::Destroy();
```

### Constructor

```cpp
explicit Napi::AsyncWorker(const Napi::Function& callback);
```

- `[in] callback`: 在 JS thread 运行.

```cpp
explicit Napi::AsyncWorker(const Napi::Function& callback, const char* resource_name);
```

- `[in] resource_name`: 标识

```cpp
explicit Napi::AsyncWorker(const Napi::Function& callback, const char* resource_name, const Napi::Object& resource);
```

- `[in] resource`: 其他参数

```cpp
explicit Napi::AsyncWorker(const Napi::Object& receiver, const Napi::Function& callback);
```

- `[in] receiver`: The `this` object passed to the called function.

```cpp
explicit Napi::AsyncWorker(const Napi::Object& receiver, const Napi::Function& callback, const char* resource_name);
```

```cpp
explicit Napi::AsyncWorker(const Napi::Object& receiver, const Napi::Function& callback, const char* resource_name, const Napi::Object& resource);
```

```cpp
explicit Napi::AsyncWorker(Napi::Env env);
```

- `[in] env`: The environment in which to create the `Napi::AsyncWorker`.

```cpp
explicit Napi::AsyncWorker(Napi::Env env, const char* resource_name);
```

```cpp
explicit Napi::AsyncWorker(Napi::Env env, const char* resource_name, const Napi::Object& resource);
```

### Destructor

```cpp
virtual Napi::AsyncWorker::~AsyncWorker();
```

## Example

可以使用属性传递数据.

`Napi::AsyncWorker::Execute` 不在 **event loop** 线程运行. `Napi::AsyncWorker::OnOK` or `Napi::AsyncWorker::OnError` 在 **event loop** 线程运行.

```cpp
#include<napi.h>

#include <chrono>
#include <thread>

using namespace Napi;

class EchoWorker : public AsyncWorker
{
public:
    EchoWorker(Function& callback, std::string& echo)
    : AsyncWorker(callback), echo(echo) {}

    ~EchoWorker() {}
// This code will be executed on the worker thread
void Execute() override
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void OnOK() override
{
    HandleScope scope(Env());
    Callback().Call({Env().Null(), String::New(Env(), echo)});
}

private:
    std::string echo;
};
```

```cpp
#include<napi.h>

// Include EchoWorker class
// ..

using namespace Napi;

Value Echo(const CallbackInfo& info)
{
    Function cb = info[1].As<Function>();
    std::string in = info[0].As<String>();
    EchoWorker* wk = new EchoWorker(cb, in);
    wk->Queue();
    return info.Env().Undefined();
}
```
