//�}�E�X�����̃w�b�_�t�@�C��

//#�w�b�_�t�@�C���ǂݍ���

//�Q�[���̃��C���w�b�_�t�@�C��
#include "game.h"
#include "shape.h"

//#�}�N����`
//�}�E�X�̃{�^��
#define MOUSE_BUTTON_CODE 129	//0x0000�`0x0080�܂�

//#�\����

//�}�E�X�\����
struct MOUSE
{
	int InputValue = 0;	//GetMouseInput�̒l������
	int WheelValue = 0;	//�}�E�X�z�C�[���̉�]�ʁi���̓v���X�l / ��O�̓}�C�i�X�l�j
	iPOINT Point;						//�}�E�X�̍��W������
	iPOINT OldPoint;					//�}�E�X�̍��W�i���O�j������
	int OldButton[MOUSE_BUTTON_CODE];	//�}�E�X�̃{�^�����́i���O�j������
	int Button[MOUSE_BUTTON_CODE];		//�}�E�X�̃{�^�����͂�����
};

//#�O���̃O���[�o���ϐ�

//�}�E�X���͂��擾
extern MOUSE mouse;

//#�v���g�^�C�v�錾
//extern�͊O���Ɋ֐�������Ƃ����ڈ�

extern VOID MouseUpdate(VOID);								//�}�E�X�̓��͏����X�V����
extern BOOL MouseDown(int MOUSE_INPUT_);					//�{�^���������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����
extern BOOL MouseUp(int MOUSE_INPUT_);						//�{�^���������グ�Ă��邩�A�}�E�X�R�[�h�Ŕ��f����
extern BOOL MouseDownKeep(int MOUSE_INPUT_, int MilliTime);	//�{�^�������������Ă��邩�A�}�E�X�R�[�h�Ŕ��f����
extern BOOL MouseClick(int MOUSE_INPUT_);					//�}�E�X���N���b�N�������A�}�E�X�R�[�h�Ŕ��f����
extern VOID MouseDraw(VOID);								//�}�E�X�̏���`�悷��

extern BOOL MouseRECTClick(RECT rect, int MOUSE_INPUT_);	//�}�E�X����`�̈���N���b�N�������H
extern BOOL MouseMaruClick(MARU rect, int MOUSE_INPUT_);	//�}�E�X���~�̈���N���b�N�������H
