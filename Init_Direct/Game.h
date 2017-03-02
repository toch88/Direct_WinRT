#pragma once
using namespace Microsoft::WRL;
using namespace Windows::UI::Core;
using namespace DirectX;

class CGame
{
public:
	ComPtr<ID3D11Device1> dev;
	ComPtr<ID3D11DeviceContext1> devContext;
	ComPtr<IDXGISwapChain1> swapChain;
	ComPtr<ID3D11RenderTargetView> rendertarget;


	void Initialize();
	void Update();
	void Render();
};

