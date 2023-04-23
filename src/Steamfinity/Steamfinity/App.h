#pragma once
#include "App.xaml.g.h"

namespace winrt::Steamfinity::implementation
{
	struct App : AppT<App>
	{
		App();

		void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const&) const;
		void OnNavigationFailed(IInspectable const&, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs const&) const;
	};
}
