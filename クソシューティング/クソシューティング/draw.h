typedef struct{
	char* c;
	int x;
	int y;
}DRAWCHAR;//描画する文字の情報を保持する構造体

void SetChar(char*,int x,int y);//描画する文字をセット
void DrawChar();//描画