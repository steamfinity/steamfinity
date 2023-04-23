#pragma once

#include "SignUpResult.g.h"

namespace winrt::Steamfinity::implementation
{
    struct SignUpResult : SignUpResultT<SignUpResult>
    {
        SignUpResult() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Steamfinity::factory_implementation
{
    struct SignUpResult : SignUpResultT<SignUpResult, implementation::SignUpResult>
    {
    };
}
