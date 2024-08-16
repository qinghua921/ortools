# BigInt

## Methods

### New

```cpp
static Napi::BigInt Napi::BigInt::New(Napi::Env env, int64_t value);
static Napi::BigInt Napi::BigInt::New(Napi::Env env, uint64_t value);
```

```cpp
static Napi::BigInt Napi::BigInt::New(Napi::Env env,
                  int sign_bit,
                  size_t word_count,
                  const uint64_t* words);
```

- `[in] sign_bit`: Determines if the resulting `BigInt` will be positive or negative.
- `[in] word_count`: The length of the words array.
- `[in] words`: An array of `uint64_t` little-endian 64-bit words.

This API converts an array of unsigned 64-bit words into a single `BigInt`
value.

The resulting `BigInt` is calculated as: (–1)<sup>`sign_bit`</sup> (`words[0]`
× (2<sup>64</sup>)<sup>0</sup> + `words[1]` × (2<sup>64</sup>)<sup>1</sup> + …)

Returns a new JavaScript `BigInt`.

### Constructor

```cpp
Napi::BigInt();
```

### Int64Value

```cpp
int64_t Napi::BigInt::Int64Value(bool* lossless) const;
```

- `[out] lossless`: 没有精度损失

### Uint64Value

```cpp
uint64_t Napi::BigInt::Uint64Value(bool* lossless) const;
```

### WordCount

```cpp
size_t Napi::BigInt::WordCount() const;
```

Returns the number of words needed to store this `BigInt` value.

### ToWords

```cpp
void Napi::BigInt::ToWords(int* sign_bit, size_t* word_count, uint64_t* words);
```

- `[out] sign_bit`: Integer representing if the JavaScript `BigInt` is positive
  or negative.
- `[in/out] word_count`: Must be initialized to the length of the words array.
  Upon return, it will be set to the actual number of words that would be
  needed to store this `BigInt`.
- `[out] words`: Pointer to a pre-allocated 64-bit word array.

Returns a single `BigInt` value into a sign bit, 64-bit little-endian array,
and the number of elements in the array.

[`Napi::Value`]: ./value.md
