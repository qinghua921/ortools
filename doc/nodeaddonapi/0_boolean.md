# Boolean

## Methods

### Constructor

```cpp
Napi::Boolean::Boolean();
```

```cpp
Napi::Boolean(napi_env env, napi_value value);
```

- `[in] value`: The `napi_value` which is a handle for a JavaScript `Boolean`.

### New

```cpp
Napi::Boolean Napi::Boolean::New(napi_env env, bool value);
```

### Value

```cpp
bool Napi::Boolean::Value() const;
```

## Operators

### operator bool

```cpp
Napi::Boolean::operator bool() const;
```

[`Napi::Value`]: ./value.md
