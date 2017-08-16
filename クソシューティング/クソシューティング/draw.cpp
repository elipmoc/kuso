#include "all.h"

DRAWCHAR drawChar[500];
int end = -1;//drawChar‚Ìg—p‚³‚ê‚Ä‚éƒƒ‚ƒŠ‚ÌÅŒã”ö
void SetChar(char* c, int x, int y){
	end++;
	drawChar[end].c = c;
	drawChar[end].x = x;
	drawChar[end].y = y;
}


void DrawChar(){
	//char d[50];
	//sprintf_s(d, "draw:%d", end);
	//DrawString(10, 30, d, GetColor(255, 255, 255));
	for (int i = 0; i <= end; i++){
		DrawString(drawChar[i].x, drawChar[i].y, drawChar[i].c, GetColor(255, 255, 255));
	}
	end = -1;
}
