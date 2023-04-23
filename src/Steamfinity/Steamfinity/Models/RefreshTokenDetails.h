#pragma once
#include "Models.RefreshTokenDetails.g.h"

namespace winrt::Steamfinity::Models::implementation
{
	struct RefreshTokenDetails : RefreshTokenDetailsT<RefreshTokenDetails>
	{
		RefreshTokenDetails(Steamfinity::Enums::SignUpResult const&, hstring const&, Windows::Foundation::DateTime const&) noexcept;

		Steamfinity::Enums::SignUpResult SignUpResult() const noexcept;
		hstring Token() const noexcept;
		Windows::Foundation::DateTime ExpirationTime() const noexcept;

		private:

		Steamfinity::Enums::SignUpResult m_signUpResult;
		hstring m_token;
		Windows::Foundation::DateTime m_expirationTime;
	};
}

namespace winrt::Steamfinity::Models::factory_implementation
{
	struct RefreshTokenDetails : RefreshTokenDetailsT<RefreshTokenDetails, implementation::RefreshTokenDetails>
	{
	};
}
