//=============================================================================
//
// ボスタイプ1処理 [boss type1.h]
// Author : 吉田悠人
//
//=============================================================================

#ifndef _BOSS_TYPE_1_H_
#define _BOSS_TYPE_1_H_

//=============================================================================
//インクルードファイル
//=============================================================================
#include "main.h"
#include "boss base.h"
//=============================================================================
//前方宣言
//=============================================================================

//=============================================================================
// クラス定義
//=============================================================================
class CBossType1 :public CBossBase
{
public:
	CBossType1(int nPriorit = PRIORITY_OBJECT_1);	//コンストラクタ
	~CBossType1();									//デストラクタ	

	static HRESULT		Load(void);					// テクスチャ読み込み
	static void			Unload(void);				// テクスチャの破棄
	static CBossType1*	Create(D3DXVECTOR3 pos);	// 生成処理

	HRESULT Init(void);				// 初期化処理
	void	Uninit(void);			// 終了処理
	void	Update(void);			// 更新処理
	void	Draw(void);				// 描画処理
private:
	static TEXTURE_DATA	m_TextureData;					// テクスチャデータ

};
#endif