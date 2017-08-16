#include "all.h"
CHARA teki;
BARRAGE tekibar;
int cont;
int beformode;//‘O‚Ì’e–‹‚ÌŽí—Þ
int mode;//Œ»Ý‚Ì’e–‹‚ÌŽí—Þ
//‰Šú‰»-----------------------------------------------------
void InitTeki(){
	beformode = 0;
	cont = 0;
	teki.xy.x = W/2;
	teki.xy.y = 30;
	teki.hp = 200;
	teki.speed=2;
	teki.addxy.x = teki.speed;
	BarrageSet(&tekibar, 500);//playerbar‚ð‰Šú‰»
}

//I—¹ˆ—--------------------------------------------------
void EndTeki(){
	Barrageremove(&tekibar);
}
void ModeCheck(){
	if (beformode != mode){ PlaySe(SUPEKA); cont = 0; beformode = mode; }
}
//“GXV----------------------------------------------------------
void Teki(){
	//DrawFormatString(10, 50, GetColor(255, 255, 255),"%d",teki.hp);
	if (teki.colFlag){ teki.hp--; teki.colFlag = false; }
	//ˆÚ“®------------------------------------
	teki.xy.x += teki.addxy.x;
	if (teki.xy.x > W - 16 || teki.xy.x < 0)teki.addxy.x *= -1;
	//“G•\Ž¦----------------------------------
	SetChar("“G", teki.xy.x, teki.xy.y);
	SetCollision(teki.xy, 7, &teki.colFlag, TEKI);
	TekiBulletDie();
	if (teki.hp > 180){ TekiBarrage1(); mode = 0; }
	else if (teki.hp > 160){ mode = 1; ModeCheck(); TekiBarrage2(); }
	else if (teki.hp > 150){ mode = 2; ModeCheck(); TekiBarrage3(); }
	else if (teki.hp > 145){  mode = 3; ModeCheck();TekiBarrage4(); }
	else if (teki.hp > 125){  mode = 4; ModeCheck();TekiBarrage5(); }
	else if (teki.hp > 105){  mode = 5; ModeCheck();TekiBarrage6(); }
	else { mode = 6; ModeCheck(); TekiBarrage7(); }
	TekiBulletMove();
}

void TekiBulletDie(){
	for (int i = 0; i <= tekibar.end; i++){
		//’e‚ª”ÍˆÍŠO‚Éo‚½‚ç||Ž©‹@‚ÆÕ“Ë‚µ‚½‚ç@Á‚·
		if (tekibar.bu_p[i].xy.x >W || tekibar.bu_p[i].xy.x <-16 || tekibar.bu_p[i].xy.y > H || tekibar.bu_p[i].xy.y <-16 || tekibar.bu_p[i].colFlag == true){
			RemoveBullet(&tekibar, i);
			i--;
		}
	}
}

void TekiBulletMove(){
	for (int i = 0; i <= tekibar.end; i++){
		tekibar.bu_p[i].xy.y += sin(tekibar.bu_p[i].angle / 180 * PI)*tekibar.bu_p[i].speed;
		tekibar.bu_p[i].xy.x += cos(tekibar.bu_p[i].angle / 180 * PI)*tekibar.bu_p[i].speed;
		SetChar("’e", tekibar.bu_p[i].xy.x, tekibar.bu_p[i].xy.y);
		SetCollision(tekibar.bu_p[i].xy, 7, &tekibar.bu_p[i].colFlag, TEKIBULLET);
	}
}

void TekiBarrage1(){
	cont++;
	if (cont % 20 == 0){
		PlaySe(SHOT1_SE);
		BULLET b;
		b.colFlag = false;
		b.xy = teki.xy;
		b.angle = 90;
		b.speed = 7;
		AddBullet(&tekibar, b);
	}
}

void TekiBarrage2(){
	cont++;
	if (cont % 28 == 0){
		PlaySe(SHOT1_SE);
		BULLET b[3];
		b[0].angle = 90;
		b[1].angle = 120;
		b[2].angle = 60;
		b[0].speed = 2.5;
		b[1].speed = 2.5;
		b[2].speed = 2.5;
		for (int i = 0; i < 3; i++){
			b[i].colFlag = false;
			b[i].xy = teki.xy;
			AddBullet(&tekibar, b[i]);
		}
	}
}

void TekiBarrage3(){
	cont++;
	if (cont % 40 == 0){
		for (int i = 0; i <= tekibar.end; i++){
			XY p = GetPlayerXY();
			tekibar.bu_p[i].speed = 1;
			tekibar.bu_p[i].angle= (atan2(p.y - tekibar.bu_p[i].xy.y, p.x - tekibar.bu_p[i].xy.x)*180)/PI;
		}
	}
}

void TekiBarrage4(){
	if (cont == 0){
		cont++;
		for (int i = 0; i <= tekibar.end; i++){
			tekibar.bu_p[i].angle = i * 20;
			tekibar.bu_p[i].speed = 2;
		}
	}
}

void TekiBarrage5(){
	static int cont2=0;
	if (cont == 0){
		for (;-1!= tekibar.end;){
			RemoveBullet(&tekibar, tekibar.end);
		}
	}
	cont++;
	if (cont % 25 == 0){
		BULLET b;
		if (GetRand(1) == 0){ b.xy.x = 0; b.angle = 0; }
		else { b.xy.x = W; b.angle = 180;}
		b.speed = 1;
		b.xy.y = GetRand(H-16-50)+50;
		AddBullet(&tekibar,b);
	}
	if (cont % 10 == 0){
		PlaySe(SHOT1_SE);
		cont2++;
		BULLET b[2];
		b[0].speed = 2.5;
		b[1].speed = 2.5;
		b[0].angle = cont2 * 10;
		b[0].xy = teki.xy;
		b[1].angle = cont2 * 10+180;
		b[1].xy = teki.xy;
		AddBullet(&tekibar, b[0]);
		AddBullet(&tekibar, b[1]);
	}
}

void TekiBarrage6(){
	cont++;
	if (cont < 300 && cont % 12 == 0){
		PlaySe(SHOT1_SE);
		for (int i = 0; i < 9; ++i){
			BULLET b;
			b.angle = (i)* 40 + GetRand(39);
			b.xy = teki.xy;
			b.speed = GetRand(10)/10 + 2;//‘¬‚³ƒZƒbƒg
			AddBullet(&tekibar, b);
		}
	}
	if (cont == 300){
		for (int i = 0; i <= tekibar.end; i++){
			tekibar.bu_p[i].speed = 0;
		}
	}

	if (cont == 450){
		for (int i = 0; i <= tekibar.end; i++){
			tekibar.bu_p[i].speed = 0;
			tekibar.bu_p[i].angle=GetRand(359);
		}
	}
	if (cont >= 450){
		for (int i = 0; i <= tekibar.end; i++){
			tekibar.bu_p[i].speed += 0.014;
		}
	}
	if (cont == 600){
		cont = 0;
	}

	if (cont > 350 && cont<450 && cont % 3 == 0){
		PlaySe(SHOT1_SE);
		BULLET b;
		b.xy = teki.xy;
		XY p = GetPlayerXY();
		b.angle = atan2(p.y - b.xy.y, p.x - b.xy.x) * 180 / PI;
		b.speed = 6;//‘¬‚³ƒZƒbƒg
		AddBullet(&tekibar, b);
	}
}

void TekiBarrage7(){
	if (cont == 0){
		teki.addxy.x = 0;
		teki.xy.x = -500;
		for (int i = 0; i <= tekibar.end; i++){
			tekibar.bu_p[i].speed = 2;
			tekibar.bu_p[i].angle = 270+GetRand(20)-15;
		}
	}
	cont++;
	if (cont>400) ChangeScene(CLEARSCENE);
	for (int i = 0; i <= tekibar.end; i++){
		tekibar.bu_p[i].speed -= 0.02;
	}
}