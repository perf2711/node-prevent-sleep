#include "prevent_sleep.h"
#include <iostream>

Napi::Value prevent_sleep::enable(const Napi::CallbackInfo& info) {
    std::cerr << "node-prevent-sleep is not supported yet on Linux.";
    return info.Env().Undefined();
}

Napi::Value prevent_sleep::disable(const Napi::CallbackInfo& info) {
    std::cerr << "node-prevent-sleep is not supported yet on Linux.";
    return info.Env().Undefined();
}

Napi::Object prevent_sleep::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("enable", Napi::Function::New(env, prevent_sleep::enable));
    exports.Set("disable", Napi::Function::New(env, prevent_sleep::disable));

    return exports;
}
