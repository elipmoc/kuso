#define W 500
#define H 480
#define PI 3.14159
enum KIND{
	PLAYER=0,
	TEKI,
	TEKIBULLET,
	PLAYERBULLET
};
typedef struct{
	double x;
	double y;
}XY;

typedef struct{
	XY xy;
	XY addxy;
	double speed;
	bool colFlag;//�Փ˃t���O
	int hp;
}CHARA;

typedef struct{
	XY xy;
	double angle;
	bool colFlag;//�Փ˃t���O
	double speed;
}BULLET;

typedef struct{
	BULLET* bu_p;
	int end;//�g�p����Ă郁�����̍ō���
}BARRAGE;

//BARRAGE��������
void BarrageSet(BARRAGE* bar_p, int size);
//BARRAGE���J��
void Barrageremove(BARRAGE* bar_p);
//BARRAGE��BULLET��ǉ�
void AddBullet(BARRAGE* bar_p, BULLET bu);
//BARRAGE��,����ꏊ��BULLET���폜
void RemoveBullet(BARRAGE* bar_p,int i);