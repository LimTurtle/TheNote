#include <stdio.h>

#include <time.h>

#include <Windows.h>

//수정 필요한 것 ///////////1 부터 /////////////2 사이에 있음

#define BufferWidth 100
#define BufferHeight 100

#define Y0 5



#define X0 20



#define YE 55



#define XE 60



#define NoteCount 30


typedef struct Obj

{

	int x;



	int y;



	const char*shape;



	bool act;



}Note,Start,Exit;



Note*note[NoteCount];

Start*easy;
Start*normal;
Start*hard;
Start*cursor;
Exit*exi;
char sNum[5];

enum STATE_ID



{



	LOGO,



	MENU,



	STAGE,



	EXIT,



};







enum Color



{



	검정색,



	파란색,



	초록색,



	옥색,



	빨간색,



	자주색,



	노란색,



	흰색,



	회색,



	연한파란색,



	연한초록색,



	연한옥색,



	연한빨간색,



	연한자주색,



	진한노란색,



};







enum Dir



{



	go_up,



	go_down,



};



Dir dir;


//더블버퍼
void InitDoubleBuffer();
void WriteBuffer(int x, int y, const char*shape, int color);
void FlipBuffer();
void ClearBuffer();
void DestroyBuffer();
//더블 버퍼 변수
HANDLE hBuffer[2];
int screenIndex;


//void SetCursorHandle();
//
//
//
//void SetCursorPosition(int _x, int _y);
//
//
//
//
//
//
//
//void SetTextColor(int _index);







//씬 관리해주는 아이



void SetState();



STATE_ID state;







//로고



void LogoInit();

void LogoProgress();

void LogoRender();



void MenuInit();

void MenuProgress();

void MenuRender();



void StageInit();

void StageProgress();

void StageRender();


void ExitInit();

void ExitProgress();

void ExitRender();


const char*logoImg[21];







int a;



int b;



int combo;
const char*rank;
int point;
int life;
int maxCombo;

int aniNum;







void LogoAni01();



void LogoAni02();



void LogoAni03();



void LogoAni04();



void LogoAni05();



float deltaTime;
float deltMax;

int MenuIndex;

void main()



{

	srand((unsigned)time(NULL));



	a = 10;



	b = 10;

	MenuIndex = 0;

	combo = 0;
	rank = "";
	point = 0;
	life = 10;
	maxCombo = 0;

	dir = go_up;



	InitDoubleBuffer();






	state = LOGO;







	aniNum = 0;



	deltaTime = 0.0f;
	deltMax = 0.0f;


	DWORD dwTime = GetTickCount();







	LogoInit();

	MenuInit();

	StageInit();

	ExitInit();



	while (true)



	{



		if (dwTime + 50 < GetTickCount())



		{



			dwTime = GetTickCount();



			//system("cls");



			SetState();

			FlipBuffer();
			ClearBuffer();



		}



	}



}







void LogoAni01()



{



	logoImg[0] = " MMMMMMMMMMMM	";

	logoImg[1] = " MMMMMMMMMMMM	";

	logoImg[2] = "        MMMM 	";

	logoImg[3] = "        MMMM 	";

	logoImg[4] = "        MMMM 	";

	logoImg[5] = "        MMMM 	";

	logoImg[6] = "        MMMM 	";

	logoImg[7] = "        MMMM 	";

	logoImg[8] = "        MMMM 	";

	logoImg[9] = " 				";

	logoImg[10] = " MMMM      MM";

	logoImg[11] = " MMMMM     MM";

	logoImg[12] = " MMMMMM    MM";

	logoImg[13] = " MMM MMM   MM";

	logoImg[14] = " MMM  MMM  MM";

	logoImg[15] = " MMM   MMM MM";

	logoImg[16] = " MMM    MMMMM";

	logoImg[17] = " MMM     MMMM";

	logoImg[18] = "";

	logoImg[19] = "";

	logoImg[20] = "					<Press Enter Key>";

}



void LogoAni02()



{

	logoImg[0] = " MMMMMMMMMMMMMMMMMM     M	 ";

	logoImg[1] = " MMMMMMMMMMMMMMMMMM     M	 ";

	logoImg[2] = "        MMMM            M	 ";

	logoImg[3] = "        MMMM            M	 ";

	logoImg[4] = "        MMMM            M	 ";

	logoImg[5] = "        MMMM            M	 ";

	logoImg[6] = "        MMMM            M	 ";

	logoImg[7] = "        MMMM            M	 ";

	logoImg[8] = "        MMMM            M	 ";

	logoImg[9] = " 							 ";

	logoImg[10] = " MMMM      MMM          	 ";

	logoImg[11] = " MMMMM     MMM       MM   ";

	logoImg[12] = " MMMMMM    MMM      MM MM ";

	logoImg[13] = " MMM MMM   MMM     MMM  M ";

	logoImg[14] = " MMM  MMM  MMM     MMM    ";

	logoImg[15] = " MMM   MMM MMM     MMM  M ";

	logoImg[16] = " MMM    MMMMMM      MM  M ";

	logoImg[17] = " MMM     MMMMM       MMM  ";

	logoImg[18] = "";

	logoImg[19] = "";

	logoImg[20] = "					<Press Enter Key>";

}



void LogoAni03()



{

	logoImg[0] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMM ";

	logoImg[1] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMM ";

	logoImg[2] = "        MMMM            MMM          MMM   ";

	logoImg[3] = "        MMMM            MMM MMMM     MMMMM ";

	logoImg[4] = "        MMMM            MMMMMMMMM    MMMMM ";

	logoImg[5] = "        MMMM            MMM    MMM   MMM   ";

	logoImg[6] = "        MMMM            MMM    MMM   MMM   ";

	logoImg[7] = "        MMMM            MMM    MMM   MMMMM ";

	logoImg[8] = "        MMMM            MMM    MMM   MMMMM ";

	logoImg[9] = " 											 ";

	logoImg[10] = " MMMM      MMM                            ";

	logoImg[11] = " MMMMM     MMM       MM         MM        ";

	logoImg[12] = " MMMMMM    MMM      MM MM       MM        ";

	logoImg[13] = " MMM MMM   MMM     MMM  MMM   MMMMMM      ";

	logoImg[14] = " MMM  MMM  MMM     MMM   MM     MM       M";

	logoImg[15] = " MMM   MMM MMM     MMM  MMM     MM       M";

	logoImg[16] = " MMM    MMMMMM      MM  M       MM       M";

	logoImg[17] = " MMM     MMMMM       MMM         MMM      ";

	logoImg[18] = "";

	logoImg[19] = "";

	logoImg[20] = "					<Press Enter Key>";

}



void LogoAni04()



{

	logoImg[0] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMMMMMM        ─────  ";

	logoImg[1] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMMMMMM                M	";

	logoImg[2] = "        MMMM            MMM          MMM              ────M	";

	logoImg[3] = "        MMMM            MMM MMMM     MMMMMMMMM                M	";

	logoImg[4] = "        MMMM            MMMMMMMMM    MMMMMMMMM        ────M	";

	logoImg[5] = "        MMMM            MMM    MMM   MMM                    MMM	";

	logoImg[6] = "        MMMM            MMM    MMM   MMM              ──MMMMM	";

	logoImg[7] = "        MMMM            MMM    MMM   MMMMMMMMM             MMM 	";

	logoImg[8] = "        MMMM            MMM    MMM   MMMMMMMMM        ─────  ";

	logoImg[9] = " 											     ";

	logoImg[10] = " MMMM      MMM                                         MMM     	";

	logoImg[11] = " MMMMM     MMM       MM         MM              ───MMMMM──  ";

	logoImg[12] = " MMMMMM    MMM      MM MM       MM                   MMM       	";

	logoImg[13] = " MMM MMM   MMM     MMM  MMM   MMMMMM      MMM    ──M────   ";

	logoImg[14] = " MMM  MMM  MMM     MMM   MM     MM       M   M       MMMMMMMMMM	";

	logoImg[15] = " MMM   MMM MMM     MMM  MMM     MM       MMMMM   ──M────   ";

	logoImg[16] = " MMM    MMMMMM      MM  M       MM       M           MMMMMMMMMM	";

	logoImg[17] = " MMM     MMMMM       MMM         MMM      MMM    ───────	";

	logoImg[18] = "";

	logoImg[19] = "";

	logoImg[20] = "					<Press Enter Key>";

}



void LogoAni05()



{

	logoImg[0] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMMMMMM        ──────── M──   ";

	logoImg[1] = " MMMMMMMMMMMMMMMMMM     MMM          MMMMMMMMM                MM       M       ";

	logoImg[2] = "        MMMM            MMM          MMM              ────MMM───M─── ";

	logoImg[3] = "        MMMM            MMM MMMM     MMMMMMMMM                M M    MMM       ";

	logoImg[4] = "        MMMM            MMMMMMMMM    MMMMMMMMM        ────M M─MMMMM─── ";

	logoImg[5] = "        MMMM            MMM    MMM   MMM                    MMM     MMM        ";

	logoImg[6] = "        MMMM            MMM    MMM   MMM              ──MMMMM───────  ";

	logoImg[7] = "        MMMM            MMM    MMM   MMMMMMMMM             MMM                 ";

	logoImg[8] = "        MMMM            MMM    MMM   MMMMMMMMM        ───────────   ";

	logoImg[9] = " 			                               ";

	logoImg[10] = " MMMM      MMM                                         MMM                   ";

	logoImg[11] = " MMMMM     MMM       MM         MM              ───MMMMM───MMM────	";

	logoImg[12] = " MMMMMM    MMM      MM MM       MM                   MMM       MMMMM         ";

	logoImg[13] = " MMM MMM   MMM     MMM  MMM   MMMMMM      MMM    ──M──── MMM────   ";

	logoImg[14] = " MMM  MMM  MMM     MMM   MM     MM       M   M       MMMMMMMMMMM				";

	logoImg[15] = " MMM   MMM MMM     MMM  MMM     MM       MMMMM   ──M──── M─────	";

	logoImg[16] = " MMM    MMMMMM      MM  M       MM       M           MMMMMMMMMM              ";

	logoImg[17] = " MMM     MMMMM       MMM         MMM      MMM    ─────────────  ";

	logoImg[18] = "";

	logoImg[19] = "";

	logoImg[20] = "					<Press Enter Key>";

}







void SetState()



{



	switch (state)



	{



	case LOGO:







		LogoProgress();



		LogoRender();



		break;







	case MENU:



		MenuProgress();

		MenuRender();



		break;





	case STAGE:



	{

		StageProgress();

		StageRender();

		break;



	}



	case EXIT:



	{

		ExitProgress();

		ExitRender();

		break;



	}



	default:



	{



		break;



	}



	}



}







void LogoInit()



{



	LogoAni01();



	LogoAni02();



	LogoAni03();



	LogoAni04();



	LogoAni05();



}



void LogoProgress()



{



	if (GetAsyncKeyState(VK_RETURN) & 0x0001)



	{



		state = MENU;



	}



}



void LogoRender()



{



	if (aniNum < 0)



	{



		dir = go_up;



	}







	if (aniNum > 6)



	{



		dir = go_down;



	}











	if (dir == go_up)



	{



		aniNum++;



	}



	else if (dir == go_down)



	{



		aniNum--;



	}











	switch (aniNum)



	{



	case 0:



		LogoAni01();



		break;



	case 1:



		LogoAni02();



		break;



	case 2:



		LogoAni03();



		break;



	case 3:



		LogoAni04();



		break;



	case 4:



		LogoAni05();



		break;



	default:



		break;



	}



	for (int i = 0; i < 21; i++)



	{



		if (i < 9)
		
		
		
		{
		
		
		
			WriteBuffer(a, b + i, logoImg[i], 흰색);
		
		
		
		}
		
		
		
		else if (i < 18)
		
		
		
		{
		
		
		
			WriteBuffer(a, b + i, logoImg[i], 연한옥색);
		
		
		
		}
		
		
		
		else
		
		{
		
			WriteBuffer(a, b + i, logoImg[i], 흰색);
		
		}


		



	}



	//SetTextColor(흰색);



}



void MenuInit()

{
	easy = (Start*)malloc(sizeof(Start));
	easy->x = 10;
	easy->y = 42;
	easy->shape = "쉬움";
	easy->act = false;

	normal = (Start*)malloc(sizeof(Start));
	normal->x = 30;
	normal->y = 42;
	normal->shape = "보통";
	normal->act = false;

	hard = (Start*)malloc(sizeof(Start));
	hard->x = 50;
	hard->y = 42;
	hard->shape = "어려움";
	hard->act = false;
	
	exi = (Exit*)malloc(sizeof(Exit));
	exi ->x=70;
	exi->y = 42;
	exi->shape = "종료";
	exi->act = false;

	cursor = (Start*)malloc(sizeof(Start));
	cursor->x = 9;
	cursor->y = 42;
	cursor->shape = "▶";
	cursor->act = false;
}

void MenuProgress()

{
	if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
	{
		MenuIndex++;
	}


	if (GetAsyncKeyState(VK_LEFT) & 0x0001)
	{
		MenuIndex--;
	}

	if (MenuIndex < 0)
	{
		MenuIndex = 0;
	}

	if (MenuIndex > 3)
	{
		MenuIndex = 3;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		switch (MenuIndex)
		{
		case 0:
			deltMax = 2.5f;
			state = STAGE;
			break;
		case 1:
			deltMax = 1.5f;
			state = STAGE;
			break;
		case 2:
			deltMax = 0.5f;
			state = STAGE;
			break;
		case 3:
			state = EXIT;
			break;
		default:
			break;
		}
	}
}

void MenuRender()

{

	LogoAni05();

	for (int i = 0; i < 18; i++)



	{



		if (i < 9)
		
		
		
		{
		
		
		
			WriteBuffer(a, b + i, logoImg[i], 흰색);
		
		
		
		}
		
		
		
		else if (i < 18)
		
		
		
		{
		
		
		
			WriteBuffer(a, b + i, logoImg[i], 연한옥색);
		
		
		
		}
		
		
		
		else
		
		{
		
			WriteBuffer(a, b + i, logoImg[i], 흰색);
		
		}
		
		
		
		//SetCursorPosition(a, b + i);
		//
		//
		//
		//printf("%s", logoImg[i]);
		


	}

	//SetTextColor(흰색);
	//SetCursorPosition(easy->x, easy->y);
	//printf("%s", easy->shape);
	WriteBuffer(easy->x, easy->y, easy->shape, 흰색);
	//SetCursorPosition(normal->x, normal->y);
	//printf("%s", normal->shape);
	WriteBuffer(normal->x, normal->y, normal->shape, 흰색);
	//SetCursorPosition(hard->x, hard->y);
	//printf("%s", hard->shape);
	WriteBuffer(hard->x, hard->y, hard->shape, 흰색);
	//SetCursorPosition(exi->x, exi->y);
	//printf("%s", exi->shape);
	WriteBuffer(exi->x, exi->y, exi->shape, 흰색);
	switch (MenuIndex)
	{
	case 0:
		cursor->x = easy->x - 2;
		cursor->y = easy->y;
		//SetCursorPosition(cursor->x, cursor->y);
		//printf("%s", cursor->shape);
		WriteBuffer(cursor->x, cursor->y, cursor->shape, 흰색);
		break;
	case 1:
		cursor->x = normal->x - 2;
		cursor->y = normal->y;
		//SetCursorPosition(cursor->x, cursor->y);
		//printf("%s", cursor->shape);
		WriteBuffer(cursor->x, cursor->y, cursor->shape, 흰색);
		break;
	case 2:
		cursor->x = hard->x - 2;
		cursor->y = hard->y;
		//SetCursorPosition(cursor->x, cursor->y);
		//printf("%s", cursor->shape);
		WriteBuffer(cursor->x, cursor->y, cursor->shape, 흰색);
		break;
	case 3:
		cursor->x = exi->x - 2;
		cursor->y = exi->y;
		//SetCursorPosition(cursor->x, cursor->y);
		//printf("%s", cursor->shape);
		WriteBuffer(cursor->x, cursor->y, cursor->shape, 흰색);
		break;
	default:
		break;
	}
}



void StageInit()

{

	for (int i = 0; i < NoteCount; i++)

	{

		note[i] = (Note*)malloc(sizeof(Note));

		note[i]->x = 0;

		note[i]->y = 0;

		note[i]->shape = "─";

		note[i]->act = false;

	}

}



void StageProgress()

{

	if (life < 0)
	{
		state = EXIT;
	}

}



void StageRender()

{	

	for (int y = Y0; y < YE; y++)

	{





		for (int x = X0; x < XE; x += 2)







		{







			if (y == Y0 || x == X0 || y == YE - 1 || x == XE - 2)







			{



				if (y == Y0 && x == X0)



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("┌");
					WriteBuffer(x, y,"┌", 흰색);


				}



				else if (y == Y0 && x == XE - 2)



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("┐");
					WriteBuffer(x, y, "┐", 흰색);


				}



				else if (y == YE - 1 && x == X0)



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("└");
					WriteBuffer(x, y, "└", 흰색);



				}



				else if (y == YE - 1 && x == XE - 2)



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("┘");
					WriteBuffer(x, y, "┘", 흰색);



				}



				else if ((y == Y0 || y == YE - 1) && (x>X0 && x<XE - 2))



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("─");
					WriteBuffer(x, y, "─", 흰색);


				}



				else if ((y > Y0 && y < YE - 1) && (x == X0 || x == XE - 2))



				{



					//SetCursorPosition(x, y);
					//
					//
					//
					//
					//
					//
					//
					//printf("│");
					WriteBuffer(x, y, "│", 흰색);


				}



			}







			if (y == YE - 6 && (x>X0 && x<XE - 2))



			{



				//SetCursorPosition(x, y);
				//
				//
				//
				//printf("=");
				WriteBuffer(x, y, "=", 흰색);



			}



			if (y == YE - 5 && x == X0 + 4)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x53))







				{

					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 4 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 4 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 4 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}





					//SetTextColor(빨간색);
					//
					//
					//
					//
					//
					//
					//
					//printf("ⓢ");
					//
					//
					//
					//
					//
					//
					//
					//SetTextColor(흰색);

					WriteBuffer(x, y, "ⓢ", 빨간색);





				}







				else







				{







					//printf("ⓢ");
					WriteBuffer(x, y, "ⓢ", 흰색);






				}



			}



			if (y == YE - 5 && x == X0 + 10)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x44))







				{

					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 10 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 10 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 10 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}





					//SetTextColor(빨간색);







					//printf("ⓓ");
					WriteBuffer(x, y, "ⓓ", 빨간색);






					//SetTextColor(흰색);







				}







				else







				{







					//printf("ⓓ");
					WriteBuffer(x, y, "ⓓ", 흰색);






				}



			}



			if (y == YE - 5 && x == X0 + 16)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x46))







				{

					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 16 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 16 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 16 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}





					//SetTextColor(빨간색);







					//printf("ⓕ");
					WriteBuffer(x, y, "ⓕ", 빨간색);






					//SetTextColor(흰색);
					






				}







				else







				{







					//printf("ⓕ");
					WriteBuffer(x, y, "ⓕ", 흰색);






				}



			}



			if (y == YE - 5 && x == X0 + 22)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x4A))







				{



					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 22 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 22 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 22 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}



					//SetTextColor(빨간색);







					//printf("ⓙ");
					WriteBuffer(x, y, "ⓙ", 빨간색);






					//SetTextColor(흰색);







				}







				else







				{







					//printf("ⓙ");
					WriteBuffer(x, y, "ⓙ", 흰색);






				}



			}



			if (y == YE - 5 && x == X0 + 28)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x4B))







				{

					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 28 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 28 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 28 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}





					//SetTextColor(빨간색);







					//printf("ⓚ");
					WriteBuffer(x, y, "ⓚ", 빨간색);






					//SetTextColor(흰색);







				}







				else







				{







					//printf("ⓚ");
					WriteBuffer(x, y, "ⓚ", 흰색);






				}



			}



			if (y == YE - 5 && x == X0 + 34)



			{



				//SetCursorPosition(x, y);



				if (GetAsyncKeyState(0x4C))







				{



					for (int i = 0; i < NoteCount; i++)

					{

						if (note[i]->act == true)

						{

							if (note[i]->x == X0 + 34 && note[i]->y == YE - 6)

							{

								//그레이트 점수 획득
								combo++;
								point += 50;
								rank = "Great!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 34 && note[i]->y == YE - 5)

							{

								//퍼펙트 점수 획득
								combo++;
								point += 100;
								rank = "Perfect!";
								note[i]->act = false;

							}

							if (note[i]->x == X0 + 34 && note[i]->y == YE - 4)

							{

								//굿 점수 획득
								combo++;
								point += 10;
								rank = "Good!";
								note[i]->act = false;

							}

						}

					}



					//SetTextColor(빨간색);







					//printf("ⓛ");
					WriteBuffer(x, y, "ⓛ", 빨간색);






					//SetTextColor(흰색);







				}







				else







				{







					//printf("ⓛ");
					WriteBuffer(x, y, "ⓛ", 흰색);






				}



			}



			if (y == YE - 4 && (x>X0 && x<XE - 2))



			{



				//SetCursorPosition(x, y);



				//printf("=");
				WriteBuffer(x, y, "=", 흰색);


			}







		}







	}







	Sleep(50);





	deltaTime += 0.4f;



	if (deltaTime > deltMax)

	{

		for (int i = 0; i < NoteCount; i++)

		{

			if (note[i]->act == false)

			{

				note[i]->act = true;

				note[i]->x = rand() % (60 - 24) + 22;

				if (note[i]->x >= X0 && note[i]->x < X0 + 4 + 3)

				{

					note[i]->x = X0 + 4;

				}

				if (note[i]->x >= X0 + 4 + 3 && note[i]->x < X0 + 10 + 3)

				{

					note[i]->x = X0 + 10;

				}

				if (note[i]->x >= X0 + 10 + 3 && note[i]->x < X0 + 16 + 3)

				{

					note[i]->x = X0 + 16;

				}

				if (note[i]->x >= X0 + 16 + 3 && note[i]->x < X0 + 22 + 3)

				{

					note[i]->x = X0 + 22;

				}

				if (note[i]->x >= X0 + 22 + 3 && note[i]->x < X0 + 28 + 3)

				{

					note[i]->x = X0 + 28;

				}

				if (note[i]->x >= X0 + 28 + 3)

				{

					note[i]->x = X0 + 34;

				}

				note[i]->y = Y0;

				break;

			}

		}

		deltaTime = 0.0f;

	}



	for (int i = 0; i < NoteCount; i++)

	{

		if (note[i]->act == true)

		{

			note[i]->y++;

			//SetCursorPosition(note[i]->x, note[i]->y);
			//
			//printf("%s", note[i]->shape);
			WriteBuffer(note[i]->x, note[i]->y, note[i]->shape, 흰색);



			if (note[i]->y > 51)

			{
				combo = 0;
				life--;
				rank = "Bad..";
				note[i]->act = false;

			}

		}



	}
	//SetCursorPosition(26, 53);
	//printf("%s", rank);
	WriteBuffer(26, 53,rank, 흰색);
	
	/////////////////////////////////////////////////////1

	//SetCursorPosition(40, 53);
	//printf("%d Combos!", combo); 수정필요
	_itoa_s(combo, sNum, 10);
	WriteBuffer(40, 53, sNum, 흰색);
	WriteBuffer(40+strlen(sNum), 53, " Combos!", 흰색);
	//SetCursorPosition(80, 5);
	//printf("%d points", point);
	_itoa_s(point, sNum, 10);
	WriteBuffer(60, 5, sNum, 흰색);
	WriteBuffer(60 + strlen(sNum), 5, " Points!", 흰색);
	//SetCursorPosition(80, 40);
	//printf("Life : ");
	WriteBuffer(60, 40,"Life : ", 흰색);
	for (int i = 0; i < life; i++)
	{
		//printf("■");
		WriteBuffer(70+i, 40, "O", 흰색);
	}
	
	/////////////////////////////////////////////////////2

	if (maxCombo < combo)
	{
		maxCombo = combo;
	}
}

void ExitInit()
{
	
}

void ExitProgress()
{
	if (GetAsyncKeyState(VK_RETURN)& 0x0001)
	{
		state = MENU;
	}
}

/////////////////////////////////////////////////////1

void ExitRender()
{
	//printf("최고 콤보 : %d Combos\n\n", maxCombo);
	//printf("점수 : %d Points\n\n", point);
	WriteBuffer(0, 0, "최고 콤보 : ", 흰색);
	_itoa_s(maxCombo, sNum, 10);
	WriteBuffer(12,0, sNum, 흰색);
	WriteBuffer(12 + strlen(sNum),0, " Combos", 흰색);
	WriteBuffer(0, 3, "점수 : ", 흰색);
	_itoa_s(point, sNum, 10);
	WriteBuffer(7,3, sNum, 흰색);
	WriteBuffer(7+strlen(sNum), 3, " Points", 흰색);
	WriteBuffer(0, 6, "<Enter> 를 누를 시 메뉴화면으로 돌아갑니다..", 흰색);
}

/////////////////////////////////////////////////////2

void SetCursorHandle()



{



	HANDLE HCursor = GetStdHandle(STD_OUTPUT_HANDLE);



	CONSOLE_CURSOR_INFO info;



	info.dwSize = 100;



	info.bVisible = FALSE;



	SetConsoleCursorInfo(HCursor, &info);



}







void SetCursorPosition(int _x, int _y)



{



	COORD pos;



	pos.X = _x;



	pos.Y = _y;







	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);



}







void SetTextColor(int _index)



{



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _index);



}

void InitDoubleBuffer()
{
	COORD size = { BufferWidth,BufferHeight }; //버퍼의 크기 관련 구조체 
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect; // 창 크기 관련 구조체(콘솔창의 크기)

					 //창 크기 설정 (1을 빼는 이유는, 그림 그렸을 때 잘리는 것 방지)
	rect.Left = 0;
	rect.Right = BufferWidth - 1;
	rect.Top = 0;
	rect.Bottom = BufferHeight - 1;

	//1번 버퍼 생성
	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size); //버퍼 크기 세팅(여기선 위에 정의한대로 (80,40) )
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect); //창 크기 세팅 (역시나 (80-1 , 40-1) )

												   //2번 버퍼 생성
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size); //버퍼 크기 세팅(여기선 위에 정의한대로 (80,40) )
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect); //창 크기 세팅 (역시나 (80-1 , 40-1) )

												   //커서 깜빡거림 지우는 함수, 대신함
	cci.dwSize = 1;
	cci.bVisible = false;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}
void WriteBuffer(int x, int y, const char*shape, int color)
{
	DWORD dw;
	COORD pos = { x,y }; //좌표 설정
	SetConsoleCursorPosition(hBuffer[screenIndex], pos); // 좌표 이동 함수 대신함
	SetConsoleTextAttribute(hBuffer[screenIndex], color); // 색깔 바꾸는 함수 대신함
	WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL); // 버퍼에 사용하게 될 것
}
void FlipBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]); // 현재 활동중인 버퍼 선택
	screenIndex = !screenIndex; // 다음 버퍼로 바꿔줌
}
void ClearBuffer()
{
	COORD coord = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, coord, &dw);
}
void DestroyBuffer()
{
	CloseHandle(hBuffer[0]); // 1번 버퍼 해제
	CloseHandle(hBuffer[1]); // 2번 버퍼 해제
}