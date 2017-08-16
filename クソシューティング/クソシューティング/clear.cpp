#include "all.h"

void ClearScene(){
	SetChar("くりあ", 50, 50);
	if (GetPlayerHp() != 5)SetChar("ノーミスでクリアを目指そう！！", 50, 80);
	else{ SetChar("本当にノーミスクリアするなんて....！！", 50, 80); }
	if (Givekey(KEY_INPUT_RETURN) == 1)ChangeScene(TITLESCENE);
}