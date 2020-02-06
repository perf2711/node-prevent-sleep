#include "prevent_sleep.h"
#include <Windows.h>

EXECUTION_STATE _previousState = -1;

Napi::Value prevent_sleep::enable(const Napi::CallbackInfo& info) {
    _previousState = SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED);

    return info.Env().Undefined();
}

Napi::Value prevent_sleep::disable(const Napi::CallbackInfo& info) {
    if (_previousState > 0) {
        SetThreadExecutionState(_previousState);
        _previousState = -1;
    }

    return info.Env().Undefined();
}

Napi::Object prevent_sleep::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("enable", Napi::Function::New(env, prevent_sleep::enable));
    exports.Set("disable", Napi::Function::New(env, prevent_sleep::disable));

    return exports;
}
