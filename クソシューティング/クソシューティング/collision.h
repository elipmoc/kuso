typedef struct{
	XY xy;
	double size;
	bool* colFlag;//�Փ˂����� *colFlag=true�ɂȂ�
}COLLISION;

//�R���W�����Փˌv�Z
void Collision();
//�R���W�������Z�b�g
void SetCollision(XY xy, double size, bool* flag, KIND kind);