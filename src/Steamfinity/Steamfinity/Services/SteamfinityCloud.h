#pragma once
#include "Services.SteamfinityCloud.g.h"

namespace winrt::Steamfinity::Services::implementation
{
	struct SteamfinityCloud : SteamfinityCloudT<SteamfinityCloud>
	{
		Windows::Foundation::IAsyncOperation<Steamfinity::Enums::SignUpResult> SignUpAsync(hstring const&, hstring const&) const;

		private:
		Windows::Web::Http::HttpClient m_httpClient;
	};
}

namespace winrt::Steamfinity::Services::factory_implementation
{
	struct SteamfinityCloud : SteamfinityCloudT<SteamfinityCloud, implementation::SteamfinityCloud>
	{
	};
}
