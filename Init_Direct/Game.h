#pragma once
using namespace Microsoft::WRL;
using namespace Windows::UI::Core;
using namespace DirectX;

struct VERTEX{
	float X, Y, Z;
};

class CGame
{
public:
	ComPtr<ID3D11Device1> dev;
	ComPtr<ID3D11DeviceContext1> devContext;
	ComPtr<IDXGISwapChain1> swapChain;
	ComPtr<ID3D11RenderTargetView> rendertarget;
	ComPtr<ID3D11Buffer> vertexbuffer;


	void Initialize();
	void InitGraphics();
	void Update();
	void Render();
};

