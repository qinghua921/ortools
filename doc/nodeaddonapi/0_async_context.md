# AsyncContext

## Methods

### Constructor

```cpp
explicit Napi::AsyncContext::AsyncContext(napi_env env, const char* resource_name);
```

- `[in] resource_name`: 名称标记

```cpp
explicit Napi::AsyncContext::AsyncContext(napi_env env, const char* resource_name, const Napi::Object& resource);
```

- `[in] resource`: 附加资源

### Destructor

```cpp
virtual Napi::AsyncContext::~AsyncContext();
```

## Example

```cpp
#include "napi.h"

void MakeCallbackWithAsyncContext(const Napi::CallbackInfo& info) {
  Napi::Function callback = info[0].As<Napi::Function>();
  Napi::Object resource = info[1].As<Napi::Object>();

  // Create a new async context instance.
  Napi::AsyncContext context(info.Env(), "async_context_test", resource);

  // Invoke the callback with the async context instance.
  callback.MakeCallback(Napi::Object::New(info.Env()),
      std::initializer_list<napi_value>{}, context);

  // The async context instance is automatically destroyed here because it's
  // block-scope like `Napi::HandleScope`.
}
```
