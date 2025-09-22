//preprocessor
#include <iostream>//c++ standard
#include <conio.h>//c standard

using namespace std;

//정적할당
int World[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

char Player = 'P';
int PlayerX = 1;
int PlayerY = 1;
bool bIsRunning = true;
//사상(Mapping)
char Sprites[10] = { ' ','*', };//그림으로 바꾼다.
int KeyCode;
//scope
//협업
bool Predict(int NewX,int NewY)
{
	if (World[NewY][NewX] == 0)
	{
		return true;
	}

	return false;
}
void Input()
{
	KeyCode = _getch();
}
void Process()
{
	if (KeyCode == 'w')
	{
		if (Predict(PlayerX, PlayerY-1))
		{
			PlayerY--;
		}
	}
	else if (KeyCode == 'a')
	{
		if (Predict(PlayerX-1, PlayerY))
		{
			PlayerX--;
		}
	}
	else if (KeyCode == 's')
	{
		if (Predict(PlayerX, PlayerY+1))
		{
			PlayerY++;
		}
	}
	else if (KeyCode == 'd')
	{
		if (Predict(PlayerX+1, PlayerY))
		{
			PlayerX++;
		}
	}
	else if (KeyCode == 'q')
	{
		bIsRunning = false;
	}
}
void Render()
{
	system("cls");
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << Player;
			}
			else//other
			{
				cout << Sprites[World[Y][X]];
			}
		}
		cout << endl;
	}
}

//cpu
int main()
{

	while (bIsRunning) 
	{
		Input();
		Process();
		Render();
	}

	return 0;
}
