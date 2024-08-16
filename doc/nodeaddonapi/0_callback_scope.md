# CallbackScope

## Methods

### Constructor

```cpp
Napi::CallbackScope::CallbackScope(napi_env env, napi_callback_scope scope);
```

- `[in] scope`: The pre-existing `napi_callback_scope` or `Napi::CallbackScope`.

```cpp
Napi::CallbackScope::CallbackScope(napi_env env, napi_async_context context);
```

- `[in] async_context`: The pre-existing `napi_async_context` or `Napi::AsyncContext`.

### Destructor

```cpp
virtual Napi::CallbackScope::~CallbackScope();
```

## Operator

```cpp
Napi::CallbackScope::operator napi_callback_scope() const;
```

Returns the Node-API `napi_callback_scope` wrapped by the `Napi::CallbackScope`
object. This can be used to mix usage of the C Node-API and node-addon-api.
