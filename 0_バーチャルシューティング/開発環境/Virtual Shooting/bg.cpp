//=============================================================================
//
//	背景[bg.h]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "bg.h"
#include "scene2d.h"
//=============================================================================
// コンストラクタ
//=============================================================================
CBgc::CBgc(int nPriorit):CScene2d(nPriorit)
{
	m_nCounterAnim = 0;
	m_nPatternAnim = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CBgc::~CBgc()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBgc::Init(void)
{
	//オブジェクト2D初期化
	CScene2d::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CBgc::Uninit(void)
{
	//オブジェクト2D終了
	CScene2d::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CBgc::Update(void)
{
	//オブジェクト2D更新
	CScene2d::Update();
}

//=============================================================================
// 描画関数
//=============================================================================
void CBgc::Draw(void)
{
	//オブジェクト2D描画
	CScene2d::Draw();
}


//=============================================================================
// スクロールY方向関数
//=============================================================================
void CBgc::ScrollY(float fScroll)
{
	D3DXVECTOR2 Texture[4];
	Texture[0] = D3DXVECTOR2(0.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f));
	Texture[1] = D3DXVECTOR2(1.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f));
	Texture[2] = D3DXVECTOR2(0.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f) + (1.0f / 1.0f));
	Texture[3] = D3DXVECTOR2(1.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f) + (1.0f / 1.0f));
	
	//アニメーションカウント
	m_nCounterAnim++;
	if (m_nCounterAnim % 2)
	{
		//アニメーションの絵を次の絵に変える
		m_nPatternAnim++;

		m_nCounterAnim = 0;
		if (m_nPatternAnim >= (1.0f/ fScroll))
		{
			m_nPatternAnim = 0;
		}
	}
	TextureAnim(Texture);
}

//=============================================================================
// スクロールX方向関数
//=============================================================================
void CBgc::ScrollX(float fScroll)
{
	D3DXVECTOR2 Texture[4];
	Texture[0] = D3DXVECTOR2(0.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f));
	Texture[1] = D3DXVECTOR2(1.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f));
	Texture[2] = D3DXVECTOR2(0.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f) + (1.0f / 1.0f));
	Texture[3] = D3DXVECTOR2(1.0f, ((float)-m_nPatternAnim * fScroll)*(1.0f / 1.0f) + (1.0f / 1.0f));

	//アニメーションカウント
	m_nCounterAnim++;
	if (m_nCounterAnim % 2)
	{
		//アニメーションの絵を次の絵に変える
		m_nPatternAnim++;

		m_nCounterAnim = 0;
		if (m_nPatternAnim >= (1.0f / fScroll))
		{
			m_nPatternAnim = 0;
		}
	}
	TextureAnim(Texture);

}
