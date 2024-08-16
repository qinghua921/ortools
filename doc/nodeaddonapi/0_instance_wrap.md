# InstanceWrap<T>


为 [`Napi::Addon<T>`][] 时, 负责把方法暴露给 JS.

为 [`Napi::ObjectWrap<T>`][] 时, 负责暴露 JS 实例方法, 该 JS 实例对应 [`Napi::ObjectWrap<T>`][] 的子类

## 方法

### InstanceMethod

定义 JS 实例方法

```cpp
template <typename T>
static Napi::ClassPropertyDescriptor<T>
Napi::InstanceWrap<T>::InstanceMethod(const char* utf8name,
                             InstanceVoidMethodCallback method,
                             napi_property_attributes attributes = napi_default,
                             void* data = nullptr);
```

```cpp
<template typename T>
template <typename InstanceWrap<T>::InstanceVoidMethodCallback method>
static Napi::ClassPropertyDescriptor<T>
Napi::InstanceWrap::InstanceMethod(const char* utf8name,
                             napi_property_attributes attributes = napi_default,
                             void* data = nullptr);
```

- `[in] utf8name`: 方法名称.
- `[in] method`: 要暴露的 C++ 方法.
- `[in] attributes`: 方法属性( `napi_property_attributes` 联合 ).
- `[in] data`: 调用时, C++ 侧要传入的参数.

返回 `Napi::ClassPropertyDescriptor<T>` . 暴露的 C++ 方法格式如下

```cpp
void MethodName(const Napi::CallbackInfo& info);
```

```cpp
Napi::Value MethodName(const Napi::CallbackInfo& info);
```

### InstanceAccessor

定义 JS 实例 get, set 属性

```cpp
template <typename T>
static Napi::ClassPropertyDescriptor<T>
Napi::InstanceWrap<T>::InstanceAccessor(const char* utf8name,
                             InstanceGetterCallback getter,
                             InstanceSetterCallback setter,
                             napi_property_attributes attributes = napi_default,
                             void* data = nullptr);
```

```cpp
template <typename T>
template <typename InstanceWrap<T>::InstanceGetterCallback getter,
          typename InstanceWrap<T>::InstanceSetterCallback setter=nullptr>
static Napi::ClassPropertyDescriptor<T>
Napi::InstanceWrap<T>::InstanceAccessor(const char* utf8name,
                             napi_property_attributes attributes = napi_default,
                             void* data = nullptr);
```

- `[in] utf8name`: 属性名称
- `[in] getter`: 对应的 C++ 侧的 get 方法
- `[in] setter`: 对应的 C++ 侧的 set 方法
- `[in] attributes`: 属性的属性( napi_property_attributes 联合 ).
- `[in] data`: get, set 时, C++ 侧要传入的参数.

返回 `Napi::ClassPropertyDescriptor<T>`.

### InstanceValue

定义 JS 实例属性

```cpp
template <typename T>
static Napi::ClassPropertyDescriptor<T>
Napi::InstanceWrap<T>::InstanceValue(const char* utf8name,
                            Napi::Value value,
                            napi_property_attributes attributes = napi_default);
```

- `[in] utf8name`: 属性名称
- `[in] value`: 属性数值
- `[in] attributes`: 属性的属性( `napi_property_attributes` 联合 ).

返回 `Napi::ClassPropertyDescriptor<T>`.

[`Napi::Addon<T>`]: ./addon.md
[`Napi::ObjectWrap<T>`]: ./object_wrap.md
