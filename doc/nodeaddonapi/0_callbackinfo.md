# CallbackInfo

对应 JavaScript request.

## Methods

### NewTarget

```cpp
Napi::Value Napi::CallbackInfo::NewTarget() const;
```

Returns the `new.target` value of the constructor call. If the function that was invoked (and for which the `Napi::NCallbackInfo` was passed) is not a constructor call, a call to `IsEmpty()` on the returned value returns true.

### IsConstructCall

```cpp
bool Napi::CallbackInfo::IsConstructCall() const;
```

Returns a `bool` indicating if the function that was invoked (and for which the `Napi::CallbackInfo` was passed) is a constructor call.

### This

```cpp
Napi::Value Napi::CallbackInfo::This() const;
```

获取调用时的 JavaScript `this` value

### Data

```cpp
void* Napi::CallbackInfo::Data() const;
```

Returns the data pointer for the callback.

### SetData

```cpp
void Napi::CallbackInfo::SetData(void* data);
```

- `[in] data`: The new data pointer to associate with this `Napi::CallbackInfo` object.

### Not documented here

```cpp
Napi::CallbackInfo::~CallbackInfo();
// Disallow copying to prevent multiple free of _dynamicArgs
Napi::CallbackInfo::CallbackInfo(CallbackInfo const &) = delete;
void Napi::CallbackInfo::operator=(CallbackInfo const &) = delete;
```
