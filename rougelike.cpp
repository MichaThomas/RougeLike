#include <windows.h>
#include <iostream>
using namespace std;

char Map[40][40] = {"####################",
					"#                 ! #",
					"#                   #",
					"#                   #",
					"#          *        #",
					"#######         #####",
					"#         #         #",
					"#         #         #",
					"#         #         #",
					"#         #         #",
					"#################   #",
					"#                   #",
					"#          ##########",
					"#                   #",
					"#             #     #",
					"########      #     #",
					"#             #     #",
					"# .           #     #",
					"####################"};
int gamespeed = 100;
int level =1;
bool stopgame = false;
int hp = 100;
int maxhap = 100;
int maxhp = 100;
int P_posx;
int P_posy;
int posx = 5;
int posy = 4;
char userinput(char);
void drawmap();
void update();
void logic();
char player = '@';
void playermove(int,int);
void drawplayer(int ,int );
void composemap();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);



int main()
{

	while (stopgame == false)
	{	//composemap();
        drawmap();
		update();
		cout <<" ";SetConsoleTextAttribute(h,11);cout<<"HP:"<<hp<< "/"<< maxhp <<endl;

	}
}

void drawmap()
{


	system("CLS");
	for(int y =0; y<22; y++)
	{
		cout << Map[y]<<endl;
		for(int y = 0; y<22; y++)
		{
			//Map[y] = 219;
			for(int x = 0; x<22; x++)
			{
				if(Map[y][x] == '#')
				{
					//SetConsoleTextAttribute(h,11);
					//Map[y][x] = 219;
					//drawplayer(posy,posx);
				}

	   		}
        }
    }
}
void update()
{
if(stopgame == false)
{


	if (GetAsyncKeyState(VK_UP) )
		{
			if(Map[posy-1][posx] != '#')
			{
				posy -= 1;
				Map[posy + 1][posx] = ' ';
			}
			if(Map[posy-1][posx] == '*')
			{
				hp -= 20;
			}
			if(Map[posy-1][posx] == '!')
			{
				 cout<<("you won");
					system("pause");

			}


	    }
	if (GetAsyncKeyState(VK_DOWN) )
		{
			if(Map[posy+1][posx] != '#')
			{
				posy += 1;
				Map[posy - 1][posx] = ' ';
			}
			if(Map[posy+1][posx] == '*')
			{
				hp -= 20;
			}
			if(Map[posy+1][posx] == '!')
			{
				 cout<<("you won");
				system("pause");
			}
	    }
	if (GetAsyncKeyState(VK_LEFT) )
		{
			if(Map[posy][posx-1] != '#')
			{
				posx -= 1;
				Map[posy][posx+1] = ' ';
			}
			if(Map[posy][posx-1] == '*')
			{
				hp -= 20;
			}
			if(Map[posy][posx-1] == '!')
			{
				 cout<<("you won");
				system("pause");
			}

	    }
	if (GetAsyncKeyState(VK_RIGHT) )
		{
			if(Map[posy][posx+1] != '#')
			{
				posx += 1;
			Map[posy][posx-1] = ' ';
			}
			if(Map[posy][posx+1] == '*')
			{
				hp -= 20;
			}
			if(Map[posy][posx+1] == '!')
			{
				 cout<<("you won");
				system("pause");
			}


	    }


	drawplayer(posy,posx);
}
}

void drawplayer(int y,int x)
{
//SetConsoleTextAttribute(h,11);
 Map[y][x] = '@' ;

}
