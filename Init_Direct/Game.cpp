#include "pch.h"
#include "Game.h"


void CGame::Initialize()
{
	ComPtr<ID3D11Device> devTemp;
	ComPtr<ID3D11DeviceContext> devContextTemp;

	D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&devTemp,
		nullptr,
		&devContextTemp);


	devTemp.As(&dev);
	devContextTemp.As(&devContext);

	ComPtr<IDXGIDevice1> dxgiDevice;
	dev.As(&dxgiDevice);

	ComPtr<IDXGIAdapter> dxgiAdapter;
	dxgiDevice->GetAdapter(&dxgiAdapter);

	ComPtr<IDXGIFactory2> dxgiFactory;
	dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), &dxgiFactory);

	DXGI_SWAP_CHAIN_DESC1 scd = { 0 };
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.BufferCount = 2;
	scd.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	scd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
	scd.SampleDesc.Count = 1;

	CoreWindow^ Window = CoreWindow::GetForCurrentThread();
	dxgiFactory->CreateSwapChainForCoreWindow(
		dev.Get(),
		reinterpret_cast<IUnknown*>(Window),
		&scd,
		nullptr,
		&swapChain);
	ComPtr<ID3D11Texture2D> backbuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backbuffer);
	dev->CreateRenderTargetView(backbuffer.Get(), nullptr, &rendertarget);	
}

void CGame::Update()
{
	
}

void CGame::Render()
{
	devContext->OMSetRenderTargets(1, rendertarget.GetAddressOf(), nullptr);

	float color[4] = { 0.8f, 0.2f, 0.4f, 1.0f };
	devContext->ClearRenderTargetView(rendertarget.Get(), color);

	swapChain->Present(1, 0);

}
