# Buffer

## Methods

### New

```cpp
static Napi::Buffer<T> Napi::Buffer::New(napi_env env, size_t length);
```

- `[in] length`: The number of `T` elements to allocate.

> When `NODE_API_NO_EXTERNAL_BUFFERS_ALLOWED` is defined, this method is not available.
> See [External Buffer][] for more information.

```cpp
static Napi::Buffer<T> Napi::Buffer::New(napi_env env, T* data, size_t length);
```

- `[in] data`: The pointer to the external data to expose.
- `[in] length`: The number of `T` elements in the external data.

```cpp
template <typename Finalizer>
static Napi::Buffer<T> Napi::Buffer::New(napi_env env,
                     T* data,
                     size_t length,
                     Finalizer finalizeCallback);
```

- `[in] finalizeCallback`: The function to be called when the `Napi::Buffer` is
  destroyed. It must implement `operator()`, accept an Napi::Env, a `T*` (which is the
  external data pointer), and return `void`.

```cpp
template <typename Finalizer, typename Hint>
static Napi::Buffer<T> Napi::Buffer::New(napi_env env,
                     T* data,
                     size_t length,
                     Finalizer finalizeCallback,
                     Hint* finalizeHint);
```

- `[in] finalizeHint`: The hint to be passed as the second parameter of the
  finalize callback.

### NewOrCopy

When the
[external buffer][] is not supported, allocates a new `Napi::Buffer` object and
copies the provided external data into it.

```cpp
static Napi::Buffer<T> Napi::Buffer::NewOrCopy(napi_env env, T* data, size_t length);
```

- `[in] env`: The environment in which to create the `Napi::Buffer` object.
- `[in] data`: The pointer to the external data to expose.
- `[in] length`: The number of `T` elements in the external data.

```cpp
template <typename Finalizer>
static Napi::Buffer<T> Napi::Buffer::NewOrCopy(
  napi_env env,
  T* data,
  size_t length,
  Finalizer finalizeCallback);
```

```cpp
template <typename Finalizer, typename Hint>
static Napi::Buffer<T> Napi::Buffer::NewOrCopy(
  napi_env env,
  T* data,
  size_t length,
  Finalizer finalizeCallback,
  Hint* finalizeHint);
```

- `[in] finalizeHint`: The hint to be passed as the second parameter of the
  finalize callback.

### Copy

Allocates a new `Napi::Buffer` object and copies the provided external data into it.

```cpp
static Napi::Buffer<T> Napi::Buffer::Copy(napi_env env, const T* data, size_t length);
```

### Constructor

```cpp
Napi::Buffer::Buffer();
```

```cpp
Napi::Buffer::Buffer(napi_env env, napi_value value);
```

- `[in] env`: The environment in which to create the `Napi::Buffer` object.
- `[in] value`: The Uint8Array reference to wrap.

### Data

```cpp
T* Napi::Buffer::Data() const;
```

### Length

```cpp
size_t Napi::Buffer::Length() const;
```

[`Napi::Uint8Array`]: ./typed_array_of.md
[External Buffer]: ./external_buffer.md
