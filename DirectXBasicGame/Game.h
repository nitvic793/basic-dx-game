//
// Game.h
//

#pragma once

#include "pch.h"
#include "StepTimer.h"
#include "AnimatedTexture.h"
#include "ScrollingBackground.h"
// A basic game implementation that creates a D3D11 device and
// provides a game loop
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window);

    // Basic game loop
    void Tick();
    void Render();

    // Rendering helpers
    void Clear();
    void Present();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged();
	void ProcessInput(WPARAM wParam);

    // Properites
    void GetDefaultSize( size_t& width, size_t& height ) const;

private:

    void Update(DX::StepTimer const& timer);
	void ProcessInput();

    void CreateDevice();
    void CreateResources();
    
    void OnDeviceLost();

    // Application state
    HWND                                            m_window;

	//Input data
	std::queue<WPARAM> m_inputQueue;

    // Direct3D Objects
    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    // Rendering resources
    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;
    Microsoft::WRL::ComPtr<ID3D11Texture2D>         m_depthStencil;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	std::unique_ptr<AnimatedTexture> m_ship;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	DirectX::SimpleMath::Vector2 m_shipPos;
	std::unique_ptr<ScrollingBackground> m_stars;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_backgroundTex;

    // Game state
    DX::StepTimer                                   m_timer;
};