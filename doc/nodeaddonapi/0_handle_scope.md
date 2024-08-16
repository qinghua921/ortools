# HandleScope

创建生命周期范围.

## Methods

### Constructor

```cpp
Napi::HandleScope::HandleScope(Napi::Env env);
```

```cpp
Napi::HandleScope::HandleScope(Napi::Env env, Napi::HandleScope scope);
```

- `[in] env`: `Napi::Env` in which the scope passed in was created.
- `[in] scope`: 被包装的 `Napi::HandleScope`.

This can be used to mix usage of the C Node-API and node-addon-api.

```cpp
operator Napi::HandleScope::napi_handle_scope() const
```

This can be used to mix usage of the C Node-API and node-addon-api.

### Destructor

```cpp
Napi::HandleScope::~HandleScope();
```

回收管理的 objects/handles.

## Example

```cpp
for (int i = 0; i < LOOP_MAX; i++) {
  Napi::HandleScope scope(info.Env());
  std::string name = std::string("inner-scope") + std::to_string(i);
  Napi::Value newValue = Napi::String::New(info.Env(), name.c_str());
  // do something with newValue
};
```

详见 [Object lifetime
management](object_lifetime_management.md).
