
//本来はこんな頭の悪いヘッダファイルは作っては行けない。
//必要なヘッダだけを読み込むべし
#include "all.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	//ウインドウとかの初期化
	SetMainWindowText("文字シューティング");
	SetGraphMode(500, 480,16);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	//音声データをあらかじめメモリにロードして高速化する
	Load();

	//使用するフォントの設定
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	//メインループ
	//Central()で実際のゲームの処理を行ってるよ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Central());

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}