//=============================================================================
//
// チュートリアル処理 [tutorial.cpp]
// Author : 吉田悠人
//
//=============================================================================
//=============================================================================
//インクルードファイル
//=============================================================================
#include "tutorial.h"
#include "sound.h"
#include "fade.h"
#include "inputmouse.h"
#include "tutorial bg.h"
//=============================================================================
// コンストラクタ
//=============================================================================
CTutorial::CTutorial()
{
	m_pTutorialBg = NULL;
}

//=============================================================================
// デストラクタ
//=============================================================================
CTutorial::~CTutorial()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTutorial::Init(void)
{
	CSound*	pSound = CManager::GetSound();	//サウンド取得

	//チュートリアル生成
	m_pTutorialBg = CTutorialBg::Create();

	//ここまで
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTutorial::Uninit(void)
{
	//サウンド取得
	CSound*	pSound = CManager::GetSound();
	//サウンド停止
	pSound->Stop();
	//シーン破棄
	CScene::ReleaseAll();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTutorial::Update(void)
{
	CSound*		pSound	= CManager::GetSound();	//サウンド取得
	CInihMouse*	pMouse	= CManager::GetMouse();	//マウス取得
	CFade*		pFade	= CManager::GetFade();	//フェード取得	
	static int	nCount	= 0;					//クリックカウント
			
	//マウスを左クリック
	if (pMouse->GetClickTrigger(0) == true)
	{
		nCount++;
		if (nCount>3)
		{
			pFade->SetFade(GAME_MODE_SELECT);
			nCount = 0;
		}
		else
		{
			//NULLチェック
			if (pSound != NULL)
			{
				//SE再生
				pSound->Play(CSound::LABEL_SE_CLICK);
			}
			//NULLチェック
			if (m_pTutorialBg != NULL)
			{
				m_pTutorialBg->TextureMove(true);
			}

		}
	}
	//マウスを右クリック
	else if (pMouse->GetClickTrigger(1) == true)
	{
		//クリックカウント
		nCount--;
		if (nCount<0)
		{
			nCount=0;
		}
		else
		{
			//NULLチェック
			if (pSound != NULL)
			{
				//SE再生
				pSound->Play(CSound::LABEL_SE_CLICK);
			}
			//NULLチェック
			if (m_pTutorialBg != NULL)
			{
				m_pTutorialBg->TextureMove(false);
			}

		}
	}

}

//=============================================================================
// 描画関数
//=============================================================================
void CTutorial::Draw(void)
{
}
