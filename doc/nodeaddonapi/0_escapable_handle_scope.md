# EscapableHandleScope

The `Napi::EscapableHandleScope` is a special type of `Napi::HandleScope`
which allows a single handle to be "promoted" to an outer scope.

## Methods

### Constructor


```cpp
Napi::EscapableHandleScope Napi::EscapableHandleScope::New(Napi::Env env);
```


```cpp
Napi::EscapableHandleScope Napi::EscapableHandleScope::New(napi_env env, napi_handle_scope scope);
```


Returns a new `Napi::EscapableHandleScope` instance which wraps the
`napi_escapable_handle_scope` handle passed in. This can be used
to mix usage of the C Node-API and node-addon-api.

```cpp
operator Napi::EscapableHandleScope::napi_escapable_handle_scope() const
```

Returns the Node-API `napi_escapable_handle_scope` wrapped by the `Napi::EscapableHandleScope` object.
This can be used to mix usage of the C Node-API and node-addon-api by allowing
the class to be used be converted to a `napi_escapable_handle_scope`.

### Destructor

```cpp
Napi::EscapableHandleScope::~EscapableHandleScope();
```

Deletes the `Napi::EscapableHandleScope` instance and allows any objects/handles created
in the scope to be collected by the garbage collector. There is no
guarantee as to when the garbage collector will do this.

### Escape

```cpp
napi::Value Napi::EscapableHandleScope::Escape(napi_value escapee);
```

- `[in] escapee`: `Napi::Value` or `napi_env` to promote to the outer scope

Returns `Napi::Value` which can be used in the outer scope. This method can
be called at most once on a given `Napi::EscapableHandleScope`. If it is called
more than once an exception will be thrown.

