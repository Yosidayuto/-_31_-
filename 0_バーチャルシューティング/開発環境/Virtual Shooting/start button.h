//=============================================================================
//
//	スタートボタン[start button.h]
//	Author:吉田　悠人
//
//=============================================================================

#ifndef _START_BUTTON_H_
#define _START_BUTTON_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "button.h"

//=============================================================================
//前方宣言
//=============================================================================
class CNumber;

//=============================================================================
// クラス定義
//=============================================================================
class CStartButton :public CButton
{
public:

	CStartButton(int nPriorit = PRIORITY_UI_1);	//コンストラクタ
	~CStartButton();							//デストラクタ
	static HRESULT			Load(void);
	static void				Unload(void);
	static CStartButton*	Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);


	HRESULT			Init(void);		// 初期化処理
	void			Uninit(void);	// 終了処理
	void			Update(void);	// 更新処理
	void			Draw(void);		// 描画処理
	void			MouseOver(void);// マウスオーバー判定
	void			Push(void);		// プッシュ判定処理
private:
	static TEXTURE_DATA	m_TextureData;	// テクスチャデータ
	CNumber*			m_pNumber;		// ナンバー
	static int			m_StageNuber;	// 次のステージ番号
};
#endif
