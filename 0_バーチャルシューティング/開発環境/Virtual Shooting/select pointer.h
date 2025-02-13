//=============================================================================
//
// セレクトのマウスポインター [select pointer.h]
// Author : 吉田悠人
//
//=============================================================================

#ifndef _SELECT_POINTER_H_
#define _SELECT_POINTER_H_

//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "main.h"
#include "mouse pointer.h"
//=============================================================================
// クラス定義
//=============================================================================
class CSelectPointer : public CPointer
{
public:

	CSelectPointer();						// コンストラクタ
	~CSelectPointer();						// デストラクタ
	static HRESULT			Load(void);		// テクスチャ読み込み
	static void				Unload(void);	// テクスチャ破棄
	static CSelectPointer*	Create(void);	// 作成処理
	HRESULT Init(void);						// 初期化処理
	void	Uninit(void);					// 終了処理
	void	Update(void);					// 更新処理
	void	Draw(void);						// 描画処理

private:
	static TEXTURE_DATA	m_TextureData;	//テクスチャデータ

};
#endif // !_POLYGON_H_
