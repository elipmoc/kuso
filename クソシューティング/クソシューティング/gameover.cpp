#include "all.h"

void GameOverScene(){
	SetChar("��-�ނ��[�΁[", 50, 50);
	if (Givekey(KEY_INPUT_RETURN) == 1)ChangeScene(TITLESCENE);
}