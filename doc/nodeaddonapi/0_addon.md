# Add-on Structure

使用静态变量存放全局数据不安全, 没有考虑多次加载.

## Example

```cpp
#include <napi.h>

class ExampleAddon : public Napi::Addon<ExampleAddon>
{
 public:
  ExampleAddon(Napi::Env env, Napi::Object exports)
  {
    DefineAddon(exports,
    {
      InstanceMethod("increment", &ExampleAddon::Increment),
      InstanceValue("subObject",
      DefineProperties(Napi::Object::New(env),
      {
        InstanceMethod("decrement", &ExampleAddon::Decrement)
      }), napi_enumerable)
    });
  }

 private:
  Napi::Value Increment(const Napi::CallbackInfo& info)
  {
    return Napi::Number::New(info.Env(), ++value);
  }

  Napi::Value Decrement(const Napi::CallbackInfo& info)
  {
    return Napi::Number::New(info.Env(), --value);
  }

  // 每个 add-on 有自己的 value.
  uint32_t value = 42;
};

// 必须使用此宏声明
NODE_API_ADDON(ExampleAddon)
```

```js
"use strict";

const exampleAddon = require("bindings")("example_addon");
console.log(exampleAddon.increment()); // prints 43
console.log(exampleAddon.increment()); // prints 44
console.log(exampleAddon.subObject.decrement()); // prints 43
```

Node 每次加载 addon 会创建一个新的实例.

**Note:** `Napi::Addon<T>` 内部使用 `Napi::Env::SetInstanceData()`. 应该使用 `Napi::Env::GetInstanceData` 获取 `Napi::Addon<T>` 的实例. 使用 `Napi::Addon<T>` 的属性存放全局变量.

## Methods

### Constructor

```cpp
Napi::Addon(Napi::Env env, Napi::Object exports);
```

- `[in] exports`: The exports object received from JavaScript.

### DefineAddon

```cpp
template <typename T>
void Napi::Addon<T>::DefineAddon(Napi::Object exports,
                   const std::initializer_list<PropertyDescriptor>& properties);
```

### DefineProperties

```cpp
template <typename T>
Napi::Object
Napi::Addon<T>::DefineProperties(Napi::Object object,
                   const std::initializer_list<PropertyDescriptor>& properties);
```

[`Napi::InstanceWrap<T>`]: ./instance_wrap.md
