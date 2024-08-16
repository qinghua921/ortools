# Name

Names 对应 JavaScript 的可以作为属性名称的值.
两种特殊的 Name: [`Napi::String`](string.md), [`Napi::Symbol`](symbol.md).

## Methods

### Constructor

```cpp
Napi::Name::Name();
```

```cpp
Napi::Name::Name(napi_env env, napi_value value);
```

- `[in] env` - The environment in which to create the array.
- `[in] value` - The primitive to wrap.

Returns a `Napi::Name` created from the JavaScript primitive.

[`Napi::Value`]: ./value.md
