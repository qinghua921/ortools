# ArrayBuffer

对应
[JavaScript `ArrayBuffer`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ArrayBuffer).

## Methods

### New

```cpp
static Napi::ArrayBuffer Napi::ArrayBuffer::New(napi_env env, size_t byteLength);
```

> When `NODE_API_NO_EXTERNAL_BUFFERS_ALLOWED` is defined, this method is not available.
> See [External Buffer][] for more information.

包装 external data 为 `Napi::ArrayBuffer`.

```cpp
static Napi::ArrayBuffer Napi::ArrayBuffer::New(napi_env env, void* externalData, size_t byteLength);
```

```cpp
template <typename Finalizer>
static Napi::ArrayBuffer Napi::ArrayBuffer::New(napi_env env,
                       void* externalData,
                       size_t byteLength,
                       Finalizer finalizeCallback);
```

- `[in] finalizeCallback`: A function to be called when the `Napi::ArrayBuffer` is
  destroyed. It must implement `operator()`, accept an Napi::Env, a `void*` (which is the
  `externalData` pointer), and return `void`.

```cpp
template <typename Finalizer, typename Hint>
static Napi::ArrayBuffer Napi::ArrayBuffer::New(napi_env env,
                       void* externalData,
                       size_t byteLength,
                       Finalizer finalizeCallback,
                       Hint* finalizeHint);
```

- `[in] finalizeHint`: The hint to be passed as the second parameter of the
  finalize callback.

### Constructor

```cpp
Napi::ArrayBuffer::ArrayBuffer();
```

```cpp
Napi::ArrayBuffer::ArrayBuffer(napi_env env, napi_value value);
```

- `[in] value`: The `Napi::ArrayBuffer` reference to wrap.

### ByteLength

```cpp
size_t Napi::ArrayBuffer::ByteLength() const;
```

### Data

```cpp
void* Napi::ArrayBuffer::Data() const;
```

Returns a pointer the wrapped data.

### Detach

```cpp
void Napi::ArrayBuffer::Detach();
```

### IsDetached

```cpp
bool Napi::ArrayBuffer::IsDetached() const;
```

Returns `true` if this `ArrayBuffer` has been detached.

[`Napi::Object`]: ./object.md
[External Buffer]: ./external_buffer.md
