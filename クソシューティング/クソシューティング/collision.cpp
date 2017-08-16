#include "all.h"
COLLISION playerCol;
COLLISION tekiCol;
COLLISION playerBulCol[100];
int pBCEnd = -1;
COLLISION tekiBulCol[200];
int tBCEnd = -1;

//コリジョンをセット
void SetCollision(XY xy, double size, bool* flag,KIND kind){
	switch (kind)
	{
	case PLAYER:
		playerCol.xy = xy;

		//当たり判定の位置を8ずらすことで調整して真ん中にくるようにしてるだけ
		playerCol.xy.x += 8;
		playerCol.xy.y += 8;

		playerCol.colFlag = flag;
		playerCol.size = size;
		break;
	case TEKI:
		tekiCol.xy = xy;

		//当たり判定の位置を8ずらすことで調整して真ん中にくるようにしてるだけ
		tekiCol.xy.x += 8;
		tekiCol.xy.y += 8;

		tekiCol.colFlag = flag;
		tekiCol.size = size;
		break;
	case TEKIBULLET:
		tBCEnd++;
		tekiBulCol[tBCEnd].xy = xy;

		//当たり判定の位置を8ずらすことで調整して真ん中にくるようにしてるだけ
		tekiBulCol[tBCEnd].xy.x += 8;
		tekiBulCol[tBCEnd].xy.y += 8;

		tekiBulCol[tBCEnd].colFlag = flag;
		tekiBulCol[tBCEnd].size = size;
		break;
	case PLAYERBULLET:
		pBCEnd++;
		playerBulCol[pBCEnd].xy = xy;

		//当たり判定の位置を8ずらすことで調整して真ん中にくるようにしてるだけ
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
//コリジョン衝突計算
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

