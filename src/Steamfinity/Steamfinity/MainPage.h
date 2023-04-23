#pragma once
#include "MainPage.g.h"

namespace winrt::Steamfinity::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
	};
}

namespace winrt::Steamfinity::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{
	};
}
