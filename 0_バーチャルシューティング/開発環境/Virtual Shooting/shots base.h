//=============================================================================
//
// ショット ベース処理 [shots base.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _SHOTS_BASE_H_
#define _SHOTS_BASE_H_
//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "scene.h"
//=============================================================================
// クラス定義
//=============================================================================
class CShotsBase 
{
public:
	CShotsBase();				// コンストラクタ
	~CShotsBase();				// デストラクタ	
	HRESULT Init(void);			// 初期化処理
	void	Uninit(void);		// 終了処理
	void	Update(void);		// 更新処理
	void	Tracking(float fSpeed);			// 撃つ向き処理

	virtual void Shots(void) = 0;

	void		SetRot(D3DXVECTOR3 rot);	// 向きセッター
	D3DXVECTOR3	GetRot(void);				// 向きゲッター
	void		SetPos(D3DXVECTOR3 pos);	// 位置セッター
	D3DXVECTOR3	GetPos(void);				// 位置ゲッター
	void		SetShotsEnd(bool bShots);	// 撃ち終わったかのセッター
	bool		GetShotsEnd(void);			// 撃ち終わったかのゲッター
private:
	D3DXVECTOR3	m_rot;	// エネミーの向き
	D3DXVECTOR3 m_pos;	// エネミーの位置
	bool		m_bShotsEnd;	//撃ち終わったか
};
#endif