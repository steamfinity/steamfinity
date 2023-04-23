#pragma once
#include "Services.SteamfinityCloud.g.h"

namespace winrt::Steamfinity::Services::implementation
{
	struct SteamfinityCloud : SteamfinityCloudT<SteamfinityCloud>
	{
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
