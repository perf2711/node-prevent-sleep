#include "prevent_sleep.h"
#include <Windows.h>

HANDLE _powerRequestHandle;
REASON_CONTEXT _powerReasonContext;

Napi::Value prevent_sleep::enable(const Napi::CallbackInfo &info)
{
    _powerReasonContext.Version = 0;
    _powerReasonContext.Flags = 1;
    _powerReasonContext.Reason.SimpleReasonString = L"node-prevent-sleep";

    _powerRequestHandle = PowerCreateRequest(&_powerReasonContext);
    if (_powerRequestHandle != INVALID_HANDLE_VALUE)
    {
        if (PowerSetRequest(_powerRequestHandle, PowerRequestSystemRequired))
        {
            if (PowerSetRequest(_powerRequestHandle, PowerRequestDisplayRequired))
            {
                return info.Env().Undefined();
            }
        }
    }

    throw Napi::Error::New(info.Env(), "failed to enable sleep lock");
}

Napi::Value prevent_sleep::disable(const Napi::CallbackInfo &info)
{
    if (_powerRequestHandle != NULL)
    {
        if (PowerClearRequest(_powerRequestHandle, PowerRequestDisplayRequired))
        {
            if (PowerClearRequest(_powerRequestHandle, PowerRequestDisplayRequired))
            {
                if (CloseHandle(_powerRequestHandle))
                {
                    return info.Env().Undefined();
                }
            }
        }

        throw Napi::Error::New(info.Env(), "failed to disable sleep lock");
    }

    return info.Env().Undefined();
}

Napi::Object prevent_sleep::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("enable", Napi::Function::New(env, prevent_sleep::enable));
    exports.Set("disable", Napi::Function::New(env, prevent_sleep::disable));

    return exports;
}
