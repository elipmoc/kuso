#include "all.h"
COLLISION playerCol;
COLLISION tekiCol;
COLLISION playerBulCol[100];
int pBCEnd = -1;
COLLISION tekiBulCol[200];
int tBCEnd = -1;

//�R���W�������Z�b�g
void SetCollision(XY xy, double size, bool* flag,KIND kind){
	switch (kind)
	{
	case PLAYER:
		playerCol.xy = xy;

		//�����蔻��̈ʒu��8���炷���ƂŒ������Đ^�񒆂ɂ���悤�ɂ��Ă邾��
		playerCol.xy.x += 8;
		playerCol.xy.y += 8;

		playerCol.colFlag = flag;
		playerCol.size = size;
		break;
	case TEKI:
		tekiCol.xy = xy;

		//�����蔻��̈ʒu��8���炷���ƂŒ������Đ^�񒆂ɂ���悤�ɂ��Ă邾��
		tekiCol.xy.x += 8;
		tekiCol.xy.y += 8;

		tekiCol.colFlag = flag;
		tekiCol.size = size;
		break;
	case TEKIBULLET:
		tBCEnd++;
		tekiBulCol[tBCEnd].xy = xy;

		//�����蔻��̈ʒu��8���炷���ƂŒ������Đ^�񒆂ɂ���悤�ɂ��Ă邾��
		tekiBulCol[tBCEnd].xy.x += 8;
		tekiBulCol[tBCEnd].xy.y += 8;

		tekiBulCol[tBCEnd].colFlag = flag;
		tekiBulCol[tBCEnd].size = size;
		break;
	case PLAYERBULLET:
		pBCEnd++;
		playerBulCol[pBCEnd].xy = xy;

		//�����蔻��̈ʒu��8���炷���ƂŒ������Đ^�񒆂ɂ���悤�ɂ��Ă邾��
		playerBulCol[pBCEnd].xy.x += 8;
		playerBulCol[pBCEnd].xy.y += 8;

		playerBulCol[pBCEnd].colFlag = flag;
		playerBulCol[pBCEnd].size = size;
		break;
	}
}

bool calc(COLLISION& a, COLLISION& b){
	if (a.size + b.size >= hypot(a.xy.x - b.xy.x, a.xy.y - b.xy.y))
		{
			return true;
		}
	return false;
}
//�R���W�����Փˌv�Z
void Collision(){
	for (int i = 0; i <= tBCEnd; i++){
		if (calc(playerCol, tekiBulCol[i])){
			*playerCol.colFlag = true;
			*tekiBulCol[i].colFlag = true;
		}
	}
	for (int i = 0; i <= pBCEnd; i++){
		if (calc(tekiCol, playerBulCol[i])){
			*playerBulCol[i].colFlag = true;
			*tekiCol.colFlag = true;
		}
	}
	if(calc(playerCol, tekiCol))*playerCol.colFlag = true;
	tBCEnd = 0;
	pBCEnd = 0;
}

