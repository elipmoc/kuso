enum SOUND
{
	SHOT1_SE=0,
	TITLE_BGM,
	GAME_BGM,
	SUPEKA,
};

void Load();//音源をメモリにロード
void BgmLoop();//bgmを途切れないように監視する
void PlaySe(SOUND);
void PlayBgm(SOUND);
void StopBgm();