#include "all.h"

//�L�[���͂�ێ�����ϐ�
int key[256];

void Getkey(){
	char GetHitkey[256];
	GetHitKeyStateAll(GetHitkey);
	for (int i = 0; i<256; i++){
		if (GetHitkey[i] == 1)key[i]++;
		else               key[i] = 0;
	}
}

//���ʂ�Ԃ��֐�
int Givekey(int keyCode){
	if (keyCode<0 || 256 <= keyCode)return -1;
	else return key[keyCode];
}