//=============================================================================
//
//	バレットボタン[bullet button.h]
//	Author:吉田　悠人
//
//=============================================================================

#ifndef _BULLET_BUTTON_H_
#define _BULLET_BUTTON_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "button.h"

//=============================================================================
// クラス定義
//=============================================================================
class CBulletButton :public CButton
{
public:

	CBulletButton(int nPriorit = PRIORITY_UI_1);	//コンストラクタ
	~CBulletButton();								//デストラクタ
	static HRESULT			Load(void);
	static void				Unload(void);
	static CBulletButton*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);


	HRESULT			Init(void);		// 初期化処理
	void			Uninit(void);	// 終了処理
	void			Update(void);	// 更新処理
	void			Draw(void);		// 描画処理
	void			MouseOver(void);// マウスオーバー判定
	void			Push(void);		// プッシュ判定処理
private:
	static TEXTURE_DATA	m_TextureData;	// テクスチャデータ
};
#endif
