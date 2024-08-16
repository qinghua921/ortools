# Array

对应 JavaScript Arrays.

## Constructor

```cpp
Napi::Array::Array();
```

Returns an empty array.

异常时抛出 `Napi::Error`. 禁用 C++ exceptions 时, 调用者需要用 `Env::IsExceptionPending`.

```cpp
Napi::Array::Array(napi_env env, napi_value value);
```

- `[in] env` - The environment in which to create the array.
- `[in] value` - The primitive to wrap.

## Methods

### New

```cpp
static Napi::Array Napi::Array::New(napi_env env);
```

```cpp
static Napi::Array Napi::Array::New(napi_env env, size_t length);
```

### Length

```cpp
uint32_t Napi::Array::Length() const;
```

[`Napi::ArrayBuffer`]: ./array_buffer.md
[`Napi::Int32Array`]: ./typed_array_of.md
[`Napi::Object`]: ./object.md
[`Napi::TypedArray`]: ./typed_array.md
