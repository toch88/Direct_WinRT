#include "pch.h"
#pragma region using_namespace

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Platform;


ref class App sealed :public IFrameworkView {
public:
		

	// Inherited via IFrameworkView
	virtual void Initialize(CoreApplicationView ^applicationView)
	{	//declare the generic event for OnActive function (callback)
		applicationView->Activated += ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);
		
	}
	virtual void SetWindow(CoreWindow ^window){}
	virtual void Load(String ^entryPoint){}
	virtual void Run(){}
	virtual void Uninitialize(){}

	void OnActivated(CoreApplicationView^ CoreAppView, IActivatedEventArgs^ Args) {
		
		CoreWindow^ Window = CoreWindow::GetForCurrentThread(); //return the pointer to Window 
		Window->Activate();
		
	}

};

ref class AppSource sealed : IFrameworkViewSource {
public:
	virtual IFrameworkView^ CreateView() {
		return ref new App();
	}
};

[MTAThread]

int main(Array<String^>^ args) {
	CoreApplication::Run(ref new AppSource());
	return 0;
}

#pragma endregion

