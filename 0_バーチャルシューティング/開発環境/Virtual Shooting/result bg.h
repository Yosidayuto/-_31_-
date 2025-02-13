//=============================================================================
//
//	リザルト背景[result bg.h]
//	Author:吉田　悠人
//
//=============================================================================

#ifndef _RESULT_BG_H_
#define _RESULT_BG_H_
//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "bg.h"
//=============================================================================
// クラス定義
//=============================================================================
class CResultBg :public CBgc
{
public:
	CResultBg(int nPriorit = PRIORITY_SCENE);	//コンストラクタ
	~CResultBg();								//デストラクタ

	static HRESULT		Load(void);		//テクスチャ読み込み
	static void			Unload(void);	//テクスチャの破棄
	static CResultBg*		Create(void);	//生成処理

	HRESULT			Init(void);		//初期化処理
	void			Uninit(void);	//終了処理
	void			Update(void);	//更新処理
	void			Draw(void);		//描画処理

private:
	static TEXTURE_DATA	m_TextureData;	//テクスチャデータ

};
#endif