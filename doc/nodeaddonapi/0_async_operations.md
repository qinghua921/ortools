# Asynchronous operations

耗时操作需要防止阻塞 **event loop** 线程, 需要放在其他线程运行.

- **[`Napi::AsyncWorker`](async_worker.md)**
- **[AsyncContext](async_context.md)**
- **[CallbackScope](callback_scope.md)**
