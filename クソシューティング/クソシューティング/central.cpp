#include "all.h"


//���݂̃V�[��
static SCENE scene;

//�V�[���؂�ւ����邩�ǂ���
static bool sceneChangeFlag = true;

//�Q�[���I���t���O
//�����true�ɂ����Central�̖߂�l��false�ɂȂ�While���[�v�𔲂��ăv���O�����I��
static bool endflag=false;

bool Central(){
	//�V�[���؂�ւ����鏈��
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