# Setup

## Installation and usage

略

3. 决定是否启用 C++ 异常:

禁用 C++ 异常使用宏:

```gyp
  'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
```

启用 C++ 异常应使用宏:

```gyp
  'defines': [ 'NODE_ADDON_API_ENABLE_MAYBE' ],
```

5. 不要使用 `node.h`, `nan.h`, or `v8.h`. 使用 `napi.h`

`NODE_ADDON_API_DISABLE_DEPRECATED` 可以禁用 `napi.h` 中的 deprecated APIs.

默认情况下, 在一个正在终止的环境 (workerthreads) 中抛出异常会终止 Node 进程. 这是一种运行时异常, 需要避免.
如果需要防止进程终止, 可以使用宏 `NODE_API_SWALLOW_UNTHROWABLE_EXCEPTIONS`.
