#include <Novice.h>
#include <player.h>
#include <Enemy.h>
#include <Struct.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>
#include<stdlib.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector2 ppos = { 1000 ,320 };
	int pspeed = 10;

	Vector2 pos = { 10,360 };
	Vector2 gspeed = { 0,0 };

	Player* player = new Player(ppos, pspeed, 10);

	player->SetPosition(ppos);
	player->SetSpeed(pspeed);


	Enemy* spaodar = new Enemy(pos, gspeed, 5);

	spaodar->SetPosition(pos);
	spaodar->SetSpeed(gspeed);

	Enemy* nezumi = new Enemy(pos, gspeed, 5);

	nezumi->SetPosition(pos);
	nezumi->SetSpeed(gspeed);

	Enemy* hae = new Enemy(pos, gspeed, 5);

	hae->SetPosition(pos);
	hae->SetSpeed(gspeed);

	Enemy* goki = new Enemy(pos, gspeed, 5);

	goki->SetPosition(pos);
	goki->SetSpeed(gspeed);

	int eneposX = goki->GetSpeedX();
	int eneposY = goki->GetSpeedX();
	int speed2 = goki->GetSpeedX();

	int playerposX = 10;
	int playerposY = 360;
	int speed = 10;

	Scean scean = Start;

	int cX[100] = { -50 };
	int	cY[100] = { -50 };

	int pointposX = -600;
	int pointposY = 200;

	int pointr = 0;
	int pointa = 0;
	int point[24] = { 0 };
	int r = 0;
	int a = 0;
	int kyori2 = 0;
	int me = 0;
	int n = 0;

	int batuttoriFlag = 0;

	unsigned int Time = (int)time(nullptr);
	srand(Time);


	int wid = 400;
	int hit = 800;

	int k = 0;
	bool blackFlag = false;

	int number = 0;

	const float kLefttopX = -wid / 2.0f;
	const float kLefttopY = -hit / 2.0f;
	const float kRigthtopX = wid / 2.0f;
	const float kRigthtopY = -hit / 2.0f;
	const float kLeftXdown = -wid / 2.0f;
	const float kLeftYdown = hit / 2.0f;
	const float kRigthXdown = wid / 2.0f;
	const float kRigthYdown = hit / 2.0f;

	float theta = 0.0f;
	float theta2 = 0.0f;

	int white = Novice::LoadTexture("white1x1.png");

	int haikeiposX = 0;

	int randspeed = 0;
	float randspeeds[5] = { 0.25,0.5,1,1.5,2 };

	float tamaspeedX[300];
	float tamaspeedY[300];
	int kyori[300];

	int batutori[3];
	int ootori[3];
	int sinnpanndori[3];

	int resultS[9];
	int resultA[9];
	int resultB[9];
	int resultC[9];
	int resultD[9];

	float yure = 50.0f;

	int respon = 0;
	int tamakann = 5000;
	int tamakann2 = 1000;
	int tama2 = 5000;


	int playerR = 15;
	int eneR = 40;

	int kaihuku = 0;


	bool deadFlag = false;
	bool enedeadFlag = false;
	///bool badFlag = false;

	bool bulletFlag[300];

	bool enemybulletFlag[300];
	bool enemybullet2Flag[300];
	bool enemybullet3Flag[300];

	bool eyeFlag = false;

	float eX[300] = { -50 };
	float eY[300] = { -50 };


	float eX2[300] = { -50 };
	float eY2[300] = { -50 };

	float eX3[300] = { -50 };
	float eY3[300] = { -50 };

	int life = 10000;
	int enelife = 2000;
	int elife = enelife;
	int plife = life;
	int relife = 0;

	int sinpanClock = 600;
	int speedClocl = 600;
	bool sinpanFlag = false;
	bool rabitFlag = false;

	int bgmhandlle = -1;
	int bgmhandlle1 = -1;
	int bgmhandlle2 = -1;
	int bgmhandlle3 = -1;
	int bgmhandlle4 = -1;
	int sehandlle = -1;

	int playertama = -1;
	int tama = -1;
	int binar;
	int lifebar[9];
	int playerlifebar[9];
	int gate[3];

	int blacktale[30];
	int kiri[10];
	int hasira;
	int eye;

	int eachnumber[6] = {};
	int cell[11];
	int playernumbers[6] = {};
	int playercell[11];


	int koukan = 0;

	for (int i = 0; i < 300; i++) {
		tamaspeedX[i] = 0;
		tamaspeedY[i] = 0;
		kyori[i] = 0;
		bulletFlag[i] = true;
		enemybulletFlag[i] = true;
		enemybullet2Flag[i] = true;
		enemybullet3Flag[i] = true;
	}

#pragma region  Image

	binar = Novice::LoadTexture("./kuroimori.png");
	lifebar[0] = Novice::LoadTexture("./image/lifebar0.png");
	lifebar[1] = Novice::LoadTexture("./image/lifebar1.png");
	lifebar[2] = Novice::LoadTexture("./image/lifebar2.png");
	lifebar[3] = Novice::LoadTexture("./image/lifebar3.png");
	lifebar[4] = Novice::LoadTexture("./image/lifebar4.png");
	lifebar[5] = Novice::LoadTexture("./image/lifebar5.png");
	lifebar[6] = Novice::LoadTexture("./image/lifebar6.png");
	lifebar[7] = Novice::LoadTexture("./image/lifebar7.png");
	lifebar[8] = Novice::LoadTexture("./image/lifebar8.png");

	playerlifebar[0] = Novice::LoadTexture("./image/playerlifebar0.png");
	playerlifebar[1] = Novice::LoadTexture("./image/playerlifebar1.png");
	playerlifebar[2] = Novice::LoadTexture("./image/playerlifebar2.png");
	playerlifebar[3] = Novice::LoadTexture("./image/playerlifebar3.png");
	playerlifebar[4] = Novice::LoadTexture("./image/playerlifebar4.png");
	playerlifebar[5] = Novice::LoadTexture("./image/playerlifebar5.png");
	playerlifebar[6] = Novice::LoadTexture("./image/playerlifebar6.png");
	playerlifebar[7] = Novice::LoadTexture("./image/playerlifebar7.png");
	playerlifebar[8] = Novice::LoadTexture("./image/playerlifebar8.png");

	gate[0] = Novice::LoadTexture("./image/gate01.png");
	gate[1] = Novice::LoadTexture("./image/gate02.png");
	gate[2] = Novice::LoadTexture("./image/gate03.png");



	blacktale[0] = Novice::LoadTexture("./image/blacktale1.png");
	blacktale[1] = Novice::LoadTexture("./image/blacktale2.png");
	blacktale[2] = Novice::LoadTexture("./image/blacktale3.png");

	blacktale[3] = Novice::LoadTexture("./image/blacktale5.png");
	blacktale[4] = Novice::LoadTexture("./image/blacktale6.png");
	blacktale[5] = Novice::LoadTexture("./image/blacktale7.png");
	blacktale[6] = Novice::LoadTexture("./image/blacktale8.png");

	blacktale[7] = Novice::LoadTexture("./image/blacktale10.png");
	blacktale[8] = Novice::LoadTexture("./image/blacktale11.png");
	blacktale[9] = Novice::LoadTexture("./image/blacktale12.png");
	blacktale[10] = Novice::LoadTexture("./image/blacktale13.png");
	blacktale[11] = Novice::LoadTexture("./image/blacktale14.png");

	blacktale[12] = Novice::LoadTexture("./image/blacktale16.png");
	blacktale[13] = Novice::LoadTexture("./image/blacktale17.png");
	blacktale[14] = Novice::LoadTexture("./image/blacktale18.png");
	blacktale[15] = Novice::LoadTexture("./image/blacktale19.png");
	blacktale[16] = Novice::LoadTexture("./image/blacktale20.png");

	blacktale[17] = Novice::LoadTexture("./image/blacktale22.png");
	blacktale[18] = Novice::LoadTexture("./image/blacktale23.png");
	blacktale[19] = Novice::LoadTexture("./image/blacktale24.png");
	blacktale[20] = Novice::LoadTexture("./image/blacktale25.png");
	blacktale[21] = Novice::LoadTexture("./image/blacktale26.png");
	blacktale[22] = Novice::LoadTexture("./image/blacktale27.png");

	blacktale[23] = Novice::LoadTexture("./image/blacktale29.png");
	blacktale[24] = Novice::LoadTexture("./image/blacktale30.png");

	kiri[0] = Novice::LoadTexture("./image/kiri1.png");
	kiri[1] = Novice::LoadTexture("./image/kiri2.png");
	kiri[2] = Novice::LoadTexture("./image/kiri3.png");
	kiri[3] = Novice::LoadTexture("./image/kiri4.png");
	kiri[4] = Novice::LoadTexture("./image/kiri5.png");
	kiri[5] = Novice::LoadTexture("./image/kiri6.png");
	kiri[6] = Novice::LoadTexture("./image/kiri7.png");
	kiri[7] = Novice::LoadTexture("./image/kiri8.png");
	kiri[8] = Novice::LoadTexture("./image/kiri9.png");

	cell[0] = Novice::LoadTexture("./image/number0.png");
	cell[1] = Novice::LoadTexture("./image/number1.png");
	cell[2] = Novice::LoadTexture("./image/number2.png");
	cell[3] = Novice::LoadTexture("./image/number3.png");
	cell[4] = Novice::LoadTexture("./image/number4.png");
	cell[5] = Novice::LoadTexture("./image/number5.png");
	cell[6] = Novice::LoadTexture("./image/number6.png");
	cell[7] = Novice::LoadTexture("./image/number7.png");
	cell[8] = Novice::LoadTexture("./image/number8.png");
	cell[9] = Novice::LoadTexture("./image/number9.png");

	playercell[0] = Novice::LoadTexture("./image/number0.png");
	playercell[1] = Novice::LoadTexture("./image/number1.png");
	playercell[2] = Novice::LoadTexture("./image/number2.png");
	playercell[3] = Novice::LoadTexture("./image/number3.png");
	playercell[4] = Novice::LoadTexture("./image/number4.png");
	playercell[5] = Novice::LoadTexture("./image/number5.png");
	playercell[6] = Novice::LoadTexture("./image/number6.png");
	playercell[7] = Novice::LoadTexture("./image/number7.png");
	playercell[8] = Novice::LoadTexture("./image/number8.png");
	playercell[9] = Novice::LoadTexture("./image/number9.png");

	resultS[0] = Novice::LoadTexture("./image/reselt-S01.png");
	resultS[1] = Novice::LoadTexture("./image/reselt-S02.png");
	resultS[2] = Novice::LoadTexture("./image/reselt-S03.png");
	resultS[3] = Novice::LoadTexture("./image/reselt-S04.png");
	resultS[4] = Novice::LoadTexture("./image/reselt-S05.png");
	resultS[5] = Novice::LoadTexture("./image/reselt-S06.png");
	resultS[6] = Novice::LoadTexture("./image/reselt-S07.png");

	resultA[0] = Novice::LoadTexture("./image/reselt-A01.png");
	resultA[1] = Novice::LoadTexture("./image/reselt-A02.png");
	resultA[2] = Novice::LoadTexture("./image/reselt-A03.png");
	resultA[3] = Novice::LoadTexture("./image/reselt-A04.png");
	resultA[4] = Novice::LoadTexture("./image/reselt-A05.png");
	resultA[5] = Novice::LoadTexture("./image/reselt-A06.png");
	resultA[6] = Novice::LoadTexture("./image/reselt-A07.png");

	resultB[0] = Novice::LoadTexture("./image/reselt-B01.png");
	resultB[1] = Novice::LoadTexture("./image/reselt-B02.png");
	resultB[2] = Novice::LoadTexture("./image/reselt-B03.png");
	resultB[3] = Novice::LoadTexture("./image/reselt-B04.png");
	resultB[4] = Novice::LoadTexture("./image/reselt-B05.png");
	resultB[5] = Novice::LoadTexture("./image/reselt-B06.png");
	resultB[6] = Novice::LoadTexture("./image/reselt-B07.png");

	resultC[0] = Novice::LoadTexture("./image/reselt-C01.png");
	resultC[1] = Novice::LoadTexture("./image/reselt-C02.png");
	resultC[2] = Novice::LoadTexture("./image/reselt-C03.png");
	resultC[3] = Novice::LoadTexture("./image/reselt-C04.png");
	resultC[4] = Novice::LoadTexture("./image/reselt-C05.png");
	resultC[5] = Novice::LoadTexture("./image/reselt-C06.png");
	resultC[6] = Novice::LoadTexture("./image/reselt-C07.png");

	resultD[0] = Novice::LoadTexture("./image/reselt-D01.png");
	resultD[1] = Novice::LoadTexture("./image/reselt-D02.png");
	resultD[2] = Novice::LoadTexture("./image/reselt-D03.png");
	resultD[3] = Novice::LoadTexture("./image/reselt-D04.png");
	resultD[4] = Novice::LoadTexture("./image/reselt-D05.png");
	resultD[5] = Novice::LoadTexture("./image/reselt-D06.png");
	resultD[6] = Novice::LoadTexture("./image/reselt-D07.png");


	int player_Texture = Novice::LoadTexture("./image/player.png");

	hasira = Novice::LoadTexture("./image/hasira.png");

	int tori = Novice::LoadTexture("./image/barid.png");

	eye = Novice::LoadTexture("./image/kumonosu.png");

	int title = Novice::LoadTexture("./image/title.png");
	int UI = Novice::LoadTexture("./image/UI1.png");
	int replaye = Novice::LoadTexture("./image/REPLAY.png");



	batutori[0] = Novice::LoadTexture("./image/1bosu1.png");
	batutori[1] = Novice::LoadTexture("./image/1bosu2.png");

	ootori[0] = Novice::LoadTexture("./image/2bosu1.png");
	ootori[1] = Novice::LoadTexture("./image/2bosu2.png");

	sinnpanndori[0] = Novice::LoadTexture("./image/3bosu1.png");
	sinnpanndori[1] = Novice::LoadTexture("./image/3bosu2.png");

	int syuumatudori = Novice::LoadTexture("./image/lastbosu.png");

	int startbgm = Novice::LoadAudio("./Sound/wing.wav");
	int bgm1 = Novice::LoadAudio("./Sound/bina1.wav");
	int bgm2 = Novice::LoadAudio("./Sound/bina2.wav");
	int bgm3 = Novice::LoadAudio("./Sound/bina3.wav");
	int bgm4 = Novice::LoadAudio("./Sound/tyouritu.wav");
	int tin = Novice::LoadAudio("./Sound/tin.wav");



#pragma endregion


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		haikeiposX++;

		playerposX = player->GetPosX();
		playerposY = player->GetPosY();
		speed = player->GetSpeed();


		if (keys[DIK_T] && preKeys[DIK_T] != 0) {
			batuttoriFlag = 0;
			life = 10000;
			enelife = 750;
			randspeeds[2] = { 1 };


			scean = tale01;
		}
		if (keys[DIK_R] && preKeys[DIK_R] != 0) {
			batutori[0] = Novice::LoadTexture("./image/badtori1.png");
			Novice::DrawBox(0, 0, 1280, 720, 0.0, WHITE, kFillModeSolid);
			life = 10000;
			enelife = 500;
			rabitFlag = true;
		}


		if (haikeiposX >= 1280) {
			haikeiposX = 0;
		}
		r = (rand() % 640);
		a = (rand() % 640);

		randspeed = (rand() % 4);

		if (tama > -1) {
			tama--;
		}
		if (playertama > -1) {
			playertama--;
		}

		if (koukan == 120) {
			for (int i = 0; i < 300; i++) {
				bulletFlag[i] = false;
				enemybulletFlag[i] = false;
				enemybullet2Flag[i] = false;
			}
		}
		if (keys[DIK_SPACE]) {
			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == false && playertama < 0) {
					cX[i] = playerposX;
					cY[i] = playerposY;
					bulletFlag[i] = true;
					playertama = 10;
				}
			}

		}

		if (life >= 0) {
			player->Move(keys);

		}
		else if (respon > 100) {
			playerposX = 500;
			playerposY = 500;
		}

		/// X座標画面端処理
		if (playerposX < 30) {
			playerposX = 30;
		}
		else if (playerposX + 102 > 1250) {
			playerposX = 1250 - 102;
		}


		///Y座標画端橋処理
		if (playerposY < 100) {
			playerposY = 100;
		}
		else if (playerposY + 102 > 590) {
			playerposY = 590 - 102;
		}


		///敵座標

		///当たり判定
		if (deadFlag == false && eneR * eneR >= (playerposX - eneposX) * (playerposX - eneposX) + (playerposY - eneposY) * (playerposY - eneposY)) {
			life = 10;
			respon = 0;
		}
		for (int i = 0; i < 100; i++) {
			if (scean != resalt && enedeadFlag == false && enelife > 0 && eneR * eneR >= (eneposX - cX[i]) * (eneposX - cX[i]) + (eneposY - cY[i]) * (eneposY - cY[i])) {
				enelife -= 5;

			}
		}

		for (int i = 0; i < 300; i++) {
			if (scean != resalt && scean != End && scean != makann3 && scean != makann2 && scean != tale04 && scean != makann && scean != Start && scean != kirikae &&
				deadFlag == false && playerR * playerR >= (playerposX - eX[i]) * (playerposX - eX[i]) + (playerposY - eY[i]) * (playerposY - eY[i])) {
				life -= 3;

			}
			if (scean != resalt && scean != End && scean != makann3 && scean != makann2 && scean != tale04 && scean != makann && scean != Start && scean != kirikae &&
				deadFlag == false && playerR * playerR >= (playerposX - eX2[i]) * (playerposX - eX2[i]) + (playerposY - eY2[i]) * (playerposY - eY2[i])) {
				if (scean == Stage01 || scean == Stage02) {
					life -= 3;
				}
				else if (scean == Stage03) {
					life -= 6;
				}

			}
		}

		///弾が動く
		if (life >= 0) {
			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == true) {
					cX[i] -= 15;
					if (cX[i] < 0) {
						bulletFlag[i] = false;
						cX[i] = -500;
						cY[i] = -500;
					}
				}
			}
		}



		theta += (1.0f / 8.0f * (float)M_PI) * 3;
		theta2 += float(M_PI) / 30.0f;

		if (n >= 600) {
			me = 0;
			n = 0;
			pointr = r;
			pointa = a;
			kyori2 = (int)(sqrt((playerposX - pointr) * (playerposX - pointr) + (playerposY - pointa) * (playerposY - pointa)));

			for (int i = 0; i < 12; i++) {
				point[i] = rand() % 1000;
				point[i + 12] = rand() % 640;
			}

			eyeFlag = false;
		}
		n++;


		float lefttopX = kLefttopX * cosf(theta) - kLefttopY * sinf(theta);

		float lefttopY = kLefttopY * cosf(theta) + kLefttopX * sinf(theta);

		float RigthtopX = kRigthtopX * cosf(theta) - kRigthtopY * sinf(theta);

		float RigthtopY = kRigthtopY * cosf(theta) + kRigthtopX * sinf(theta);

		float leftdownX = kLeftXdown * cosf(theta) - kLeftYdown * sinf(theta);

		float leftdownY = kLeftYdown * cosf(theta) + kLeftXdown * sinf(theta);

		float RigthdownX = kRigthXdown * cosf(theta) - kRigthYdown * sinf(theta);

		float RigthdownY = kRigthYdown * cosf(theta) + kRigthXdown * sinf(theta);

		float leftpostopX = lefttopX + pointposX;
		float leftpostopY = lefttopY + pointposY;
		float rigthpostopX = RigthtopX + pointposX;
		float rigthpostopY = RigthtopY + pointposY;
		float leftposdownX = leftdownX + pointposX;
		float leftposdownY = leftdownY + pointposY;
		float rigthposdownX = RigthdownX + pointposX;
		float rigthposdownY = RigthdownY + pointposY;

		for (int i = 0; i < 300; i++) {
			if (enemybulletFlag[i] == false && tama <= 0) {
				eX[i] = leftpostopX;
				eY[i] = leftpostopY;
				enemybulletFlag[i] = true;

				tama = tamakann2;
			}
			if (tama > -1) {
				tama--;
			}
			if (enemybulletFlag[i] == true) {
				eX[i] += (int)(speed * randspeeds[2]);


				if (eX[i] > 1280) {
					enemybulletFlag[i] = false;
				}
			}

		}

		if (scean == Stage01 || scean == Stage04) {
			for (int i = 0; i < 300; i++) {
				if (enemybullet2Flag[i] == false && tama <= 0) {
					eX2[i] = (float)(eneposX);
					eY2[i] = (float)(eneposY);
					enemybullet2Flag[i] = true;


					kyori[i] = (int)(sqrt((playerposX - eX2[i]) * (playerposX - eX2[i]) + (playerposY - eY2[i]) * (playerposY - eY2[i])));
					tamaspeedX[i] = (float)((playerposX - eX2[i]) / kyori[i]);
					tamaspeedY[i] = (float)((playerposY - eY2[i]) / kyori[i]);


					tama = tamakann;
				}
				if (tama > -1) {
					tama--;
				}
			}
		}


		for (int i = 0; i < 300; i++) {
			if (enemybullet2Flag[i] == true) {
				eX2[i] += (int)(tamaspeedX[i] * speed2);
				eY2[i] += (int)(tamaspeedY[i] * speed2);


				if (eX2[i] > 1280) {
					enemybullet2Flag[i] = false;
				}
			}

		}


		for (int i = 0; i < 300; i++) {
			if (enemybullet3Flag[i] == false && tama2 <= 0) {
				eX3[i] = (float)(eneposX);
				eY3[i] = (float)(eneposY);
				enemybullet3Flag[i] = true;


				kyori[i] = (int)(sqrt((playerposX - eX3[i]) * (playerposX - eX3[i]) + (playerposY - eY3[i]) * (playerposY - eY3[i])));
				tamaspeedX[i] = (float)((playerposX - eX3[i]) / kyori[i]);
				tamaspeedY[i] = (float)((playerposY - eY3[i]) / kyori[i]);


				tama2 = tamakann * 5;
			}
			if (tama2 > -1) {
				tama2--;
			}
		}

		sinpanClock--;

		if (sinpanClock <= 0 && scean == Stage03) {
			if (life >= 100) {
				life = (int)(life * 0.675 - 50);
			}
			else if (life < 100) {
				life -= 100;
			}
			sinpanFlag = true;
			sinnpanndori[0] = sinnpanndori[1];
			sinpanClock = 600;
		}
		else if (sinpanClock <= 0 && scean == Stage04) {
			life = (int)(life * 0.9) - 50;
			sinpanFlag = true;
			sinpanClock = 600;
		}

		speedClocl--;
		if (speedClocl <= 0 && (scean == Stage03 || scean == Stage04)) {
			randspeeds[2] = randspeeds[randspeed];

			speedClocl = 600;
		}


		if (life <= 0) {
			Novice::DrawSprite(320, 50, replaye, 1, 1, 0.0, WHITE);
		}
		if (!keys[DIK_K] && preKeys[DIK_K] != 0 && kaihuku < 20) {
			for (int i = 0; i < 300; i++) {
				life++;

			}
			kaihuku++;
		}
		if (!(keys[DIK_RSHIFT] || !keys[DIK_LSHIFT]) && preKeys[DIK_RETURN] && (preKeys[DIK_RSHIFT] || !preKeys[DIK_LSHIFT])) {
			life++;
			relife++;
		}
		if (enelife > 0) {
			number = enelife + 1;
			eachnumber[0] = number / 10000;
			number = number % 10000;

			eachnumber[1] = number / 1000;
			number = number % 1000;

			eachnumber[2] = number / 100;
			number = number % 100;

			eachnumber[3] = number / 10;
			number = number % 10;

			eachnumber[4] = number;
		}

		if (life > 0) {
			int playernumber = life;
			playernumbers[0] = playernumber / 10000;
			playernumber = playernumber % 10000;

			playernumbers[1] = playernumber / 1000;
			playernumber = playernumber % 1000;

			playernumbers[2] = playernumber / 100;
			playernumber = playernumber % 100;

			playernumbers[3] = playernumber / 10;
			playernumber = playernumber % 10;

			playernumbers[4] = playernumber;
		}
		else if (life <= 0) {
			playernumbers[0] = 0;
			playernumbers[1] = 0;
			playernumbers[2] = 0;
			playernumbers[3] = 0;
			playernumbers[4] = 0;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scean)
		{
		case Start:
			Novice::StopAudio(bgmhandlle3);
			if (Novice::IsPlayingAudio(bgmhandlle) == 0 || bgmhandlle == -1) {
				bgmhandlle = Novice::PlayAudio(startbgm, true, 0.0f);

			}
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
				Novice::DrawSprite(300, 100, title, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(0, 0, binar, 1, 1, 0.0f, WHITE);
				scean = kirikae;
				break;
			}
			Novice::DrawSprite(0, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(00, 00, title, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(0, 0, gate[0], 0.125, 0.125, 0.0f, WHITE);
			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);

			break;
		case kirikae:
			Novice::DrawSprite(0, 0, binar, 1, 1, 0.0f, WHITE);
			if (koukan >= 90) {
				koukan = 0;
				scean = Stage01;

			}
			else if (koukan >= 60) {
				Novice::DrawSprite(0, 0, gate[2], 0.125, 0.125, 0.0f, WHITE);
			}
			else if (koukan >= 30) {
				Novice::DrawSprite(0, 0, gate[1], 0.125, 0.125, 0.0f, WHITE);
			}
			else if (koukan >= 0) {
				Novice::DrawSprite(0, 0, gate[0], 0.125, 0.125, 0.0f, WHITE);
			}

			Novice::DrawSprite(-400, -400, title, 1, 1, 0.0f, WHITE);

			koukan++;
			break;
		case tale000:

			if (koukan >= 240) {
				scean = tale01;
			}
			else if (koukan >= 120) {



			}

			koukan++;
			break;
		case tale01:
			if (koukan >= 450) {
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
					k = 0;
					blackFlag = false;
				}
			}

			if (k < 241) {
				k++;
			}
			else if (k >= 241) {

				eneposX = 10;
				eneposY = 360;

				pointposX = -600;
				pointposY = 200;

				wid = 400;
				hit = 800;

				k = 0;
				blackFlag = false;

				theta = 0.0f;
				theta2 = 0.0f;

				randspeeds[2] = { 1 };
				tamakann2 = 2000;

				white = Novice::LoadTexture("white1x1.png");

				haikeiposX = 0;

				speed = 10;

				speed2 = 20;

				life = life + 200;

				yure = 50.0f;

				respon = 0;
				tamakann = 2000;

				deadFlag = false;
				enedeadFlag = false;

				for (int i = 0; i < 300; i++) {
					tamaspeedX[i] = 0;
					tamaspeedY[i] = 0;
					kyori[i] = 0;
					bulletFlag[i] = true;
					enemybulletFlag[i] = true;
					enemybullet2Flag[i] = true;
					enemybullet3Flag[i] = true;
				}
				enelife = 750;
				elife = enelife;
				blackFlag = true;
				koukan = 0;
				scean = Stage01;

			}

			if (blackFlag == false) {
				Novice::DrawSprite(0, 0, blacktale[k / 10], 1, 1, 0.0, WHITE);
			}
			///Novice::DrawSprite(0, 0, tale[1], 1, 1, 0.0f, WHITE);
			koukan++;
			break;
		case Stage01:
			if (k < 241) {
				k++;
			}
			else if (k == 241) {

				eneposX = 10;
				eneposY = 360;

				pointposX = -600;
				pointposY = 200;

				wid = 400;
				hit = 800;


				blackFlag = false;

				theta = 0.0f;
				theta2 = 0.0f;

				randspeeds[2] = { 1 };
				tamakann2 = 2000;

				white = Novice::LoadTexture("white1x1.png");

				haikeiposX = 0;

				speed = 10;

				speed2 = 20;

				life = life + 200;

				yure = 50.0f;

				respon = 0;
				tamakann = 2000;

				deadFlag = false;
				enedeadFlag = false;

				for (int i = 0; i < 300; i++) {
					tamaspeedX[i] = 0;
					tamaspeedY[i] = 0;
					kyori[i] = 0;
					bulletFlag[i] = true;
					enemybulletFlag[i] = true;
					enemybullet2Flag[i] = true;
					enemybullet3Flag[i] = true;
				}
				enelife = 750;
				elife = enelife;
				blackFlag = true;
				koukan = 0;
				k++;
			}
			Novice::StopAudio(bgmhandlle);
			Novice::StopAudio(bgmhandlle2);
			Novice::StopAudio(bgmhandlle3);
			Novice::StopAudio(bgmhandlle4);
			if (Novice::IsPlayingAudio(bgmhandlle1) == 0 || bgmhandlle1 == -1) {
				bgmhandlle1 = Novice::PlayAudio(bgm1, true, 0.0f);

			}

			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);

			if (haikeiposX >= 1280) {
				haikeiposX = 0;
			}


			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == true && deadFlag == false && life >= 0) {
					Novice::DrawSprite(cX[i], cY[i], hasira, 1, 1, 0.0, WHITE);
				}
			}


			if (enedeadFlag == false && koukan > 120) {

				for (int i = 0; i < 300; i++) {
					if (enemybulletFlag[i] == true) {
						Novice::DrawSprite((int)eX[i], (int)eY[i], tori, 1, 1, 0.0, WHITE);
					}
					if (enemybullet2Flag[i] == true) {
						Novice::DrawSprite((int)(eX2[i]), (int)(eY2[i]), tori, 1, 1, 0.0, WHITE);

					}

				}
			}

			if (enelife > 0) {
				nezumi->Draw(nezumi->GetPosX(), nezumi->GetPosY(), batutori[batuttoriFlag], 1);
			}

			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			Novice::DrawSprite(100, 670, cell[eachnumber[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(164, 670, cell[eachnumber[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(228, 670, cell[eachnumber[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(292, 670, cell[eachnumber[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(356, 670, cell[eachnumber[4]], 0.5, 0.5, 0.0f, WHITE);

			Novice::DrawSprite(1000, 65, playercell[playernumbers[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1064, 65, playercell[playernumbers[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1128, 65, playercell[playernumbers[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1192, 65, playercell[playernumbers[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1256, 65, playercell[playernumbers[4]], 0.5, 0.5, 0.0f, WHITE);


			if (enelife >= elife * 0.9) {
				Novice::DrawSprite(0, 600, lifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.8) {
				Novice::DrawSprite(0, 600, lifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.7) {
				Novice::DrawSprite(0, 600, lifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.6) {
				Novice::DrawSprite(0, 600, lifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.5) {
				Novice::DrawSprite(0, 600, lifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.4) {
				Novice::DrawSprite(0, 600, lifebar[5], 1, 1, 0.0f, WHITE);
				batuttoriFlag = 1;
				theta2 += 10;
				tamakann2 = 500;
				randspeeds[2] = { 3 };
			}
			else if (enelife >= elife * 0.3) {
				Novice::DrawSprite(0, 600, lifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.2) {
				Novice::DrawSprite(0, 600, lifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (enelife > 0) {
				Novice::DrawSprite(0, 600, lifebar[8], 1, 1, 0.0f, WHITE);
			}
			else if (enelife <= 0) {
				enedeadFlag = true;
				scean = scean = Stage02;

				k = 290;
				koukan = 0;

			}

			if (life >= plife * 0.9) {
				Novice::DrawSprite(900, 12, playerlifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.8) {
				Novice::DrawSprite(900, 6, playerlifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.7) {
				Novice::DrawSprite(900, 6, playerlifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.6) {
				Novice::DrawSprite(900, 6, playerlifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.5) {
				Novice::DrawSprite(900, 6, playerlifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.4) {
				Novice::DrawSprite(900, 6, playerlifebar[5], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.3) {
				Novice::DrawSprite(900, 6, playerlifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.2) {
				Novice::DrawSprite(900, 6, playerlifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (life > 0) {
				Novice::DrawSprite(900, 6, playerlifebar[8], 1, 1, 0.0f, WHITE);
			}

			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			}

			Novice::DrawQuad((int)rigthpostopX, (int)rigthpostopY, (int)leftpostopX, (int)leftpostopY, (int)rigthposdownX, (int)rigthposdownY, (int)leftposdownX, (int)leftposdownY, 1000, 1000, 100, 200, white, WHITE);
			if (life <= 0) {
				Novice::DrawSprite(450, 50, replaye, 0.5, 0.5, 0.0, WHITE);
			}
			koukan++;

			break;
		case tale002:
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);


			if (haikeiposX >= 1280) {
				haikeiposX = 0;
			}

			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);


			if (k > 0) {
				k--;
			}
			if (k <= 0) {
				scean = tale02;
				blackFlag = true;
				koukan = 0;
			}

			/*if(blackFlag == false) {
				Novice::DrawSprite(0, 0, kiri[k / 10], 1, 1, 0.0, WHITE);
			}
			*/
			break;
		case tale02:
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);


			if (k >= 120) {

				if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {

					if (koukan < 291) {
						koukan++;
					}
					else if (koukan >= 291) {

						eneposX = 10;
						eneposY = 360;

						pointposX = -600;
						pointposY = 200;

						wid = 400;
						hit = 800;

						k = 0;
						blackFlag = false;

						theta = 0.0f;
						theta2 = 0.0f;

						randspeeds[2] = { 1 };
						tamakann2 = 2000;

						white = Novice::LoadTexture("white1x1.png");

						haikeiposX = 0;

						speed = 10;

						speed2 = 20;

						life = life + 200;

						yure = 50.0f;

						respon = 0;
						tamakann = 5000000;

						deadFlag = false;
						enedeadFlag = false;

						enelife = 2400;
						elife = enelife;
						scean = makann;
					}


				}
			}
			koukan++;
			k++;
			break;
		case makann:
			if (k >= 120) {
				scean = Stage02;
			}
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			Novice::DrawSprite(eneposX - 100, eneposY - 200, ootori[0], 4, 4, 0.0, WHITE);
			for (int i = 0; i < 300; i++) {

				eX[i] = { -50 };
				eY[i] = { -50 };

			}
			k++;


			break;
		case Stage02:

			Novice::StopAudio(bgmhandlle1);
			if (!Novice::IsPlayingAudio(bgmhandlle2) || bgmhandlle2 == -1) {
				bgmhandlle2 = Novice::PlayAudio(bgm2, true, 0.0f);
			}

			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);

			if (haikeiposX >= 1280) {
				haikeiposX = 0;
			}


			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == true && deadFlag == false) {
					Novice::DrawSprite(cX[i], cY[i], hasira, 1, 1, 0.0, WHITE);
				}
			}

			if (enedeadFlag == false && koukan > 120) {

				for (int i = 0; i < 300; i++) {
					if (enemybulletFlag[i] == true) {
						Novice::DrawSprite((int)eX[i], (int)eY[i], tori, 1, 1, 0.0, WHITE);
					}
					if (enemybullet2Flag[i] == true) {
						Novice::DrawSprite((int)(eX2[i]), (int)(eY2[i] - 50), tori, 1, 1, 0.0, WHITE);

					}

				}
			}

			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			if (enelife >= elife * 0.9) {
				Novice::DrawSprite(0, 600, lifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.8) {
				Novice::DrawSprite(0, 600, lifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.7) {
				Novice::DrawSprite(0, 600, lifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.6) {
				Novice::DrawSprite(0, 600, lifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.5) {
				Novice::DrawSprite(0, 600, lifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.4) {
				Novice::DrawSprite(0, 600, lifebar[5], 1, 1, 0.0f, WHITE);
				ootori[0] = ootori[1];
				tamakann2 = 500;
			}
			else if (enelife >= elife * 0.3) {
				Novice::DrawSprite(0, 600, lifebar[6], 1, 1, 0.0f, WHITE);
				ootori[0] = ootori[1];
			}
			else if (enelife >= elife * 0.2) {
				Novice::DrawSprite(0, 600, lifebar[7], 1, 1, 0.0f, WHITE);
				ootori[0] = ootori[1];
			}
			else if (enelife > 0) {
				Novice::DrawSprite(0, 600, lifebar[8], 1, 1, 0.0f, WHITE);
				ootori[0] = ootori[1];
			}
			else if (enelife <= 0) {
				enedeadFlag = true;
				scean = tale003;
				k = 290;
				koukan = 0;

			}

			if (life >= plife * 0.9) {
				Novice::DrawSprite(900, 12, playerlifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.8) {
				Novice::DrawSprite(900, 6, playerlifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.7) {
				Novice::DrawSprite(900, 6, playerlifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.6) {
				Novice::DrawSprite(900, 6, playerlifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.5) {
				Novice::DrawSprite(900, 6, playerlifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.4) {
				Novice::DrawSprite(900, 6, playerlifebar[5], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.3) {
				Novice::DrawSprite(900, 6, playerlifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.2) {
				Novice::DrawSprite(900, 6, playerlifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (life > 0) {
				Novice::DrawSprite(900, 6, playerlifebar[8], 1, 1, 0.0f, WHITE);
			}

			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			}



			Novice::DrawSprite(1000, 65, playercell[playernumbers[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1064, 65, playercell[playernumbers[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1128, 65, playercell[playernumbers[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1192, 65, playercell[playernumbers[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1256, 65, playercell[playernumbers[4]], 0.5, 0.5, 0.0f, WHITE);

			Novice::DrawSprite(100, 670, cell[eachnumber[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(164, 670, cell[eachnumber[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(228, 670, cell[eachnumber[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(292, 670, cell[eachnumber[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(356, 670, cell[eachnumber[4]], 0.5, 0.5, 0.0f, WHITE);




			if (enelife > 0) {
				spaodar->Draw(spaodar->GetPosX(), spaodar->GetPosY(), ootori[0], 1);

			}
			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			}
			Novice::DrawQuad((int)rigthpostopX, (int)rigthpostopY, (int)leftpostopX, (int)leftpostopY, (int)rigthposdownX, (int)rigthposdownY, (int)leftposdownX, (int)leftposdownY, 1000, 1000, 100, 200, white, WHITE);

			koukan++;
			if (eyeFlag == false) {
				if (playerposX != pointr) {
					playerposX += speed / 3;
				}
				if (playerposY != pointa) {
					playerposY -= speed / 3;
				}
				Novice::DrawSprite(pointr, pointa, eye, 4, 4, 0.0, WHITE);
				for (int i = 0; i < 12; i++) {
					Novice::DrawSprite(point[i], point[i + 12], eye, 4, 4, 0.0, WHITE);
				}
			}
			if (life <= 0) {
				Novice::DrawSprite(450, 50, replaye, 0.5, 0.5, 0.0, WHITE);
			}
			Novice::DrawSprite(0, 0, kiri[7], 1, 1, 0.0, WHITE);
			koukan++;

			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);

			break;
		case tale003:
			if (k < 0) {
				k--;
			}
			else if (k >= 0) {
				scean = tale03;
				blackFlag = true;
				koukan = 0;
			}

			if (blackFlag == false) {
				Novice::DrawSprite(0, 0, blacktale[k / 10], 1, 1, 0.0, WHITE);
			}

			k++;
			break;
		case tale03:
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);

			if (koukan >= 120) {

				if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {



					eneposX = 10;
					eneposY = 360;

					pointposX = -600;
					pointposY = 200;

					wid = 400;
					hit = 800;

					k = 0;
					blackFlag = false;




					theta = 0.0f;
					theta2 = 0.0f;

					white = Novice::LoadTexture("white1x1.png");

					haikeiposX = 0;

					speed = 10;

					speed2 = 20;

					life = life + 200;

					yure = 50.0f;

					respon = 0;
					tamakann = 5000;
					tamakann2 = 2000;

					deadFlag = false;
					enedeadFlag = false;

					enelife = 1440;
					elife = enelife;
					scean = makann2;
				}
			}
			koukan++;
			break;
		case makann2:
			if (k >= 120) {
				scean = Stage03;
			}
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);
			for (int i = 0; i < 300; i++) {

				eX[i] = { -50 };
				eY[i] = { -50 };

			}
			hae->Draw(hae->GetPosX(), hae->GetPosY(), sinnpanndori[0], 2);
			k++;
			break;
		case Stage03:
			Novice::StopAudio(bgmhandlle2);
			if ((!Novice::IsPlayingAudio(sehandlle) || sehandlle == -1) && sinpanFlag == true) {
				sehandlle = Novice::PlayAudio(tin, false, 0.0f);
				sinpanFlag = false;

			}
			if (!Novice::IsPlayingAudio(bgmhandlle3) || bgmhandlle3 == -1) {
				bgmhandlle3 = Novice::PlayAudio(bgm3, true, 0.0f);
			}


			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);

			if (haikeiposX >= 1280) {
				haikeiposX = 0;
			}


			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == true && deadFlag == false) {
					Novice::DrawSprite(cX[i], cY[i], hasira, 1, 1, 0.0, WHITE);
				}
			}


			if (enedeadFlag == false && koukan > 120) {

				for (int i = 0; i < 300; i++) {
					if (enemybulletFlag[i] == true) {
						Novice::DrawSprite((int)eX[i], (int)eY[i], tori, 1, 1, 0.0, WHITE);
					}

				}
			}

			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);


			if (enelife >= elife * 0.9) {
				Novice::DrawSprite(0, 600, lifebar[0], 1, 1, 0.0f, WHITE);

			}
			else if (enelife >= elife * 0.8) {
				Novice::DrawSprite(0, 600, lifebar[1], 1, 1, 0.0f, WHITE);

			}
			else if (enelife >= elife * 0.7) {
				Novice::DrawSprite(0, 600, lifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.6) {
				Novice::DrawSprite(0, 600, lifebar[3], 1, 1, 0.0f, WHITE);

			}
			else if (enelife >= elife * 0.5) {
				Novice::DrawSprite(0, 600, lifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.4) {
				Novice::DrawSprite(0, 600, lifebar[5], 1, 1, 0.0f, WHITE);
				tamakann = 3000;
			}
			else if (enelife >= elife * 0.3) {
				Novice::DrawSprite(0, 600, lifebar[6], 1, 1, 0.0f, WHITE);

			}
			else if (enelife >= elife * 0.2) {
				Novice::DrawSprite(0, 600, lifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (enelife > 0) {
				Novice::DrawSprite(0, 600, lifebar[8], 1, 1, 0.0f, WHITE);
			}
			else if (enelife <= 0) {
				enedeadFlag = true;
				scean = tale004;
				k = 290;
				koukan = 0;

			}

			if (life >= plife * 0.9) {
				Novice::DrawSprite(900, 12, playerlifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.8) {
				Novice::DrawSprite(900, 6, playerlifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.7) {
				Novice::DrawSprite(900, 6, playerlifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.6) {
				Novice::DrawSprite(900, 6, playerlifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.5) {
				Novice::DrawSprite(900, 6, playerlifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.4) {
				Novice::DrawSprite(900, 6, playerlifebar[5], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.3) {
				Novice::DrawSprite(900, 6, playerlifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.2) {
				Novice::DrawSprite(900, 6, playerlifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (life > 0) {
				Novice::DrawSprite(900, 6, playerlifebar[8], 1, 1, 0.0f, WHITE);
			}

			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			}


			Novice::DrawSprite(1000, 65, playercell[playernumbers[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1064, 65, playercell[playernumbers[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1128, 65, playercell[playernumbers[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1192, 65, playercell[playernumbers[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1256, 65, playercell[playernumbers[4]], 0.5, 0.5, 0.0f, WHITE);


			Novice::DrawSprite(100, 670, cell[eachnumber[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(164, 670, cell[eachnumber[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(228, 670, cell[eachnumber[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(292, 670, cell[eachnumber[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(356, 670, cell[eachnumber[4]], 0.5, 0.5, 0.0f, WHITE);


			Novice::DrawQuad((int)rigthpostopX, (int)rigthpostopY, (int)leftpostopX, (int)leftpostopY, (int)rigthposdownX, (int)rigthposdownY, (int)leftposdownX, (int)leftposdownY, 1000, 1000, 100, 200, white, WHITE);

			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
				n = 0;
			}

			if (enelife > 0) {
				goki->Draw(goki->GetPosX(), goki->GetPosY(), sinnpanndori[0], 1);
			}
			else if (life <= 0) {
				if (n <= 241) {
					n++;
					Novice::DrawSprite(0, 0, kiri[n / 30], 1, 1, 0.0, WHITE);
				}

			}
			if (life <= 0) {
				Novice::DrawSprite(450, 50, replaye, 0.5, 0.5, 0.0, WHITE);
			}

			koukan++;

			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);

			break;
		case tale004:
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			if (k < 0) {
				k--;
			}
			else if (k >= 0) {
				scean = tale04;
				blackFlag = true;
				n = 0;
				koukan = 0;
			}

			if (blackFlag == false) {
				Novice::DrawSprite(0, 0, blacktale[k / 10], 1, 1, 0.0, WHITE);
			}


			///k++;
			break;
		case tale04:
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);
			Novice::DrawSprite(376, 600, UI, 1, 1, 0.0f, WHITE);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);
			if (koukan >= 120) {


				if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE] != 0) {


					eneposX = 10;
					eneposY = 360;

					pointposX = -600;
					pointposY = 200;

					wid = 400;
					hit = 800;

					k = 0;

					blackFlag = false;




					theta = 0.0f;
					theta2 = 0.0f;

					white = Novice::LoadTexture("white1x1.png");

					haikeiposX = 0;

					speed = 10;

					speed2 = 20;



					yure = 50.0f;

					respon = 0;
					tamakann = 5000;
					tamakann2 = 2000;

					life = life + 200;


					deadFlag = false;
					enedeadFlag = false;

					enelife = 3000;
					elife = enelife;
					scean = makann3;


				}
			}
			n++;
			koukan++;
			break;
		case makann3:
			if (k >= 120) {
				scean = Stage04;
			}
			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);

			Novice::DrawSprite(eneposX - 50, eneposY - 175, syuumatudori, 2, 2, 0.0, WHITE);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);
			for (int i = 0; i < 300; i++) {

				eX[i] = { -50 };
				eY[i] = { -50 };

			}
			k++;
			break;
		case Stage04:

			Novice::StopAudio(bgmhandlle3);
			if (!Novice::IsPlayingAudio(bgmhandlle4) || bgmhandlle4 == -1) {
				bgmhandlle4 = Novice::PlayAudio(bgm4, true, 0.0f);
			}

			if ((!Novice::IsPlayingAudio(sehandlle) || sehandlle == -1) && sinpanFlag == true) {
				sehandlle = Novice::PlayAudio(tin, false, 0.0f);
				sinpanFlag = false;

			}

			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);

			if (haikeiposX >= 1280) {
				haikeiposX = 0;
			}

			for (int i = 0; i < 100; i++) {
				if (bulletFlag[i] == true && deadFlag == false) {
					Novice::DrawSprite(cX[i], cY[i], hasira, 1, 1, 0.0, WHITE);
				}
			}
			Novice::DrawBox(0, 0, 1280, 100, 0.0, BLACK, kFillModeSolid);

			Novice::DrawBox(0, 570, 1280, 150, 0.0, BLACK, kFillModeSolid);

			if (enedeadFlag == false && koukan > 120) {
				for (int i = 0; i < 300; i++) {
					if (enemybulletFlag[i] == true) {
						Novice::DrawSprite((int)eX[i], (int)eY[i], tori, 1, 1, 0.0, WHITE);
					}
					if (enemybullet2Flag[i] == true) {
						Novice::DrawSprite((int)(eX2[i]), (int)(eY2[i] - 50), tori, 1, 1, 0.0, WHITE);
					}


				}
			}

			if (enelife >= elife * 0.9) {
				Novice::DrawSprite(0, 600, lifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.8) {
				Novice::DrawSprite(0, 600, lifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.7) {
				Novice::DrawSprite(0, 600, lifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.6) {
				Novice::DrawSprite(0, 600, lifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.5) {
				Novice::DrawSprite(0, 600, lifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.4) {
				Novice::DrawSprite(0, 600, lifebar[5], 1, 1, 0.0f, WHITE);
				tamakann = 300;
			}
			else if (enelife >= elife * 0.3) {
				Novice::DrawSprite(0, 600, lifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (enelife >= elife * 0.2) {
				Novice::DrawSprite(0, 600, lifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (enelife > 0) {
				Novice::DrawSprite(0, 600, lifebar[8], 1, 1, 0.0f, WHITE);
			}
			else if (enelife <= 0) {
				enedeadFlag = true;
				scean = End;
				k = 0;
				koukan = 0;

			}

			if (life >= plife * 0.9) {
				Novice::DrawSprite(900, 12, playerlifebar[0], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.8) {
				Novice::DrawSprite(900, 6, playerlifebar[1], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.7) {
				Novice::DrawSprite(900, 6, playerlifebar[2], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.6) {
				Novice::DrawSprite(900, 6, playerlifebar[3], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.5) {
				Novice::DrawSprite(900, 6, playerlifebar[4], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.4) {
				Novice::DrawSprite(900, 6, playerlifebar[5], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.3) {
				Novice::DrawSprite(900, 6, playerlifebar[6], 1, 1, 0.0f, WHITE);
			}
			else if (life >= plife * 0.2) {
				Novice::DrawSprite(900, 6, playerlifebar[7], 1, 1, 0.0f, WHITE);
			}
			else if (life > 0) {
				Novice::DrawSprite(900, 6, playerlifebar[8], 1, 1, 0.0f, WHITE);
			}

			if (life >= 0) {
				player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			}


			Novice::DrawSprite(900, 65, playercell[playernumbers[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(964, 65, playercell[playernumbers[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1028, 65, playercell[playernumbers[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1092, 65, playercell[playernumbers[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(1156, 65, playercell[playernumbers[4]], 0.5, 0.5, 0.0f, WHITE);


			Novice::DrawSprite(100, 670, cell[eachnumber[0]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(164, 670, cell[eachnumber[1]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(228, 670, cell[eachnumber[2]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(292, 670, cell[eachnumber[3]], 0.5, 0.5, 0.0f, WHITE);
			Novice::DrawSprite(356, 670, cell[eachnumber[4]], 0.5, 0.5, 0.0f, WHITE);

			if (enelife > 0) {
				Novice::DrawSprite(eneposX - 50, eneposY - 175, syuumatudori, 2, 2, 0.0, WHITE);
			}
			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			Novice::DrawQuad((int)rigthpostopX, (int)rigthpostopY, (int)leftpostopX, (int)leftpostopY, (int)rigthposdownX, (int)rigthposdownY, (int)leftposdownX, (int)leftposdownY, 1000, 1000, 100, 200, white, WHITE);
			if (eyeFlag == false) {
				if (playerposX != pointr) {
					playerposX += speed / 3;
				}
				if (playerposY != pointa) {
					playerposY -= speed / 3;
				}
				Novice::DrawSprite(pointr, pointa, eye, 4, 4, 0.0, WHITE);
				for (int i = 0; i < 12; i++) {
					Novice::DrawSprite(point[i], point[i + 12], eye, 4, 4, 0.0, WHITE);
				}

			}
			else if (eyeFlag == true) {
				speed = speed;
			}
			if (life <= 0) {
				Novice::DrawSprite(450, 50, replaye, 0.5, 0.5, 0.0, WHITE);
			}
			Novice::DrawSprite(0, 0, kiri[7], 1, 1, 0.0, WHITE);
			koukan++;
			break;
		case End:


			Novice::DrawSprite(haikeiposX, 0, binar, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(haikeiposX - 1280, 0, binar, 1, 1, 0.0f, WHITE);

			player->Drow(player->GetPosX(), player->GetPosY(), player_Texture, 1);
			if (k < 120) {
				Novice::DrawSprite(0, 0, kiri[k / 14], 1, 1, 0.0, WHITE);
			}

			if (k >= 120) {

				if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
					koukan += 120;
				}
				if (koukan >= 600) {
					k = 0;
					scean = resalt;
				}




			}
			k++;

			break;
		case resalt:
			Novice::StopAudio(bgmhandlle3);

			number = (10000 - life + kaihuku * 300 + relife);
			Novice::DrawBox(0, 0, 1280, 720, 0.0, BLACK, kFillModeSolid);
			if (rabitFlag == true) {
				if (k <= 60) {
					Novice::DrawSprite(320, 50, resultD[k / 10], 1, 1, 0.0, WHITE);
				}
				if (k > 60) {
					Novice::DrawSprite(320, 50, resultD[6], 1, 1, 0.0, WHITE);
				}
			}
			else if (number < 10000) {
				if (k <= 60) {
					Novice::DrawSprite(320, 50, resultS[k / 10], 1, 1, 0.0, WHITE);
				}
				if (k > 60) {
					Novice::DrawSprite(320, 50, resultS[6], 1, 1, 0.0, WHITE);
				}
			}
			else if (number < 13000) {
				if (k <= 60) {
					Novice::DrawSprite(320, 50, resultA[k / 10], 1, 1, 0.0, WHITE);
				}
				if (k > 60) {
					Novice::DrawSprite(320, 50, resultA[6], 1, 1, 0.0, WHITE);
				}
			}
			else if (number < 16000) {
				if (k <= 60) {
					Novice::DrawSprite(320, 50, resultB[k / 10], 1, 1, 0.0, WHITE);
				}
				if (k > 60) {
					Novice::DrawSprite(320, 50, resultB[6], 1, 1, 0.0, WHITE);
				}
			}
			else if (number >= 16000) {
				if (k <= 60) {
					Novice::DrawSprite(320, 50, resultC[k / 10], 1, 1, 0.0, WHITE);
				}
				if (k > 60) {
					Novice::DrawSprite(320, 50, resultC[6], 1, 1, 0.0, WHITE);
				}
			}


			eachnumber[0] = number / 10000;
			number = number % 10000;

			eachnumber[1] = number / 1000;
			number = number % 1000;

			eachnumber[2] = number / 100;
			number = number % 100;

			eachnumber[3] = number / 10;
			number = number % 10;

			eachnumber[4] = number;
			if (k > 70) {

				Novice::DrawSprite(390, 300, cell[eachnumber[0]], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(454, 300, cell[eachnumber[1]], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(518, 300, cell[eachnumber[2]], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(582, 300, cell[eachnumber[3]], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(646, 300, cell[eachnumber[4]], 1, 1, 0.0f, WHITE);

			}

			k++;
			break;
		case over:
			Novice::StopAudio(bgmhandlle1);
			Novice::StopAudio(bgmhandlle2);
			Novice::StopAudio(bgmhandlle3);
			Novice::StopAudio(bgmhandlle4);

			if (Novice::IsPlayingAudio(bgmhandlle) == 0 || bgmhandlle == -1) {
				bgmhandlle = Novice::PlayAudio(startbgm, true, 0.0f);

			}

			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);


			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
				life = 10000;
				enelife = 500;
				scean = Stage01;
			}
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;

}
