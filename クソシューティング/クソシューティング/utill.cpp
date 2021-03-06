#include "all.h"

//BARRAGEを初期化
void BarrageSet(BARRAGE* bar_p, int size){
	do{
		(*bar_p).bu_p = (BULLET*)malloc(sizeof(BULLET)*size);//BULLETメモリ確保
		
	} while ((*bar_p).bu_p==NULL);
	(*bar_p).end = -1;
}

//BARRAGEを開放
void Barrageremove(BARRAGE* bar_p){
	free((*bar_p).bu_p);//BULLETメモリ開放
}

//BARRAGEにBULLETを追加
void AddBullet(BARRAGE* bar_p, BULLET bu){
	(*bar_p).end++;
	(*bar_p).bu_p[(*bar_p).end] = bu;
}

//BARRAGEの,ある場所のBULLETを削除
void RemoveBullet(BARRAGE* bar_p, int i){
	(*bar_p).bu_p[i] = (*bar_p).bu_p[(*bar_p).end];
	(*bar_p).end--;
}