#include "prevent_sleep.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return prevent_sleep::Init(env, exports);
}

NODE_API_MODULE(node_prevent_sleep, InitAll)
