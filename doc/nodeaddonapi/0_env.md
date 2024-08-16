# Env

## Methods

### Global

```cpp
Napi::Object Napi::Env::Global() const;
```

返回 `Napi::Object`( 对应 JavaScript Global Object ).

### Undefined

```cpp
Napi::Value Napi::Env::Undefined() const;
```

返回全局的 JavaScript Undefined Object.

### Null

```cpp
Napi::Value Napi::Env::Null() const;
```

返回全局的 JavaScript Null Object.

### IsExceptionPending

```cpp
bool Napi::Env::IsExceptionPending() const;
```

是否有挂起异常

### GetAndClearPendingException

```cpp
Napi::Error Napi::Env::GetAndClearPendingException() const;
```

获取挂起异常

### RunScript

```cpp
Napi::Value Napi::Env::RunScript(____ script) const;
```

- `[in] script`: 要执行的 JS 脚本

### GetInstanceData

```cpp
template <typename T> T* GetInstanceData() const;
```

获取实例数据, 没有返回 `nullptr`

### SetInstanceData

```cpp
template <typename T> using Finalizer = void (*)(Env, T*);
template <typename T, Finalizer<T> fini = Env::DefaultFini<T>>
void SetInstanceData(T* data) const;
```

- `[template] fini`: A function to call when the instance data is to be deleted.
  Accepts a function of the form `void CleanupData(Napi::Env env, T* data)`. If
  not given, the default finalizer will be used, which simply uses the `delete`
  operator to destroy `T*` when the addon instance is unloaded.
- `[in] data`: A pointer to data that will be associated with the instance of
  the addon for the duration of its lifecycle.

```cpp
template <typename DataType, typename HintType>
using FinalizerWithHint = void (*)(Env, DataType*, HintType*);
template <typename DataType,
          typename HintType,
          FinalizerWithHint<DataType, HintType> fini =
            Env::DefaultFiniWithHint<DataType, HintType>>
void SetInstanceData(DataType* data, HintType* hint) const;
```

- `[in] hint`: A pointer to data that will be associated with the instance of
  the addon for the duration of its lifecycle and will be passed as a hint to
  `fini` when the addon instance is unloaded.

### AddCleanupHook

```cpp
template <typename Hook>
CleanupHook<Hook> AddCleanupHook(Hook hook);
```

- `[in] hook`: A function to call when the environment exits. Accepts a
  function of the form `void ()`.

Registers `hook` as a function to be run once the current Node.js environment
exits. Unlike the underlying C-based Node-API, providing the same `hook`
multiple times **is** allowed. The hooks will be called in **reverse** order, i.e.
the most recently added one will be called first.

Returns an `Env::CleanupHook` object, which can be used to remove the hook via
its `Remove()` method.

```cpp
template <typename Hook, typename Arg>
CleanupHook<Hook, Arg> AddCleanupHook(Hook hook, Arg* arg);
```

- `[in] hook`: A function to call when the environment exits. Accepts a
  function of the form `void (Arg* arg)`.
- `[in] arg`: A pointer to data that will be passed as the argument to `hook`.

# Env::CleanupHook

## Methods

### IsEmpty

```cpp
bool IsEmpty();
```

Returns `true` if the cleanup hook was **not** successfully registered.

### Remove

```cpp
bool Remove(Env env);
```

Unregisters the hook from running once the current Node.js environment exits.

Returns `true` if the hook was successfully removed from the Node.js
environment.
