//=============================================================================
//
//	レンダリング処理[renderer.h]
//	Author:吉田悠人
//
//=============================================================================

#ifndef _RENDERER_H_
#define _RENDERER_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include"main.h"

//=============================================================================
//クラス定義
//=============================================================================
class CRenderer
{
public:
	CRenderer();
	~CRenderer();
	HRESULT Init(HWND hWnd, bool bWindow);
	void	Uninit(void);
	void	Update(void);
	void	Draw(void);

	
	LPDIRECT3DDEVICE9 GetObjects(void) {return m_pD3DDevice;}	//オブジェクトゲッター
private:
	void DrawFPS();
	LPDIRECT3D9				m_pD3D;			// Direct3Dオブジェクト
	LPDIRECT3DDEVICE9		m_pD3DDevice;	// Deviceオブジェクト(描画に必要)
	LPD3DXFONT				m_pFont;		// フォントへのポインタ
};
#endif