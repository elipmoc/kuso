enum SOUND
{
	SHOT1_SE=0,
	TITLE_BGM,
	GAME_BGM,
	SUPEKA,
};

void Load();//‰¹Œ¹‚ðƒƒ‚ƒŠ‚Éƒ[ƒh
void BgmLoop();//bgm‚ð“rØ‚ê‚È‚¢‚æ‚¤‚ÉŠÄŽ‹‚·‚é
void PlaySe(SOUND);
void PlayBgm(SOUND);
void StopBgm();