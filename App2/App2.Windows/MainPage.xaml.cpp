//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <sstream>
#include <thread>
#include <mutex>

using namespace App2;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

int i = 7;

MainPage::MainPage()
{
	InitializeComponent();
}


void App2::MainPage::button1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String ^ s;
	s = i.ToString();
	tb1->Text = s;
}

String^ s;
std::mutex m;

void zapisz(String^ &k)
{
	std::lock_guard<std::mutex> lg(m);
	s = k;
}

void App2::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ k = "Hello";
	std::thread t(zapisz, k);
	t.join();
	tb1->Text = s;
}
