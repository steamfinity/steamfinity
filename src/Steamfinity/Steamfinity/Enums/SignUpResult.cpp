#include "pch.h"
#include "SignUpResult.h"
#if __has_include("SignUpResult.g.cpp")
#include "SignUpResult.g.cpp"
#endif

namespace winrt::Steamfinity::implementation
{
    int32_t SignUpResult::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SignUpResult::MyProperty(int32_t /*value*/)
    {
        throw hresult_not_implemented();
    }
}
