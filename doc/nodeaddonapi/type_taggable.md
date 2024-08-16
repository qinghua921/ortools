# TypeTaggable

继承 [`Napi::Value`][].

### TypeTag()

```cpp
void Napi::TypeTaggable::TypeTag(const napi_type_tag* type_tag) const;
```

- `[in] type_tag`: 要标记的类型.

标记类型

### CheckTypeTag()

```cpp
bool Napi::TypeTaggable::CheckTypeTag(const napi_type_tag* type_tag) const;
```

检查类型

[`Napi::Value`]: ./value.md
[`Napi::Object`]: ./object.md
[`Napi::External`]: ./external.md
