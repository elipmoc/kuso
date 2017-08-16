#include "all.h"

//BARRAGE‚ğ‰Šú‰»
void BarrageSet(BARRAGE* bar_p, int size){
	do{
		(*bar_p).bu_p = (BULLET*)malloc(sizeof(BULLET)*size);//BULLETƒƒ‚ƒŠŠm•Û
		
	} while ((*bar_p).bu_p==NULL);
	(*bar_p).end = -1;
}

//BARRAGE‚ğŠJ•ú
void Barrageremove(BARRAGE* bar_p){
	free((*bar_p).bu_p);//BULLETƒƒ‚ƒŠŠJ•ú
}

//BARRAGE‚ÉBULLET‚ğ’Ç‰Á
void AddBullet(BARRAGE* bar_p, BULLET bu){
	(*bar_p).end++;
	(*bar_p).bu_p[(*bar_p).end] = bu;
}

//BARRAGE‚Ì,‚ ‚éêŠ‚ÌBULLET‚ğíœ
void RemoveBullet(BARRAGE* bar_p, int i){
	(*bar_p).bu_p[i] = (*bar_p).bu_p[(*bar_p).end];
	(*bar_p).end--;
}