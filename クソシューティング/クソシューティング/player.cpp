#include "all.h"

	CHARA player;
	BARRAGE playerbar;//���@�e�Ǘ��\����
	char hp[30];//HP��\�����邽�߂̕�����
	//������-------------------------------------------------
	void InitPlayer(){
		player.xy.x = W / 2;
		player.xy.y = H - 20;
		player.speed = 5;
		player.hp = 5;
		BarrageSet(&playerbar, 50);//playerbar��������
	}

	//�I������--------------------------------------------------
	void EndPlayer(){
		Barrageremove(&playerbar);
	}


	//�v���C���[���X�V-----------------------------------------
	void Player(){
		if (player.hp <= 0){ ChangeScene(GAMEOVERSCENE);}
		player.addxy.x = 0;
		player.addxy.y = 0;
		//�ړ�-------------------------------------------
		if (Givekey(KEY_INPUT_UP) != 0)player.addxy.y = -1;
		if (Givekey(KEY_INPUT_DOWN) != 0)player.addxy.y = 1;
		if (Givekey(KEY_INPUT_LEFT) != 0)player.addxy.x = -1;
		if (Givekey(KEY_INPUT_RIGHT) != 0)player.addxy.x = 1;
		if (player.addxy.x!=0 ||player.addxy.y != 0){
			double distance = sqrt(player.addxy.x*player.addxy.x + player.addxy.y*player.addxy.y);
			player.xy.x += player.addxy.x / distance*player.speed;
			player.xy.y += player.addxy.y / distance*player.speed;
			if (player.xy.x > W - 16)player.xy.x = W - 16;
			if (player.xy.x < 0)player.xy.x =0;
			if (player.xy.y > H - 16)player.xy.y = H - 16;
			if (player.xy.y < 0)player.xy.y = 0;

		}
		//�V���b�g----------------------------------------
		if (Givekey(KEY_INPUT_Z) != 0)PlayerShot();

		//HP�\��------------------------------------------
		sprintf_s(hp, "HP:%d", player.hp);
		SetChar(hp, 10, 400);
		//�v���C���[�\��----------------------------------
		SetChar("��", player.xy.x, player.xy.y);
		if (player.colFlag){ player.colFlag = false; player.hp--; }
		SetCollision(player.xy, 3, &player.colFlag, PLAYER);
	}


	void PlayerShot(){
		static int count = 0;//�e�̔��˕p�x�𒲐�����p
		count++;
		if (count % 15 != 0)return;

		BULLET bullet[2];
		bullet[0].xy = player.xy;
		bullet[1].xy = player.xy;
		bullet[0].colFlag = false;
		bullet[1].colFlag = false;
		bullet[0].xy.x += 16;
		bullet[1].xy.x += -16;
		AddBullet(&playerbar, bullet[0]);
		AddBullet(&playerbar, bullet[1]);
	}

	//�v���C���[�e�����X�V-----------------------------------------
	void PlayerBarrage(){
		for (int i = 0; i <= playerbar.end; i++){
			playerbar.bu_p[i].xy.y -= 7;
			//�e���͈͊O�ɏo�������
			if (playerbar.bu_p[i].xy.y < 0 || playerbar.bu_p[i].colFlag==true){
				RemoveBullet(&playerbar, i);
				i--;
			}
			else{ SetChar("�e", playerbar.bu_p[i].xy.x, playerbar.bu_p[i].xy.y); 
			SetCollision(playerbar.bu_p[i].xy, 7, &playerbar.bu_p[i].colFlag, PLAYERBULLET);
			}
		}
	}


	XY GetPlayerXY(){
		return player.xy;
	}

	int GetPlayerHp(){
		return player.hp;
	}