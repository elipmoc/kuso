
//�{���͂���ȓ��̈����w�b�_�t�@�C���͍���Ă͍s���Ȃ��B
//�K�v�ȃw�b�_������ǂݍ��ނׂ�
#include "all.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	//�E�C���h�E�Ƃ��̏�����
	SetMainWindowText("�����V���[�e�B���O");
	SetGraphMode(500, 480,16);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	//�����f�[�^�����炩���߃������Ƀ��[�h���č���������
	Load();

	//�g�p����t�H���g�̐ݒ�
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	//���C�����[�v
	//Central()�Ŏ��ۂ̃Q�[���̏������s���Ă��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Central());

	DxLib_End(); // DX���C�u�����I������
	return 0;
}