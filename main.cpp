#include "SBDL.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

//const variables of the game


const int windowWidth = 1000;
const int windowHeight =400;
int counter = 0;//barry Running
int counter2 = 0;//zapper 1 Showing
int counter3 = 0;//zapper 3 showing
int counter4 = 0;//zapper 4 showing
int temp;//for producing the random number to decide to show one of the zappers 
int temp2;//for showing the zappers cor
int temp3;
int cor1;
int cor2;
int cor3;
int rand1;
int rand2;
int rand3;
int rand4;
int rand5;
int rand6;
const float vel_background = -0.4;
float barrySpeed =(0.05);
const float barry_a = 2;
bool air = false;
bool music_bool;
int time_for_lazers;
int my;
int counter5 = 0;
int counter6 = 0;
int counter7 = 0;
int counter8 = 0;
int counter9 = 0;

enum state {
	pausing , playing , settings , losing , menu , exitting , start
}gameState;



//*************************************************************

Texture background[10];
Texture barry;
Texture background_;
Texture back;
Texture changeKeys;
Texture gravity;
Texture highScores;
Texture quit;
Texture play;
Texture resume500;
Texture resume;
Texture retry;
Texture setting;
Texture soundOff;
Texture  soundOn;
Texture	sound ;
Texture firstp;
Texture firstp2;
Texture barry2;
Texture zapper1[4];
Texture zapper2[4];
Texture zapper3[4];
Texture barryJumping;
Texture barryJumping2;
Texture pause;
Texture scientist[4];
Texture scientist2[4];
Texture scientist3[4];
Texture gameOver;
Texture lasers[3];
Texture missles[7];




Music *changebarry;
Music *coin;
Music *grav_change_1;
Music *grav_change_2;
Music *highscore;
Music *jetpack_se;
Music *laser_fire_lp;
Music *laser_warning;
Music *missile_launch;
Music *missile_warning;
Music *music;
Music *soundonEffect;
Music *zapper;

SDL_Rect playButtonRect;
SDL_Rect settingButtonRect;
SDL_Rect quitButtonRect;
SDL_Rect quit2ButtonRect;
SDL_Rect highScoresButtonRect;
SDL_Rect backbuttonRect;
SDL_Rect back2ButtonRect;
SDL_Rect pauseButtonRect;
SDL_Rect resumeButtonRect;
SDL_Rect retryButtonRect;
SDL_Rect zapper1Rect;
SDL_Rect zapper2Rect;
SDL_Rect zapper3Rect;
SDL_Rect barryRect;
SDL_Rect missleRect;
SDL_Rect laserRect;
SDL_Rect soundOnRect;
SDL_Rect soundOffRect;




//structures of the game

struct Cor {
	float x, y;
} ;
Cor backgrounds[10];
Cor BarryCor;
Cor zapper1Cor;
Cor zapper2Cor;
Cor zapper3Cor;
Cor scientist1Cor[4];
Cor scientist2Cor[4];
Cor scientist3Cor[4];
Cor misslesCors;
Cor laserCors;



struct FlippingThing {
	int size;
	Texture *images = nullptr;
	std::string folderAddress = "assets/";
	int currentIndex;
	bool active = false;
};



//********************************************************************
//helful functions for the game

//--------------------------------------
void backgroundsCor(){
	backgrounds[0] = { 0, 0 };
	backgrounds[1] = { 1 * windowWidth, 0 };
	backgrounds[2] = { 2 * windowWidth, 0 };
	backgrounds[3] = { 3 * windowWidth, 0 };
	backgrounds[4] = { 4 * windowWidth, 0 };
	backgrounds[5] = { 5 * windowWidth, 0 };
	backgrounds[6] = { 6 * windowWidth, 0 };
	backgrounds[7] = { 7 * windowWidth, 0 };
	backgrounds[8] = { 8 * windowWidth, 0 };
	backgrounds[9] = { 9 * windowWidth, 0 };

}
//----------------------------------------------
void Keeper(){

	//images of the game 
	background[0] = SBDL::loadTexture("assets/pic/Lab Start.png");
	background[1] = SBDL::loadTexture("assets/pic/Lab1.png");
	background[2] = SBDL::loadTexture("assets/pic/Lab2.png");
	background[3] = SBDL::loadTexture("assets/pic/Sector Start.png");
	background[4] = SBDL::loadTexture("assets/pic/Sector1.png");
	background[5] = SBDL::loadTexture("assets/pic/Sector2.png");
	background[6] = SBDL::loadTexture("assets/pic/warehouse Start.png");
	background[7] = SBDL::loadTexture("assets/pic/warehouse.png");
	background[8] = SBDL::loadTexture("assets/pic/Volcano1.png");
	background[9] = SBDL::loadTexture("assets/pic/Volcano2.png");

	zapper1[0] = SBDL::loadTexture("assets/pic/zapper1/1.png");
	zapper1[1] = SBDL::loadTexture("assets/pic/zapper1/2.png");
	zapper1[2] = SBDL::loadTexture("assets/pic/zapper1/3.png");
	zapper1[3] = SBDL::loadTexture("assets/pic/zapper1/4.png");

	zapper2[0] = SBDL::loadTexture("assets/pic/zapper2/1.png");
	zapper2[1] = SBDL::loadTexture("assets/pic/zapper2/2.png");
	zapper2[2] = SBDL::loadTexture("assets/pic/zapper2/3.png");
	zapper2[3] = SBDL::loadTexture("assets/pic/zapper2/4.png");

	zapper3[0] = SBDL::loadTexture("assets/pic/zapper3/1.png");
	zapper3[1] = SBDL::loadTexture("assets/pic/zapper3/2.png");
	zapper3[2] = SBDL::loadTexture("assets/pic/zapper3/3.png");
	zapper3[3] = SBDL::loadTexture("assets/pic/zapper3/4.png");

	scientist[0] = SBDL::loadTexture("assets/pic/scientist/3.png");
	scientist[1] = SBDL::loadTexture("assets/pic/scientist/4.png");
	scientist[2] = SBDL::loadTexture("assets/pic/scientist/5.png");
	scientist[3] = SBDL::loadTexture("assets/pic/scientist/6.png");

	scientist2[0] = SBDL::loadTexture("assets/pic/scientist/8.png");
	scientist2[1] = SBDL::loadTexture("assets/pic/scientist/9.png");
	scientist2[2] = SBDL::loadTexture("assets/pic/scientist/10.png");
	scientist2[3] = SBDL::loadTexture("assets/pic/scientist/11.png");

	scientist3[0] = SBDL::loadTexture("assets/pic/scientist/12.png");
	scientist3[1] = SBDL::loadTexture("assets/pic/scientist/13.png");
	scientist3[2] = SBDL::loadTexture("assets/pic/scientist/14.png");
	scientist3[3] = SBDL::loadTexture("assets/pic/scientist/15.png");

	lasers[0] = SBDL::loadTexture("assets/pic/laser/1.png");
	lasers[1] = SBDL::loadTexture("assets/pic/laser/2.png");
	lasers[2] = SBDL::loadTexture("assets/pic/laser/3.png");	

	missles[0] = SBDL::loadTexture("assets/pic/jet/1.png");
	missles[1] = SBDL::loadTexture("assets/pic/jet/2.png");
	missles[2] = SBDL::loadTexture("assets/pic/jet/3.png");
	missles[3] = SBDL::loadTexture("assets/pic/jet/4.png");
	missles[4] = SBDL::loadTexture("assets/pic/jet/5.png");
	missles[5] = SBDL::loadTexture("assets/pic/jet/6.png");
	missles[6] = SBDL::loadTexture("assets/pic/jet/7.png");

    background_ = SBDL::loadTexture("assets/pic/Background.png");
	back = SBDL::loadTexture("assets/pic/back.png");
	changeKeys = SBDL::loadTexture("assets/pic/change keys.png");
    gravity = SBDL::loadTexture("assets/pic/gravity_token.png");
	highScores = SBDL::loadTexture("assets/pic/highscores.png");
	play = SBDL::loadTexture("assets/pic/play.png");
	quit = SBDL::loadTexture("assets/pic/quit.png");
	resume500 = SBDL::loadTexture("assets/pic/resume 500.png");
	resume = SBDL::loadTexture("assets/pic/resume.png");
	retry = SBDL::loadTexture("assets/pic/retry.png");
	setting = SBDL::loadTexture("assets/pic/setting.png");
	soundOff = SBDL::loadTexture("assets/pic/sound off.png");
    soundOn = SBDL::loadTexture("assets/pic/sound on.png");
	sound = SBDL::loadTexture("assets/pic/sound.png");
    firstp = SBDL::loadTexture("assets/pic/First P.png");
	firstp2 = SBDL::loadTexture("assets/pic/First P2.png");
	barry = SBDL::loadTexture("assets/pic/barry run/1.png");
	barry2 = SBDL::loadTexture("assets/pic/barry run/2.png");
	barryJumping = SBDL::loadTexture("assets/pic/barry jump/1.png");
	barryJumping2 = SBDL::loadTexture("assets/pic/barry jump/2.png");
	pause = SBDL::loadTexture("assets/pic/pause.png");
	firstp = SBDL::loadTexture("assets/pic/First P.png");
	firstp2 = SBDL::loadTexture("assets/pic/First P2.png");
	gameOver = SBDL::loadTexture("assets/pic/gameOver.png");
	
	//musics of the game
	changebarry = SBDL::loadMusic("assets/sound/changebarry.wav");
	coin = SBDL::loadMusic("assets/sound/coin.wav");
	grav_change_1 = SBDL::loadMusic("assets/sound/grav_change_1.wav");
	grav_change_2 = SBDL::loadMusic("assets/sound/grav_change_1.wav");
	highscore = SBDL::loadMusic("assets/sound/highscore.wav");
	jetpack_se = SBDL::loadMusic("assets/sound/jetpack_se.wav");
	laser_fire_lp = SBDL::loadMusic("assets/sound/laser_fire_lp.wav");
	laser_warning = SBDL::loadMusic("assets/sound/laser_warning.wav");
	missile_launch = SBDL::loadMusic("assets/sound/missile_launch.wav");
	missile_warning = SBDL::loadMusic("assets/sound/missile_warning.wav");
	music = SBDL::loadMusic("assets/sound/music.wav");
	soundonEffect = SBDL::loadMusic("assets/sound/soundonEffect.wav");
	zapper = SBDL::loadMusic("assets/sound/zapper.wav");
	
}
//--------------------------------------------
void forMusic(){
	SBDL::playMusic(music, -1);
	music_bool = true;
}
//----------------------------------------------
void TextureShower(){

	SBDL::showTexture(background[0], backgrounds[0].x, backgrounds[0].y);
	SBDL::showTexture(background[1], backgrounds[1].x, backgrounds[0].y);
	SBDL::showTexture(background[2], backgrounds[2].x, backgrounds[0].y);
	SBDL::showTexture(background[3], backgrounds[3].x, backgrounds[0].y);
	SBDL::showTexture(background[4], backgrounds[4].x, backgrounds[0].y);
	SBDL::showTexture(background[5], backgrounds[5].x, backgrounds[0].y);
	SBDL::showTexture(background[6], backgrounds[6].x, backgrounds[0].y);
	SBDL::showTexture(background[7], backgrounds[7].x, backgrounds[0].y);
	SBDL::showTexture(background[8], backgrounds[8].x, backgrounds[0].y);
	SBDL::showTexture(background[9], backgrounds[9].x, backgrounds[0].y);
	SBDL::showTexture(pause, windowWidth - 55, 0);

	backgrounds[0].x += vel_background;
	backgrounds[1].x += vel_background;
	backgrounds[2].x += vel_background;
	backgrounds[3].x += vel_background;
	backgrounds[4].x += vel_background;
	backgrounds[5].x += vel_background;
	backgrounds[6].x += vel_background;
	backgrounds[7].x += vel_background;
	backgrounds[8].x += vel_background;
	backgrounds[9].x += vel_background;

	if (backgrounds[9].x <= 0){
		backgroundsCor();
		TextureShower();
	}
}
//----------------------------------------
void misslesCor(){
	srand(time(NULL));
	misslesCors.x = 2000;
	rand5 = rand() % 333;
	misslesCors.y = rand5;
}
//------------------------------
void misslesShower(){
	if (counter9 % 7 == 0){
		SBDL::showTexture(missles[0], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 1){
		SBDL::showTexture(missles[1], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 2){
		SBDL::showTexture(missles[2], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 3){
		SBDL::showTexture(missles[3], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 4){
		SBDL::showTexture(missles[4], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 5){
		SBDL::showTexture(missles[5], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	if (counter9 % 7 == 6){
		SBDL::showTexture(missles[6], misslesCors.x, misslesCors.y);
		misslesCors.x += 1.2 * vel_background;
	}
	counter9++;
	if (counter9 > 7)
		counter9 = 0;
	if (misslesCors.x <= -45)
		misslesCor();
}
//-------------------------------------------------
void scientistCor(){
	scientist1Cor[0] = { windowWidth / 16, 350 };
	scientist1Cor[1] = { windowWidth / 16, 350 };
	scientist1Cor[2] = { windowWidth / 16, 350 };
	scientist1Cor[3] = { windowWidth / 16, 350 };
}
//-----------------------------------------------
void showScientist(){
	if (counter5 % 4 == 0){
		SBDL::showTexture(scientist[0], scientist1Cor[0].x, scientist1Cor[0].y);
		scientist1Cor[0].x += 0.5;
	}
	if (counter5 % 4 == 1){
		SBDL::showTexture(scientist[1], scientist1Cor[0].x, scientist1Cor[0].y);
		scientist1Cor[0].x -= -0.5;
	}
	if (counter5 % 4 == 2){
		SBDL::showTexture(scientist[2], scientist1Cor[0].x, scientist1Cor[0].y);
		scientist1Cor[0].x -= -0.5;
	}
	if (counter5 % 4 == 3){
		SBDL::showTexture(scientist[3], scientist1Cor[0].x, scientist1Cor[0].y);
		scientist1Cor[0].x -= -0.5;
	}
	counter5++;

	if (scientist1Cor[0].x >= windowWidth && counter5 >= 3345){
		scientistCor();
		counter5 = 0;
	}
}
//------------------------------
void scientistCor2(){
	scientist2Cor[0]= { windowWidth / 9, 350 };
}
//-------------------------------------------------------
void showScientist2(){
	if (counter6 % 4 == 0){
		SBDL::showTexture(scientist2[0], scientist2Cor[0].x, scientist2Cor[0].y);
		scientist2Cor[0].x -= -0.15;
	}
	if (counter6 % 4 == 1){
		SBDL::showTexture(scientist2[1], scientist2Cor[0].x, scientist2Cor[0].y);
		scientist2Cor[0].x -= -0.15;
	}
	if (counter6 % 4 == 2){
		SBDL::showTexture(scientist2[1], scientist2Cor[0].x, scientist2Cor[0].y);
		scientist2Cor[0].x -= -0.15;
	}
	if (counter6 % 4 == 3){
		SBDL::showTexture(scientist2[1], scientist2Cor[0].x, scientist2Cor[0].y);
		scientist2Cor[0].x -= -0.15;
	}
	counter6++;
	if (counter6 > 4)
		counter6 = 0;
	if (scientist2Cor[0].x >= windowWidth)
		scientistCor2();
}

void scientistCor3(){
	scientist3Cor[0] = { windowWidth, 350 };
}
void showScientist3(){
	if (counter8 % 4 == 0){
		SBDL::showTexture(scientist3[0], scientist3Cor[0].x,scientist3Cor[0].y );
		scientist3Cor[0].x -= 0.25;
	}
	if (counter8 % 4 == 1){
		SBDL::showTexture(scientist3[1], scientist3Cor[0].x, scientist3Cor[0].y);
		scientist3Cor[0].x -= 0.25;
	}
	if (counter8 % 4 == 2){
		SBDL::showTexture(scientist3[2], scientist3Cor[0].x, scientist3Cor[0].y);
		scientist3Cor[0].x -=0.25;
	}
	if (counter8 % 4 == 3){
		SBDL::showTexture(scientist3[3], scientist3Cor[0].x, scientist3Cor[0].y);
		scientist3Cor[0].x -=0.25;
	}
	counter8++;
	if (scientist3Cor[0].x <= 0)
		scientistCor3();
	if (counter8 > 4)
		counter8 = 0;
}
//-------------------------------
void showBarryRun(){
	if (BarryCor.y > 0 && BarryCor.y < windowHeight - 60.43)
		air = true;
	else
		air = false;
	if (!SBDL::keyHeld(SDL_SCANCODE_SPACE)){
		if (air == false){
			if (counter % 10 <= 5 )
				SBDL::showTexture(barry, BarryCor.x, BarryCor.y);
			if (counter % 10 > 5)
				SBDL::showTexture(barry2, BarryCor.x, BarryCor.y);

			counter ++;
			if (counter > 9)
				counter = 0;
		}

	}
	if (SBDL::keyHeld(SDL_SCANCODE_SPACE))
		SBDL::showTexture(barryJumping, BarryCor.x, BarryCor.y);
	else if (!SBDL::keyHeld(SDL_SCANCODE_SPACE) && air == true) 
		SBDL::showTexture(barryJumping2, BarryCor.x, BarryCor.y);
	
}
//-------------------------------------
void spaceHeld(){

	if (SBDL::keyHeld(SDL_SCANCODE_SPACE) && BarryCor.y <= windowHeight &&  BarryCor.y >= 0){
		barrySpeed = 0; barrySpeed += 0.79; BarryCor.y -= barrySpeed*barrySpeed*(0.85);

	}
	else  {
		if (BarryCor.y <= 345){
			barrySpeed = 1.4; barrySpeed -= 0.79; BarryCor.y += barrySpeed*barrySpeed*(0.85);
		}
	}
}
//-------------------------------------------
void zapper1Cors(){
	srand(time(NULL));
	rand1 = rand() % 327;
	zapper1Cor.x = windowWidth ;
	zapper1Cor.y = rand1;
}
//-------------------------------------------
void zapper1Shower(){

	if (counter2 % 4 == 0){
		SBDL::showTexture(zapper1[0], zapper1Cor.x, rand1);
		zapper1Cor.x += vel_background;
	}
	if (counter2 % 4 == 1){
		SBDL::showTexture(zapper1[1], zapper1Cor.x, rand1);
		zapper1Cor.x += vel_background;
	}
	if (counter2 % 4 == 2){
		SBDL::showTexture(zapper1[2], zapper1Cor.x, rand1);
		zapper1Cor.x += vel_background;
	}
	if (counter2 % 4 == 3){
		SBDL::showTexture(zapper1[3], zapper1Cor.x, rand1);
		zapper1Cor.x += vel_background;
	}
	counter2++;
	if (counter2 > 4)
		counter2 = 0;
	if (zapper1Cor.x <= -158)
		zapper1Cors();
}
//-----------------------------------------------
void zapper2Cors(){
	srand(time(NULL));
	rand2 = rand() % 262;
	zapper2Cor.x = windowWidth*1.33 ;
	zapper3Cor.y = rand2;
	//zapper2Cor.y = 
}
//----------------------------------------------
void zapper2Shower(){

	if (counter3 % 4 == 0){
		SBDL::showTexture(zapper2[0], zapper2Cor.x, zapper2Cor.y);
		zapper2Cor.x += vel_background;
	}
	if (counter3 % 4 == 1){
		SBDL::showTexture(zapper2[1], zapper2Cor.x, zapper2Cor.y);
		zapper2Cor.x += vel_background;
	}
	if (counter3 % 4 == 2){
		SBDL::showTexture(zapper2[2], zapper2Cor.x, zapper2Cor.y);
		zapper2Cor.x += vel_background;
	}
	if (counter3 % 4 == 3){
		SBDL::showTexture(zapper2[3], zapper2Cor.x, zapper2Cor.y);
		zapper2Cor.x += vel_background;
	}
	counter3++;
	if (counter3 > 4)
		counter3 = 0;
	if (zapper2Cor.x <= -145){
		zapper2Cors();
	}
}

//----------------------------------------------

void zapper3Cors(){
	srand(time(NULL));
	//rand3 = 
	zapper3Cor.x = windowWidth*2.5;
	zapper3Cor.y = rand() % 242; 

}
//------------------------------------------
void zapper3Shower(){
	if (counter4 % 4 == 0){
		SBDL::showTexture(zapper3[0], zapper3Cor.x, zapper3Cor.y);
		zapper3Cor.x += vel_background;
	}
	if (counter4 % 4 == 1){
		SBDL::showTexture(zapper3[1], zapper3Cor.x, zapper3Cor.y);
		zapper3Cor.x += vel_background;
	}
	if (counter4 % 4 == 2){
		SBDL::showTexture(zapper3[2], zapper3Cor.x, zapper3Cor.y);
		zapper3Cor.x += vel_background;
	}
	if (counter4 % 4 == 3){
		SBDL::showTexture(zapper3[3], zapper3Cor.x, zapper3Cor.y);
		zapper3Cor.x += vel_background;
	}
	counter4++;
	if (counter4 > 4)
		counter4 = 0;
	if (zapper3Cor.x <= -58)
		zapper3Cors();
}
void laserCor(){
	laserCors = { 0, 0 };
}

void laserShower(){
	if (counter7 < 4000 && counter7>2500 && counter7 % 4 == 0)
		SBDL::showTexture(lasers[0], laserCors.x, laserCors.y);
	if (counter7 >= 4000 && counter7 <6500 && counter7 % 2 == 0)
		SBDL::showTexture(lasers[1], laserCors.x, laserCors.y);
	if (counter7 >= 6500 && counter7 < 9000 && counter7 % 2 == 1)
		SBDL::showTexture(lasers[2], laserCors.x, laserCors.y);
	counter7++;
	if (counter7 >= 20000)
		counter7 = 0;

}
//----------------------------------------
/*void random(){
	temp = rand() % 10;
	if (temp == 1)
		zapper1Shower();
	return;
	if (temp == 2)
		zapper2Shower();
	return;
	if (temp == 0)
		zapper3Shower();
	return;
}*/
//-------------------------------------------
void pauseFunc(){
	SBDL::stopMusic();
	SBDL::showTexture(background_, 0, 0);
	SBDL::showTexture(resume, windowWidth - 173, windowHeight - 60);
	if (SBDL::mouseInRect(resumeButtonRect) && SBDL::Mouse.clicked()){
		gameState = playing;
		forMusic();
	}
}
//-------------------------------------------
void Setting() {
	SBDL::showTexture(background_, 0, 0);
	SBDL::showTexture(soundOn, windowWidth - 179, 115);
	SBDL::showTexture(soundOff, windowWidth - 179, 50);
	SBDL::showTexture(back, 15, windowHeight - 75);
	
	backbuttonRect = { 15, windowHeight - 75, 173, 60 };
	soundOnRect = { windowWidth - 179, 115, 173, 60 };
	soundOffRect = { windowWidth - 179, 50, 173, 60 };
	if (SBDL::mouseInRect(backbuttonRect) && SBDL::Mouse.clicked())
		gameState = menu;
	if (SBDL::mouseInRect(soundOffRect) && SBDL::Mouse.clicked() && music_bool == true){
		SBDL::stopMusic();
		music_bool = false;
	}
	if (SBDL::mouseInRect(soundOnRect) && SBDL::Mouse.clicked() && music_bool == false ){
		forMusic();
	}
}
//-------------------------------------------
void Menu() {
	playButtonRect = { windowWidth - 179, 50,play.width , play.height };
	quitButtonRect = { windowWidth - 179,180 , 173, 60 };
	settingButtonRect = { windowWidth - 179, 115,173,60 };
	pauseButtonRect = { windowWidth - 55, 0, 50, 50 };
	resumeButtonRect = { windowWidth - 173, windowHeight - 60, 173, 60 };
	SBDL::showTexture(background_, 0, 0);
	SBDL::showTexture(play, windowWidth -179, 50);
	SBDL::showTexture(setting, windowWidth - 179, 115);
	SBDL::showTexture(quit,windowWidth - 179, 180);
	if (SBDL::keyPressed(SDL_SCANCODE_S))
		gameState = playing;
	if (SBDL::mouseInRect(playButtonRect) && SBDL::Mouse.clicked()){
		gameState = playing;
	}
	if (SBDL::mouseInRect(quitButtonRect) && SBDL::Mouse.clicked())
		gameState = exitting;
	if (SBDL::keyPressed(SDL_SCANCODE_Q))
		gameState = exitting;
	if (SBDL::mouseInRect(settingButtonRect) && SBDL::Mouse.clicked()){
		gameState = settings;
	}

}
//------------------------------------------
void Losing(){
	SBDL::stopMusic();
	barryRect = { BarryCor.x, BarryCor.y, 45, 54 };
	zapper1Rect = { zapper1Cor.x, zapper1Cor.x, 150, 73 };
	zapper2Rect = { zapper2Cor.x, zapper2Cor.y, 181, 172 };
	zapper3Rect = { zapper3Cor.x, zapper3Cor.y, 73, 150 };
	laserRect = { 0, 0, 487, 48 };
	retryButtonRect = { 585, 300, 171, 60 };
	quit2ButtonRect = { 225, 300, 171, 60 };
	back2ButtonRect = { 405, 300, 171, 60 };
	SBDL::showTexture(gameOver, 0, 0);
	SBDL::showTexture(retry, 585, 300);
	SBDL::showTexture(back, 405, 300);
	SBDL::showTexture(quit, 225, 300);
	if (SBDL::mouseInRect(retryButtonRect) && SBDL::Mouse.clicked())
		gameState = start;
	if (SBDL::keyPressed(SDL_SCANCODE_I))
		gameState = start;
	if (SBDL::mouseInRect(quit2ButtonRect) && SBDL::Mouse.clicked())
		exit(0);
	if (SBDL::mouseInRect(back2ButtonRect) && SBDL::Mouse.clicked()){
		forMusic();
		gameState = menu;
	}
}
//-----------------------------------------
void PLAYING(){
	spaceHeld();
	TextureShower();
	showBarryRun();
	zapper1Shower();
	zapper2Shower();
	zapper3Shower();
	showScientist();
	showScientist2();
	showScientist3();
	misslesShower();
	laserShower();   
	zapper1Rect = { zapper1Cor.x, zapper1Cor.y, 158, 58 };
	zapper2Rect = { zapper2Cor.x, zapper2Cor.y, 30, 90 };
	zapper3Rect = { zapper3Cor.x, zapper3Cor.y, 58, 158 };
	//laserRect = { 0, 0, 487, 48 };
	barryRect = { BarryCor.x, BarryCor.y, 45, 54 };
	if (SBDL::mouseInRect(pauseButtonRect) && SBDL::Mouse.clicked())
		gameState = pausing;
	if (SBDL::hasIntersectionRect(zapper1Rect, barryRect) ){
		gameState = losing;
	}
	if (SBDL::hasIntersectionRect(zapper2Rect, barryRect)){
		gameState = losing;
	}
	if (SBDL::hasIntersectionRect(zapper3Rect , barryRect)){
		gameState = losing;
	}
	//if (SBDL::hasIntersectionRect(laserRect, barryRect))            //this part is for losing by impacting to lasers!!!!!!!

		//gameState = losing;
}
//--------------------------------------------
void initialize(){
	backgroundsCor();
	BarryCor = { windowWidth / (6), 325 };
	zapper1Cors();
	zapper2Cors();
	zapper3Cors();
	scientistCor();
	scientistCor2();
	scientistCor3();
	misslesCor();
	forMusic();
	laserCor();

	gameState = playing;	
}
//------------------------------------------

int main(int argc, char *argv[]){


	const int FPS = 75;
	const int delay = 1000 / FPS;

	SBDL::InitEngine("JetPack JoyRide", windowWidth, windowHeight);
	gameState = menu;
	BarryCor = { windowWidth / (6), 325};

	
	/*
	FlippingThing coins;
	coins.images = new Texture[6];
	coins.size = 6;
	coins.currentIndex = 0;
	coins.folderAddress = "assets/pic/coins/";

*/

	Keeper();
	backgroundsCor();
	TextureShower();
	Setting();
	zapper2Cors();
	zapper1Cors();
	zapper3Cors();
	scientistCor();
	scientistCor2();
	scientistCor3();
	misslesCor();
	laserCor();
	forMusic();
	
	while (SBDL::isRunning()){

		int loopSratTime = SBDL::getTime();
		time_for_lazers++;

		SBDL::updateEvents();
		SBDL::updateRenderScreen();

		if (gameState == menu){
			Menu();
			if (SBDL::mouseInRect(playButtonRect) && SBDL::Mouse.clicked())
				initialize();
		}


		else if (gameState == losing){
			Losing();
		}
		else if (gameState == start){
			initialize();
		}
		else if (gameState == exitting)
			exit(0);
		else if (gameState == settings)
			Setting();
		else if (gameState == pausing)
			pauseFunc();

		else if (gameState = playing) {
			PLAYING();

		}
	}
	return 0;
}

