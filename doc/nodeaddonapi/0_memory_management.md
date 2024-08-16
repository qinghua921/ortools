# MemoryManagement

The `Napi::MemoryManagement` class contains functions that give the JavaScript engine
an indication of the amount of externally allocated memory that is kept alive by
JavaScript objects.

## Methods

### AdjustExternalMemory

```cpp
static int64_t Napi::MemoryManagement::AdjustExternalMemory(Napi::Env env, int64_t change_in_bytes);
```

- `[in] env`: The environment in which the API is invoked under.
- `[in] change_in_bytes`: The change in externally allocated memory that is kept
  alive by JavaScript objects expressed in bytes.

Returns the adjusted memory value.
