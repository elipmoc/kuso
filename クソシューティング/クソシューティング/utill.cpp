#include "all.h"

//BARRAGE��������
void BarrageSet(BARRAGE* bar_p, int size){
	do{
		(*bar_p).bu_p = (BULLET*)malloc(sizeof(BULLET)*size);//BULLET�������m��
		
	} while ((*bar_p).bu_p==NULL);
	(*bar_p).end = -1;
}

//BARRAGE���J��
void Barrageremove(BARRAGE* bar_p){
	free((*bar_p).bu_p);//BULLET�������J��
}

//BARRAGE��BULLET��ǉ�
void AddBullet(BARRAGE* bar_p, BULLET bu){
	(*bar_p).end++;
	(*bar_p).bu_p[(*bar_p).end] = bu;
}

//BARRAGE��,����ꏊ��BULLET���폜
void RemoveBullet(BARRAGE* bar_p, int i){
	(*bar_p).bu_p[i] = (*bar_p).bu_p[(*bar_p).end];
	(*bar_p).end--;
}