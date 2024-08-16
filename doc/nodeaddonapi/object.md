# Object

对应 JavaScript 对象. 有如下子类:

- [`Napi::Array`](array.md)
- [`Napi::ArrayBuffer`](array_buffer.md)
- [`Napi::Buffer<T>`](buffer.md)
- [`Napi::Function`](function.md)
- [`Napi::TypedArray`](typed_array.md).

## Methods

### Constructor

```cpp
Napi::Object::Object();
```

创建空对象

```cpp
Napi::Object::Object(napi_env env, napi_value value);
```

### New()

```cpp
Napi::Object Napi::Object::New(napi_env env);
```

### Set()

```cpp
bool Napi::Object::Set (____ key, ____ value) const;
```

The key can be any of the following types:

- `napi_value`
- [`Napi::Value`](value.md)
- `const char*`
- `const std::string&`
- `uint32_t`

The `value` can be of any type that is accepted by [`Napi::Value::From`][].

### Delete()

```cpp
bool Napi::Object::Delete(____ key) const;
```

Returns `true` if the property was deleted.

The `key` can be any of the following types:

- `napi_value`
- [`Napi::Value`](value.md)
- `const char *`
- `const std::string &`
- `uint32_t`

### Get()

```cpp
Napi::Value Napi::Object::Get(____ key);
```

Returns the value _undefined_ if the key does not exist.

The `key` can be any of the following types:

- `napi_value`
- [`Napi::Value`](value.md)
- `const char *`
- `const std::string &`
- `uint32_t`

### InstanceOf()

```cpp
bool Napi::Object::InstanceOf (const Function& constructor) const
```

Note: This is equivalent to the JavaScript instanceof operator.

### AddFinalizer()

```cpp
template <typename Finalizer, typename T>
inline void AddFinalizer(Finalizer finalizeCallback, T* data) const;
```

- `[in] finalizeCallback`: 垃圾回收时的回调函数.
- `[in] data`: 回收的数据.

```cpp
template <typename Finalizer, typename T, typename Hint>
inline void AddFinalizer(Finalizer finalizeCallback,
                         T* data,
                         Hint* finalizeHint) const;
```

### GetPropertyNames()

```cpp
Napi::Array Napi::Object::GetPropertyNames() const;
```

返回 [`Napi::Array`](array.md) of strings.
`Symbol` 类型的 key 不返回.

### DefineProperties()

```cpp
bool Napi::Object::DefineProperties (____ properties) const;
```

- `[in] properties`: A list of [`Napi::PropertyDescriptor`](property_descriptor.md). Can be one of the following types:
  - const std::initializer_list<Napi::PropertyDescriptor>&
  - const std::vector<Napi::PropertyDescriptor>&

### Freeze()

```cpp
void Napi::Object::Freeze() const;
```

`Freeze()` 后不能做任何改变.

### Seal()

```cpp
void Napi::Object::Seal() const;
```

`Seal()` 属性不能该表, 属性值可以.

### operator\[\]()

```cpp
Napi::PropertyLValue<std::string> Napi::Object::operator[] (const char* utf8name) const;
```

使用中括号获取或者设置属性数值

## Iterator

只有在启用了 C++ 异常后, 才能使用. (`NAPI_CPP_EXCEPTIONS`).

### Constant Iterator

不可改变遍历的数值

#### Example

```cpp
Value Sum(const CallbackInfo& info) {
  Object object = info[0].As<Object>();
  int64_t sum = 0;

  for (const auto& e : object) {
    sum += static_cast<Value>(e.second).As<Number>().Int64Value();
  }

  return Number::New(info.Env(), sum);
}
```

### Non Constant Iterator

可改变遍历的数值

#### Example

```cpp
void Increment(const CallbackInfo& info) {
  Env env = info.Env();
  Object object = info[0].As<Object>();

  for (auto e : object) {
    int64_t value = static_cast<Value>(e.second).As<Number>().Int64Value();
    ++value;
    e.second = Napi::Number::New(env, value);
  }
}
```

[`Napi::TypeTaggable`]: ./type_taggable.md
[`Napi::Value::From`]: ./value.md#from
