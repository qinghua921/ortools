# FunctionReference

等于 `Napi::Reference<Napi::Function>`.

## Methods

### Weak

Creates a "weak" reference to the value, in that the initial reference count is
set to 0.

```cpp
static Napi::FunctionReference Napi::Weak(const Napi::Function& value);
```

- `[in] value`: The value which is to be referenced.

### Persistent

Creates a "persistent" reference to the value, in that the initial reference
count is set to 1.

```cpp
static Napi::FunctionReference Napi::Persistent(const Napi::Function& value);
```

- `[in] value`: The value which is to be referenced.

### Constructor

Creates a new empty instance of `Napi::FunctionReference`.

```cpp
Napi::FunctionReference::FunctionReference();
```

```cpp
Napi::FunctionReference::FunctionReference(napi_env env, napi_ref ref);
```

- `[in] ref`: The Node-API reference to be held by the `Napi::FunctionReference`.

Returns a newly created `Napi::FunctionReference` object.

### New

Constructs a new instance by calling the constructor held by this reference.

```cpp
Napi::Object Napi::FunctionReference::New(const std::initializer_list<napi_value>& args) const;
```

- `[in] args`: Initializer list of JavaScript values as `napi_value` representing
  the arguments of the constructor function.

```cpp
Napi::Object Napi::FunctionReference::New(const std::vector<napi_value>& args) const;
```

- `[in] args`: Vector of JavaScript values as `napi_value` representing the
  arguments of the constructor function.

Returns a new JavaScript object.

### Call

Calls a referenced Javascript function from a native add-on.

```cpp
Napi::Value Napi::FunctionReference::Call(const std::initializer_list<napi_value>& args) const;
```

- `[in] args`: Initializer list of JavaScript values as `napi_value` representing
  the arguments of the referenced function.

```cpp
Napi::Value Napi::FunctionReference::Call(const std::vector<napi_value>& args) const;
```

- `[in] args`: Vector of JavaScript values as `napi_value` representing the
  arguments of the referenced function.

```cpp
Napi::Value Napi::FunctionReference::Call(napi_value recv, const std::initializer_list<napi_value>& args) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] args`: Initializer list of JavaScript values as `napi_value` representing
  the arguments of the referenced function.

```cpp
Napi::Value Napi::FunctionReference::Call(napi_value recv, const std::vector<napi_value>& args) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] args`: Vector of JavaScript values as `napi_value` representing the
  arguments of the referenced function.

```cpp
Napi::Value Napi::FunctionReference::Call(napi_value recv, size_t argc, const napi_value* args) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] argc`: The number of arguments passed to the referenced function.
- `[in] args`: Array of JavaScript values as `napi_value` representing the
  arguments of the referenced function.

Returns a `Napi::Value` representing the JavaScript object returned by the referenced
function.

### MakeCallback

Calls a referenced JavaScript function from a native add-on after an asynchronous
operation.

```cpp
Napi::Value Napi::FunctionReference::MakeCallback(napi_value recv, const std::initializer_list<napi_value>& args, napi_async_context = nullptr) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] args`: Initializer list of JavaScript values as `napi_value` representing
  the arguments of the referenced function.
- `[in] context`: Context for the async operation that is invoking the callback.
  This should normally be a value previously obtained from [Napi::AsyncContext](async_context.md).
  However `nullptr` is also allowed, which indicates the current async context
  (if any) is to be used for the callback.

Returns a `Napi::Value` representing the JavaScript object returned by the referenced
function.

### MakeCallback

Calls a referenced JavaScript function from a native add-on after an asynchronous
operation.

```cpp
Napi::Value Napi::FunctionReference::MakeCallback(napi_value recv, const std::vector<napi_value>& args, napi_async_context context = nullptr) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] args`: Vector of JavaScript values as `napi_value` representing the
  arguments of the referenced function.
- `[in] context`: Context for the async operation that is invoking the callback.
  This should normally be a value previously obtained from [Napi::AsyncContext](async_context.md).
  However `nullptr` is also allowed, which indicates the current async context
  (if any) is to be used for the callback.

Returns a `Napi::Value` representing the JavaScript object returned by the referenced
function.

### MakeCallback

Calls a referenced JavaScript function from a native add-on after an asynchronous
operation.

```cpp
Napi::Value Napi::FunctionReference::MakeCallback(napi_value recv, size_t argc, const napi_value* args, napi_async_context context = nullptr) const;
```

- `[in] recv`: The `this` object passed to the referenced function when it's called.
- `[in] argc`: The number of arguments passed to the referenced function.
- `[in] args`: Array of JavaScript values as `napi_value` representing the
  arguments of the referenced function.
- `[in] context`: Context for the async operation that is invoking the callback.
  This should normally be a value previously obtained from [Napi::AsyncContext](async_context.md).
  However `nullptr` is also allowed, which indicates the current async context
  (if any) is to be used for the callback.

Returns a `Napi::Value` representing the JavaScript object returned by the referenced
function.

## Operator

```cpp
Napi::Value operator ()(const std::initializer_list<napi_value>& args) const;
```

- `[in] args`: Initializer list of reference to JavaScript values as `napi_value`

Returns a `Napi::Value` representing the JavaScript value returned by the referenced
function.
