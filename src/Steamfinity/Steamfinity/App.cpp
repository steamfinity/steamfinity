#include "pch.h"
#include "App.h"

using namespace winrt;

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

namespace winrt::Steamfinity::implementation
{
	App::App()
	{
		#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
		UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
		{
			if (IsDebuggerPresent())
			{
				auto const errorMessage{ e.Message() };
				__debugbreak();
			}
		});
		#endif
	}

	void App::OnLaunched(LaunchActivatedEventArgs const& e) const
	{
		Frame rootFrame{ nullptr };

		auto const currentWindow{ Window::Current() };
		if (auto const content{ currentWindow.Content() })
		{
			rootFrame = content.try_as<Frame>();
		}

		if (!rootFrame)
		{
			rootFrame = Frame{};
			rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

			if (!e.PrelaunchActivated())
			{
				if (!rootFrame.Content())
				{
					rootFrame.Navigate(xaml_typename<Steamfinity::MainPage>(), box_value(e.Arguments()));
				}

				currentWindow.Content(rootFrame);
				currentWindow.Activate();
			}
		}
		else
		{
			if (!e.PrelaunchActivated())
			{
				if (!rootFrame.Content())
				{
					rootFrame.Navigate(xaml_typename<Steamfinity::MainPage>(), box_value(e.Arguments()));
				}

				currentWindow.Activate();
			}
		}
	}

	void App::OnNavigationFailed(IInspectable const&, NavigationFailedEventArgs const& e) const
	{
		throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
	}
}
