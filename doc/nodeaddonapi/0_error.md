# Error

The `Napi::Error` class is a persistent reference to a JavaScript error object thus
inherits its behavior from the `Napi::ObjectReference` class (for more info see: [`Napi::ObjectReference`](object_reference.md)).

If C++ exceptions are enabled (for more info see: [Setup](setup.md)), then the
`Napi::Error` class extends `std::exception` and enables integrated
error-handling for C++ exceptions and JavaScript exceptions.

For more details about error handling refer to the section titled [Error handling](error_handling.md).

## Methods

### New

```cpp
Napi::Error::New(Napi::Env env);
```

```cpp
Napi::Error::New(Napi::Env env, const char* message);
```

```cpp
Napi::Error::New(Napi::Env env, const std::string& message);
```

### Fatal

In case of an unrecoverable error in a native module, a fatal error can be thrown
to immediately terminate the process.

```cpp
static NAPI_NO_RETURN void Napi::Error::Fatal(const char* location, const char* message);
```

The function call does not return, the process will be terminated.

### Constructor

```cpp
Napi::Error::Error();
```

```cpp
Napi::Error::Error(napi_env env, napi_value value);
```

### Message

```cpp
std::string& Napi::Error::Message() const NAPI_NOEXCEPT;
```

### ThrowAsJavaScriptException

Throw the error as JavaScript exception.

```cpp
void Napi::Error::ThrowAsJavaScriptException() const;
```

### what

```cpp
const char* Napi::Error::what() const NAPI_NOEXCEPT override;
```

Returns a pointer to a null-terminated string that is used to identify the
exception. This method can be used only if the exception mechanism is enabled.

[`Napi::ObjectReference`]: ./object_reference.md
[`std::exception`]: https://cplusplus.com/reference/exception/exception/
