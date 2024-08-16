# Date

## Methods

### ValueOf

```cpp
double Napi::Date::ValueOf() const;
```

从 1 January 1970 00:00:00 UTC 的毫秒数.

## Operators

### Example

```cpp
double operatorVal = Napi::Date::New(Env(), 0); // Napi::Date to double
// or
auto instanceVal = info[0].As<Napi::Date>().ValueOf();
```
