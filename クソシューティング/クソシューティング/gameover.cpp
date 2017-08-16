#include "all.h"

void GameOverScene(){
	SetChar("Ç∞-ÇﬁÇ®Å[ÇŒÅ[", 50, 50);
	if (Givekey(KEY_INPUT_RETURN) == 1)ChangeScene(TITLESCENE);
}