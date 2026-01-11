#include "iGraphics.h"
#include "bitmap_loader.h"
#define screenwidth 1920
#define screenheight 1080
#define backgroundspeed 5
#define level1_obstaclespeed 10
#define level2_obstaclespeed 50
#define projectname Flying Witch

int gamestate = 0, image1, image2, image3, image4, image5, ps;
int l1_bgimage[2],l2_bgimage[2], mainChar_x = 20, mainChar_y = 500;
int mainChar, level = 0;
long double Score=0;
char s[10000];

int obs_image_l1_lower[3],obs_image_l1_upper[3];
int obs_image_l2_lower[3], obs_image_l2_upper[3];

struct background{
	int x;
	int y;
};

background bg1[2];
background bg2[2];

int minObsHeight = 40;
int maxObsHeight = 500;

struct lower_obstacles{

	int x = 0;
	int dx = 100;
	int y = 0;
	int dy = 250;
};

lower_obstacles l1_down_obs[6];
lower_obstacles l2_down_obs[6];
struct upper_obstacles{
	int x = 500;
	int dx = 100;
	int y = 500;
	int dy = 250;
};
upper_obstacles l1_upper_obs[6];
upper_obstacles l2_upper_obs[6];
/*
function iDraw() is called again and again by the system.

*/



void iDraw()
{
	
	iClear();
	if (gamestate == 0)
	{
		iShowImage(0, 0, 1920, 1080, image1);
	}

	else if (gamestate == 1){
		iShowImage(0, 0, 1920, 1080, image2);
		
		if (level==1){
			
				iShowImage(bg1[0].x, bg1[0].y, 2000, 1080, l1_bgimage[0]);
				iShowImage(bg1[1].x, bg1[1].y, 2000, 1080, l1_bgimage[1]);
				
				iShowImage(mainChar_x, mainChar_y, 200, 151, mainChar);
				
				iShowImage(l1_down_obs[0].x, l1_down_obs[0].y, l1_down_obs[0].dx, l1_down_obs[0].dy, obs_image_l1_lower[0]);
				iShowImage(l1_down_obs[1].x, l1_down_obs[1].y, l1_down_obs[1].dx, l1_down_obs[1].dy, obs_image_l1_lower[1]);
				iShowImage(l1_down_obs[2].x, l1_down_obs[2].y, l1_down_obs[2].dx, l1_down_obs[2].dy, obs_image_l1_lower[2]);
				iShowImage(l1_down_obs[3].x, l1_down_obs[3].y, l1_down_obs[3].dx, l1_down_obs[4].dy, obs_image_l1_lower[0]);
				iShowImage(l1_down_obs[4].x, l1_down_obs[4].y, l1_down_obs[4].dx, l1_down_obs[4].dy, obs_image_l1_lower[1]);
				iShowImage(l1_down_obs[5].x, l1_down_obs[5].y, l1_down_obs[5].dx, l1_down_obs[5].dy, obs_image_l1_lower[2]);

				iShowImage(l1_upper_obs[0].x, l1_upper_obs[0].y, l1_upper_obs[0].dx, l1_upper_obs[0].dy, obs_image_l1_upper[0]);
				iShowImage(l1_upper_obs[1].x, l1_upper_obs[1].y, l1_upper_obs[1].dx, l1_upper_obs[1].dy, obs_image_l1_upper[1]);
				iShowImage(l1_upper_obs[2].x, l1_upper_obs[2].y, l1_upper_obs[2].dx, l1_upper_obs[2].dy, obs_image_l1_upper[2]);
				iShowImage(l1_upper_obs[3].x, l1_upper_obs[3].y, l1_upper_obs[3].dx, l1_upper_obs[4].dy, obs_image_l1_upper[0]);
				iShowImage(l1_upper_obs[4].x, l1_upper_obs[4].y, l1_upper_obs[4].dx, l1_upper_obs[4].dy, obs_image_l1_upper[1]);
				iShowImage(l1_upper_obs[5].x, l1_upper_obs[5].y, l1_upper_obs[5].dx, l1_upper_obs[5].dy, obs_image_l1_upper[2]);
				
		}
		
		if (level == 2){
			
			iShowImage(bg2[0].x, bg2[0].y, 2000, 1080, l2_bgimage[0]);
			iShowImage(bg2[1].x, bg2[1].y, 2000, 1080, l2_bgimage[1]);
			
			iShowImage(mainChar_x, mainChar_y, 200, 151, mainChar);

			iShowImage(l2_down_obs[0].x, l2_down_obs[0].y, l2_down_obs[0].dx, l2_down_obs[0].dy, obs_image_l2_lower[0]);
			iShowImage(l2_down_obs[1].x, l2_down_obs[1].y, l2_down_obs[1].dx, l2_down_obs[1].dy, obs_image_l2_lower[1]);
			iShowImage(l2_down_obs[2].x, l2_down_obs[2].y, l2_down_obs[2].dx, l2_down_obs[2].dy, obs_image_l2_lower[2]);
			iShowImage(l2_down_obs[3].x, l2_down_obs[3].y, l2_down_obs[3].dx, l2_down_obs[4].dy, obs_image_l2_lower[0]);
			iShowImage(l2_down_obs[4].x, l2_down_obs[4].y, l2_down_obs[4].dx, l2_down_obs[4].dy, obs_image_l2_lower[1]);
			iShowImage(l2_down_obs[5].x, l2_down_obs[5].y, l2_down_obs[5].dx, l2_down_obs[5].dy, obs_image_l2_lower[2]);

			iShowImage(l2_upper_obs[0].x, l2_upper_obs[0].y, l2_upper_obs[0].dx, l2_upper_obs[0].dy, obs_image_l2_upper[0]);
			iShowImage(l2_upper_obs[1].x, l2_upper_obs[1].y, l2_upper_obs[1].dx, l2_upper_obs[1].dy, obs_image_l2_upper[1]);
			iShowImage(l2_upper_obs[2].x, l2_upper_obs[2].y, l2_upper_obs[2].dx, l2_upper_obs[2].dy, obs_image_l2_upper[2]);
			iShowImage(l2_upper_obs[3].x, l2_upper_obs[3].y, l2_upper_obs[3].dx, l2_upper_obs[4].dy, obs_image_l2_upper[0]);
			iShowImage(l2_upper_obs[4].x, l2_upper_obs[4].y, l2_upper_obs[4].dx, l2_upper_obs[4].dy, obs_image_l2_upper[1]);
			iShowImage(l2_upper_obs[5].x, l2_upper_obs[5].y, l2_upper_obs[5].dx, l2_upper_obs[5].dy, obs_image_l2_upper[2]);

		}
	}

	if (gamestate == 2){
		iShowImage(0, 0, 1920, 1080, image3);
	}
	if (gamestate == 3){
		//PlaySound("music\\GameOver.wav", NULL, SND_LOOP | SND_ASYNC);
		iShowImage(500, 500, 800, 450, image5);
		iText(810, 710, s, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	

}

void iPassiveMouse(int x, int y)
{
	;
}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/



void iMouse(int button, int state, int mx, int my)
{
	if (gamestate == 0){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here
			printf("mx = %d, my= %d\n", mx, my);
			if (mx >= 720 && mx<1100 && my >= 702 && my<790){
				gamestate = 1;
			}

			if (mx >= 720 && mx < 1100 && my >= 530 && my < 640){
				gamestate = 2;
			}

			if (mx >= 720 && mx < 1100 && my >= 340 && my < 460){
				exit(0);
			}
			

		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here

		}

	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	if (key == 'b')
	{
		gamestate = 0;
	}
	if (key == 'e')
	{
		level=1;
		PlaySound("music\\level1.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (key == 'h'){
		level = 2;
		PlaySound("music\\level2.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_LEFT)
	{
		mainChar_x -= 10;
		if (mainChar_x <= 0)
			mainChar_x = 20;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		mainChar_x += 10;
		if (mainChar_x >= (screenwidth - 10))
		{
			mainChar_x = 200;
		}

	}
	if (key == GLUT_KEY_UP)
	{
		mainChar_y += 10;
	}
	if (key == GLUT_KEY_DOWN)
	{
		mainChar_y -= 10;
	}

	//place your codes for other keys here
}

void bgRendering(){
	if (level == 1){
		for (int i = 0; i < 2; i++){
			bg1[i].x -= backgroundspeed;
			if (bg1[i].x <= -2000){
				bg1[i].x = 1980;
			}
		}
	}

	if (level == 2){
		for (int i = 0; i < 2; i++){
				bg2[i].x -= backgroundspeed;
				if (bg2[i].x <= -2000){
					bg2[i].x = 1980;
				}
			}
	}
	
}



void obsticles_rendering(){

	if (level == 1){
		for (int i = 0; i < 6; i++){
			l1_down_obs[i].x -= level1_obstaclespeed;

			l1_down_obs[i].dy = minObsHeight + rand() % maxObsHeight;

			if (l1_down_obs[i].x == 0){
				l1_down_obs[i].x = 1980;
			}

			l1_upper_obs[i].x -= level1_obstaclespeed;
			l1_upper_obs[i].dy = maxObsHeight + rand() % minObsHeight;
			if (l1_upper_obs[i].x == 0){
				l1_upper_obs[i].x = 1980;
			}
		}
		Score += 0.5;
	}

	if (level == 2){
		for (int i = 0; i < 6; i++){
			l2_down_obs[i].x -= level2_obstaclespeed;

			l2_down_obs[i].dy = minObsHeight + rand() % maxObsHeight;

			if (l2_down_obs[i].x == 0){
				l2_down_obs[i].x = 1980;
			}

			l2_upper_obs[i].x -= level2_obstaclespeed;
			l2_upper_obs[i].dy = maxObsHeight + rand() % minObsHeight;
			if (l2_upper_obs[i].x == 0){
				l2_upper_obs[i].x = 1980;
			}
		}
		Score += 0.5;
	}

}

void collision()
{
	if (level == 1){
		for (int i = 0; i < 6; i++)
		{
			if (((mainChar_x >= l1_down_obs[i].x) && (mainChar_x <= l1_down_obs[i].x + l1_down_obs[i].dx)) && ((mainChar_y >= l1_down_obs[i].y) && (mainChar_y <= l1_down_obs[i].y + l1_down_obs[i].dy)))
			{
				
				gamestate = 3;
				iPauseTimer(ps);
			}
			if ((((mainChar_x + 150 >= l1_upper_obs[i].x) && (mainChar_x <= l1_upper_obs[i].x + l1_upper_obs[i].dx)) && ((mainChar_y + 130 >= l1_upper_obs[i].y) && (mainChar_y <= l1_upper_obs[i].y + l1_upper_obs[i].dy)))){
				
				gamestate = 3;
				iPauseTimer(ps);
			}
		}
	}

	if (level == 2){
		for (int i = 0; i < 6; i++)
		{
			if (((mainChar_x >= l2_down_obs[i].x) && (mainChar_x <= l2_down_obs[i].x + l2_down_obs[i].dx)) && ((mainChar_y >= l2_down_obs[i].y) && (mainChar_y <= l2_down_obs[i].y + l2_down_obs[i].dy)))
			{
				gamestate = 3;
				iPauseTimer(ps);
			}
			if ((((mainChar_x + 150 >= l2_upper_obs[i].x) && (mainChar_x <= l2_upper_obs[i].x + l2_upper_obs[i].dx)) && ((mainChar_y + 130 >= l2_upper_obs[i].y) && (mainChar_y <= l2_upper_obs[i].y + l2_upper_obs[i].dy)))){
				gamestate = 3;
				iPauseTimer(ps);
			}
		}
	}

}

void ScoreShow(){
	itoa(Score, s, 10);
}


int main()
{
	//place your own initialization codes here.

	iInitialize(screenwidth, screenheight, "Flying Witch");
	l1_bgimage[0] = iLoadImage("images\\bg1.1.jpg");
	l1_bgimage[1] = iLoadImage("images\\bg1.2.jpg");

	l2_bgimage[0] = iLoadImage("images\\bg2.1.jpg");
	l2_bgimage[1] = iLoadImage("images\\bg2.2.jpg");
	
	image1 = iLoadImage("images\\CoverPage.png");
	image2 = iLoadImage("images\\Level.png");
	image3 = iLoadImage("images\\About.png");
	
	PlaySound("music\\mainmenu.wav", NULL, SND_LOOP | SND_ASYNC);


	mainChar = iLoadImage("images\\MainChar1.png");

	bg1[0].x = 0;
	bg1[0].y = 0;
	bg1[1].x = 2000;
	bg1[1].y = 0;

	bg2[0].x = 0;
	bg2[0].y = 0;
	bg2[1].x = 2000;
	bg2[1].y = 0;
	iSetTimer(5, bgRendering);

	obs_image_l1_lower[0] = iLoadImage("images\\l1_down_obs_l.png");
	obs_image_l1_lower[1] = iLoadImage("images\\l1_down_obs_s.png"); 
	obs_image_l1_lower[2] = iLoadImage("images\\l1_down_obs_m.png");
	//l2_down_obs_l .png


	obs_image_l1_upper[0] = iLoadImage("images\\l1_upper_obs_l.png");
	obs_image_l1_upper[1] = iLoadImage("images\\l1_upper_obs_s.png");
	obs_image_l1_upper[2] = iLoadImage("images\\l1_upper_obs_m.png");
	
	obs_image_l2_lower[0] = iLoadImage("images\\l2_down_obs_l.png");
	obs_image_l2_lower[1] = iLoadImage("images\\l2_down_obs_s.png");
	obs_image_l2_lower[2] = iLoadImage("images\\l2_down_obs_m.png");


	obs_image_l2_upper[0] = iLoadImage("images\\l2_upper_obs_l.png");
	obs_image_l2_upper[1] = iLoadImage("images\\l2_upper_obs_s.png");
	obs_image_l2_upper[2] = iLoadImage("images\\l2_upper_obs_m.png");

	image5 = iLoadImage("images\\GameOver.png");

	int lower_obsInitX = 1000; 
	int lower_obsInitY = 0;
	for (int i = 0; i < 6; i++){
		l1_down_obs[i].x = lower_obsInitX + 150;
		l1_down_obs[i].y = 0;
		lower_obsInitX += 200;
	}

	int upper_obsInitX = 1000;
	int upper_obsInitY = 540;
	for (int i = 0; i < 6; i++){
		l1_upper_obs[i].x = upper_obsInitX + 150;
		l1_upper_obs[i].y = 650+ rand()% 100;
		upper_obsInitX += 200;
	}

	
	
	for (int i = 0; i < 6; i++){
		l2_down_obs[i].x = lower_obsInitX + 150;
		l2_down_obs[i].y = 0;
		lower_obsInitX += 200;
	}

	
	for (int i = 0; i < 6; i++){
		l2_upper_obs[i].x = upper_obsInitX + 150;
		l2_upper_obs[i].y = 650 + rand() % 100;
		upper_obsInitX += 200;
	}
	
	iSetTimer(250, obsticles_rendering);
	
	
	iSetTimer(1, collision);
	ps = iSetTimer(160, ScoreShow);

	iStart(); // it will start drawing

	return 0;
}

