//=============================================================================
//
//	レーザーボタン[laser button.h]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "laser button.h"
#include "manager.h"
#include "renderer.h"
#include "sound.h"
#include "score.h"
#include "select.h"
#include "telop.h"
#include "player data.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define LASER_SCORE (7000)	//消費スコア
//=============================================================================
// 静的メンバー変数
//=============================================================================
TEXTURE_DATA CLaserButton::m_TextureData = { NULL,	"data/TEXTURE/Text_Laser.png", };

//=============================================================================
// コンストラクタ
//=============================================================================
CLaserButton::CLaserButton(int nPriorit)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CLaserButton::~CLaserButton()
{
}

//=============================================================================
// テクスチャ読み込み
//=============================================================================
HRESULT CLaserButton::Load(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		m_TextureData.m_cFileName,
		&m_TextureData.m_Texture);

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CLaserButton::Unload(void)
{
	//テクスチャの破棄
	if (m_TextureData.m_Texture != NULL)
	{
		m_TextureData.m_Texture->Release();
		m_TextureData.m_Texture = NULL;
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CLaserButton * CLaserButton::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CLaserButton* pLaserButton;
	pLaserButton = new CLaserButton;

	//位置設定
	pLaserButton->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
	//サイズ設定
	pLaserButton->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
	//テクスチャ設定
	pLaserButton->BindTexture(m_TextureData.m_Texture);
	//初期化処理
	pLaserButton->Init();

	return pLaserButton;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CLaserButton::Init(void)
{
	//ボタンの初期化処理
	CButton::Init();
	//位置設定
	SetPos(D3DXVECTOR3(GetPos().x + 85, GetPos().y, 0.0f));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CLaserButton::Uninit(void)
{
	CButton::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CLaserButton::Update(void)
{
	CButton::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CLaserButton::Draw(void)
{
	CButton::Draw();
}

//=============================================================================
// マウスオーバー判定
//=============================================================================
void CLaserButton::MouseOver(void)
{
	//スコア減少量取得
	CScore*		pMinusScore = CSelect::GetMinusScore();
	//テロップポインタ
	CTelop*		pTelop = CSelect::GetTelop();

	//消費スコア反映
	pMinusScore->SetScore(LASER_SCORE);
	//テロップ切替
	if (pTelop->GetTelopType() != TELOP_TYPE_LASER)
	{
		pTelop->TypeChange(TELOP_TYPE_LASER);
	}
}

//=============================================================================
// プッシュ判定処理
//=============================================================================
void CLaserButton::Push(void)
{
	//マウスポインタ取得
	CInihMouse* pMouse = CManager::GetMouse();
	//サウンド取得
	CSound*		pSound = CManager::GetSound();
	//プレイヤーデータ取得
	CPlayerData*	pPlayer = CManager::GetPlayer();
	//武装データ取得
	WEAPON_DATA WeaponData = pPlayer->GetWeaponData();
	//スコア
	CScore*		pScore = CSelect::GetScore();
	//取得スコアデータ取得
	int			nScore = pScore->GetScore();

	//左クリック
	if (pMouse->GetClickTrigger(CLICK_LEFT) == true)
	{
		//プレイヤーの武装に空きがあるか
		if (WeaponData.Left == WEAPONS_MODE_NONE
			|| WeaponData.Right == WEAPONS_MODE_NONE)
		{
			//現在のスコアが消費スコアより多いか
			if (nScore >= LASER_SCORE)
			{
				//クリック音SE
				pSound->Play(CSound::LABEL_SE_CLICK);
				//スコア消費
				pScore->AddScore(-LASER_SCORE);
				//武装変更
				if (WeaponData.Left == WEAPONS_MODE_NONE)
				{
					//装備設定
					WeaponData.Left = WEAPONS_MODE_LASER;
				}
				else
				{
					//装備設定
					WeaponData.Right = WEAPONS_MODE_LASER;
				}
				//反映
				pPlayer->SetWeaponData(WeaponData);
			}
		}
	}
	//右クリック
	else if (pMouse->GetClickTrigger(CLICK_RIGHT) == true)
	{
		//プレイヤーの武装にバレットがあるか
		if (WeaponData.Left == WEAPONS_MODE_LASER
			|| WeaponData.Right == WEAPONS_MODE_LASER)
		{
			//クリック音SE
			pSound->Play(CSound::LABEL_SE_CLICK);
			//スコア消費
			pScore->AddScore(LASER_SCORE);
			//武装変更
			if (WeaponData.Left == WEAPONS_MODE_LASER)
			{
				//装備設定
				WeaponData.Left = WEAPONS_MODE_NONE;
			}
			else
			{
				//装備設定
				WeaponData.Right = WEAPONS_MODE_NONE;
			}
			//反映
			pPlayer->SetWeaponData(WeaponData);
		}
	}
}
