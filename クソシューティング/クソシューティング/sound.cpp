#include "all.h"
int soundData[10];
int nowBgm=0;//���݂�BGM

//�������������Ƀ��[�h----------------------------------------
void Load(){
	soundData[SHOT1_SE] = LoadSoundMem("sound/shot1.wav");
	ChangeVolumeSoundMem(150, soundData[SHOT1_SE]);
	soundData[GAME_BGM] = LoadSoundMem("sound/batle.mp3");
	ChangeVolumeSoundMem(150, soundData[GAME_BGM]);
	soundData[SUPEKA] = LoadSoundMem("sound/�X�؃J�����I.wav");
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

//bgm��r�؂�Ȃ��悤�ɊĎ�����
void BgmLoop(){
	if (CheckSoundMem(nowBgm) == 0){ PlaySoundMem(nowBgm, DX_PLAYTYPE_BACK); };
}