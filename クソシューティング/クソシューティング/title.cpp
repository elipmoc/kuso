#include "all.h"

void TitleScene(){
	SetChar("文字シューティング", 50, 50);
	if(Givekey(KEY_INPUT_RETURN)==1)ChangeScene(GAMESCENE);
}

//初期化処理
void TitleSceneInit(){ StopBgm(); PlayBgm(TITLE_BGM); }