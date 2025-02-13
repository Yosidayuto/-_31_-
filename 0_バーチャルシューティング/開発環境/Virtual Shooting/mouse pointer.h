//=============================================================================
//
// マウスポインター [mouse pointer.h]
// Author : 吉田悠人
//
//=============================================================================
#ifndef _MOUSE_POINTER_H_
#define _MOUSE_POINTER_H_
//=============================================================================
// ヘッダファイルのインクルード
//=============================================================================
#include "main.h"
#include "scene2D.h"


//=============================================================================
// クラス定義
//=============================================================================
class CPointer : public CScene2d
{
public:

	CPointer(int nPriorit = PRIORITY_UI_3);			// コンストラクタ
	~CPointer();									// デストラクタ
	static HRESULT	 Load(void);					// テクスチャ読み込み
	static void		 Unload(void);					// テクスチャ破棄
	HRESULT Init(void);								// 初期化処理
	void	Uninit(void);							// 終了処理
	void	Update(void);							// 更新処理
	void	Draw(void);								// 描画処理
	void	MouseMove(void);						// マウス追従処理
private:

};



#endif // !_POLYGON_H_
