#include <napi.h>

namespace prevent_sleep
{
    Napi::Value enable(const Napi::CallbackInfo &info);
    Napi::Value disable(const Napi::CallbackInfo &info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
} // namespace prevent_sleep
