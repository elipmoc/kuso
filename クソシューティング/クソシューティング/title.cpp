#include "all.h"

void TitleScene(){
	SetChar("�����V���[�e�B���O", 50, 50);
	if(Givekey(KEY_INPUT_RETURN)==1)ChangeScene(GAMESCENE);
}

//����������
void TitleSceneInit(){ StopBgm(); PlayBgm(TITLE_BGM); }