# Promise

`Napi::Promise` 和 `Napi::Promise::Deferred` 对应 Promise 对象.

```cpp
Napi::Value YourFunction(const Napi::CallbackInfo& info) {
  // your code goes here...
  Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(info.Env());
  // deferred needs to survive this call...
  return deferred.Promise();
}
```

之后使用 `Resolve` or `Reject` 返回结果:

```cpp
  deferred.Resolve(String::New(info.Env(), "OK"));
```

## Promise::Deferred Methods

### Factory Method

```cpp
static Napi::Promise::Deferred Napi::Promise::Deferred::New(napi_env env);
```

### Constructor

```cpp
Napi::Promise::Deferred(napi_env env);
```
