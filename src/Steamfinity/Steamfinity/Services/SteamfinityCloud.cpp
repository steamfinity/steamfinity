#include "pch.h"

#include "Services/SteamfinityCloud.h"
#include "Services.SteamfinityCloud.g.cpp"

using namespace winrt;

using namespace Windows::Foundation;
using namespace Windows::Data::Json;
using namespace Windows::Web::Http;

using namespace Steamfinity::Enums;

namespace winrt::Steamfinity::Services::implementation
{
	IAsyncOperation<SignUpResult> SteamfinityCloud::SignUpAsync(hstring const& userName, hstring const& password) const
	{
		JsonObject const requestData;
		requestData.Insert(L"userName", JsonValue::CreateStringValue(userName));
		requestData.Insert(L"password", JsonValue::CreateStringValue(password));

		Uri const requestUri{ to_hstring(STEAMFINITY_API_BASE_URL) + L"Authentication/SignUp" };
		HttpStringContent const requestContent{ requestData.Stringify() };

		auto const& response = co_await m_httpClient.PostAsync(requestUri, requestContent);

		if (!response.IsSuccessStatusCode())
		{
			auto const& responseContent{ co_await response.Content().ReadAsStringAsync() };
			auto const errorCode{ JsonObject::Parse(responseContent).GetNamedString(L"code") };

			if (errorCode == L"DUPLICATE_USER_NAME") co_return SignUpResult::DuplicateUserName;
			else if (errorCode == L"INVALID_USER_NAME") co_return SignUpResult::InvalidUserName;
			else if (errorCode == L"PASSWORD_TOO_WEAK") co_return SignUpResult::PasswordTooWeak;

			response.EnsureSuccessStatusCode();
		}

		co_return SignUpResult::Success;
	}
}
