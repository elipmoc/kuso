enum SOUND
{
	SHOT1_SE=0,
	TITLE_BGM,
	GAME_BGM,
	SUPEKA,
};

void Load();//�������������Ƀ��[�h
void BgmLoop();//bgm��r�؂�Ȃ��悤�ɊĎ�����
void PlaySe(SOUND);
void PlayBgm(SOUND);
void StopBgm();