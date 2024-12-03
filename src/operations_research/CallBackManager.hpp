#include <map>
#include <napi.h>

namespace operations_research
{

class CallBackManager
{
  public:
    CallBackManager()
    {
    }
    ~CallBackManager()
    {
        for (auto it = callbackMap.begin(); it != callbackMap.end(); ++it)
        {
            clean(it->first);
        }
    }
    std::map<Napi::Env, Napi::FunctionReference> callbackMap;
    void insert(Napi::Env env, Napi::Function callback)
    {
        clean(env);
        callbackMap[env] = Napi::Persistent(callback);
        env.AddCleanupHook(
            [this, env]()
            { clean(env); }
        );
    }
    Napi::MaybeOrValue<Napi::Value> call(Napi::Env env, const std::initializer_list<napi_value> &args)
    {
        if (callbackMap.find(env) == callbackMap.end())
            return env.Null();

        return callbackMap.find(env)->second.Call(args);
    }

  private:
    void clean(Napi::Env env)
    {
        if (callbackMap.find(env) == callbackMap.end())
            return;

        callbackMap.find(env)->second.Unref();
        callbackMap.find(env)->second.Reset();
        callbackMap.erase(env);
    }
};

} // namespace operations_research