#include "all.h"

void GameScene(){
	Player();
	PlayerBarrage();
	Teki();
	Collision();
}

void GameSceneInit() {
	StopBgm();
	PlayBgm(GAME_BGM); 
	InitPlayer();
	InitTeki();
}

void GameSceneEnd(){
	EndPlayer();
	EndTeki();
}