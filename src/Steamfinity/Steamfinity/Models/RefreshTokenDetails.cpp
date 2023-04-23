#include "pch.h"

#include "Models/RefreshTokenDetails.h"
#include "Models.RefreshTokenDetails.g.cpp"

using namespace winrt;

using namespace Windows::Foundation;
using namespace Steamfinity::Enums;

namespace winrt::Steamfinity::Models::implementation
{
	RefreshTokenDetails::RefreshTokenDetails(Steamfinity::Enums::SignUpResult const& signUpResult, hstring const& token, DateTime const& expirationTime) noexcept :
		m_signUpResult{ signUpResult },
		m_token{ token },
		m_expirationTime{ expirationTime }
	{
	}

	SignUpResult RefreshTokenDetails::SignUpResult() const noexcept
	{
		return m_signUpResult;
	}

	hstring RefreshTokenDetails::Token() const noexcept
	{
		return m_token;
	}

	DateTime RefreshTokenDetails::ExpirationTime() const noexcept
	{
		return m_expirationTime;
	}
}
