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
	bool colFlag;//衝突フラグ
	int hp;
}CHARA;

typedef struct{
	XY xy;
	double angle;
	bool colFlag;//衝突フラグ
	double speed;
}BULLET;

typedef struct{
	BULLET* bu_p;
	int end;//使用されてるメモリの最高尾
}BARRAGE;

//BARRAGEを初期化
void BarrageSet(BARRAGE* bar_p, int size);
//BARRAGEを開放
void Barrageremove(BARRAGE* bar_p);
//BARRAGEにBULLETを追加
void AddBullet(BARRAGE* bar_p, BULLET bu);
//BARRAGEの,ある場所のBULLETを削除
void RemoveBullet(BARRAGE* bar_p,int i);