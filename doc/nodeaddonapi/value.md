# Value

`Napi::Value` 对应 JS 侧的 unknown 类型.

## Constructors

### Constructor

```cpp
Napi::Value::Value();
```

```cpp
Napi::Value::Value(napi_env env, napi_value value);
```

- `[in] env`: 所在环境
- `[in] value`: 数值, 可以为如下类型:
  - `bool`
  - Any integer type
  - Any floating point type
  - `const char*` (encoded using UTF-8, null-terminated)
  - `const char16_t*` (encoded using UTF-16-LE, null-terminated)
  - `std::string` (encoded using UTF-8)
  - `std::u16string`
  - `Napi::Value`
  - `napi_value`

## Operators

### operator napi_value

```cpp
Napi::Value::operator napi_value() const;
```

返回 `napi_value`. 空值时, 为 `nullptr`.

## Methods

### As

```cpp
template <typename T> T Napi::Value::As() const;
```

转换失败抛出 `Napi::Error`. 可以使用 `Napi::Value::Is*()` 判断类型, 可以使用`NODE_ADDON_API_ENABLE_TYPE_CHECK_ON_AS` 强制类型检查.

### From

```cpp
template <typename T>
static Napi::Value Napi::Value::From(napi_env env, const T& value);
```

- `[in] env`: 在哪个环境中创建?.
- `[in] value`: 初始值.

转换 C++ 数据 为 JS 数据.
C++ 数据可以为以下类型

- `bool` - returns a `Napi::Boolean`.
- Any integer type - returns a `Napi::Number`.
- Any floating point type - returns a `Napi::Number`.
- `const char*` (encoded using UTF-8, null-terminated) - returns a
  `Napi::String`.
- `const char16_t*` (encoded using UTF-16-LE, null-terminated) - returns a
  `Napi::String`.
- `std::string` (encoded using UTF-8) - returns a `Napi::String`.
- `std::u16string` - returns a `Napi::String`.
- `Napi::Value` - returns a `Napi::Value`.
- `Napi_value` - returns a `Napi::Value`.

### IsArray

```cpp
bool Napi::Value::IsArray() const;
```

判断为 JavaScript `Napi::Array`

### IsEmpty

```cpp
bool Napi::Value::IsEmpty() const;
```

empty `Napi::Value` 不同于 JavaScript `null` or `undefined`, 后者为 valid 数据.

禁用 C++ 时, 方法可能返回 empty `Napi::Value` 以表示异常. 调用者使用前需要使用
`Env::IsExceptionPending` 检查数据.

### ToBoolean

```cpp
Napi::Boolean Napi::Value::ToBoolean() const;
```

转化失败抛出异常, 如果禁用 C++ 异常需要使用 `Env::IsExceptionPending` 检查返回数据.

### Type

```cpp
napi_valuetype Napi::Value::Type() const;
```

Returns the `napi_valuetype` type of the `Napi::Value`.

[`Napi::Boolean`]: ./boolean.md
[`Napi::BigInt`]: ./bigint.md
[`Napi::Date`]: ./date.md
[`Napi::External`]: ./external.md
[`Napi::Name`]: ./name.md
[`Napi::Number`]: ./number.md
[`Napi::Object`]: ./object.md
