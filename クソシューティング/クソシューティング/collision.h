typedef struct{
	XY xy;
	double size;
	bool* colFlag;//衝突したら *colFlag=trueになる
}COLLISION;

//コリジョン衝突計算
void Collision();
//コリジョンをセット
void SetCollision(XY xy, double size, bool* flag, KIND kind);