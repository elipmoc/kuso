#include "all.h"


//現在のシーン
static SCENE scene;

//シーン切り替えするかどうか
static bool sceneChangeFlag = true;

//ゲーム終了フラグ
//これをtrueにするとCentralの戻り値がfalseになりWhileループを抜けてプログラム終了
static bool endflag=false;

bool Central(){
	//シーン切り替えする処理
	if (sceneChangeFlag){
		if (scene == GAMESCENE)GameSceneInit();
		if (scene == TITLESCENE)TitleSceneInit();
		sceneChangeFlag = false;
	}
	switch (scene)
	{
	case 0:
		TitleScene();
		break;
	case 1:
		GameScene();
		break;
	case 2:
		GameOverScene();
		break;
	case 3:
		ClearScene();
		break;
	}
	Getkey();
	BgmLoop();
	DrawChar();
	return !endflag;
}

void End(){endflag = true;}

void ChangeScene(SCENE _scene){
	if (scene == GAMESCENE)GameSceneEnd();
	sceneChangeFlag = true;
	scene = _scene;}