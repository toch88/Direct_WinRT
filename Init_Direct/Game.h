#pragma once
using namespace Microsoft::WRL;
using namespace Windows::UI::Core;
using namespace DirectX;

ref class CGame
{
public:
	void Initialize();
	void Update();
	void Render();
};

