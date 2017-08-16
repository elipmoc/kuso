#include "all.h"
int soundData[10];
int nowBgm=0;//現在のBGM

//音源をメモリにロード----------------------------------------
void Load(){
	soundData[SHOT1_SE] = LoadSoundMem("sound/shot1.wav");
	ChangeVolumeSoundMem(150, soundData[SHOT1_SE]);
	soundData[GAME_BGM] = LoadSoundMem("sound/batle.mp3");
	ChangeVolumeSoundMem(150, soundData[GAME_BGM]);
	soundData[SUPEKA] = LoadSoundMem("sound/スぺカ発動！.wav");
	ChangeVolumeSoundMem(200, soundData[SUPEKA]);
	soundData[TITLE_BGM] = LoadSoundMem("sound/title.mp3");
	ChangeVolumeSoundMem(255, soundData[TITLE_BGM]);
}

void PlaySe(SOUND s){

		PlaySoundMem(soundData[s], DX_PLAYTYPE_BACK, TRUE);
}

void PlayBgm(SOUND s){
	PlaySoundMem(soundData[s], DX_PLAYTYPE_BACK);
	nowBgm = soundData[s];
}

void StopBgm(){
	StopSoundMem(nowBgm);
	nowBgm = 0;
}

//bgmを途切れないように監視する
void BgmLoop(){
	if (CheckSoundMem(nowBgm) == 0){ PlaySoundMem(nowBgm, DX_PLAYTYPE_BACK); };
}