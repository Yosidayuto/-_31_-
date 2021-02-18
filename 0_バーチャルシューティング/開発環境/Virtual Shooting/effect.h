//=============================================================================
//
// �G�t�F�N�g���� [effect.h]
// Author : �g�c�I�l
//
//=============================================================================

#ifndef _EFFECT_H_
#define _EFFECT_H_
//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "scene2d.h"

//=============================================================================
// �N���X��`
//=============================================================================
class CEffect:public CScene2d
{
public:
	CEffect(int nPriorit = PRIORITY_OBJECT_1);
	~CEffect();
	typedef enum  //�G�t�F�N�g���
	{
		EFFECT_TYPE_BULLET = 0,
		EFFECT_TYPE_LASER,
		EFFECT_TYPE_MAX
	}EFFECT_TYPE;

	static CEffect*	Create(D3DXVECTOR3 Pos, D3DXCOLOR col, D3DXVECTOR3 size, EFFECT_TYPE type);	//��������
	static void		Unload(void);							//�e�N�X�`���̔j��
	static HRESULT	Load(void);								//�e�N�X�`���ǂݍ���

	HRESULT	Init( D3DXVECTOR3 size, D3DXCOLOR col);		//����������
	void	Uninit(void);								//�I������
	void	Update(void);								//�X�V����
	void	Draw(void);									//�`�揈��
private:
	static TEXTURE_DATA	m_TextureData[EFFECT_TYPE_MAX];	// �e�N�X�`���f�[�^
	D3DXVECTOR3 m_size;				//�T�C�Y
	EFFECT_TYPE m_Type;				//�^�C�v
	D3DXCOLOR	m_col;				//�J���[
	int	nLife;						//�G�t�F�N�g�̎˒�����

};

#endif