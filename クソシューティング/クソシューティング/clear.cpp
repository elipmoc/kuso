#include "all.h"

void ClearScene(){
	SetChar("���肠", 50, 50);
	if (GetPlayerHp() != 5)SetChar("�m�[�~�X�ŃN���A��ڎw�����I�I", 50, 80);
	else{ SetChar("�{���Ƀm�[�~�X�N���A����Ȃ��....�I�I", 50, 80); }
	if (Givekey(KEY_INPUT_RETURN) == 1)ChangeScene(TITLESCENE);
}