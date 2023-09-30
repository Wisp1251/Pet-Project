#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

//global var
int wight = 5, height = 5;
int bomb = 3;
int user_x, user_y;
int choose = 1;
int **pole = NULL;
int** user_pole = NULL;
int count;
unsigned char symbol_flag = 63;
unsigned char symbol_activ_pole = 186;
unsigned char symbol_bomb = 42;
bool game;
bool open = false;
bool menu = true;
bool work = true;



//prototype function
void Place_Bomb(int bomb);
void Game_Over();
void Game_Win();
void Open(int x, int y);
void Draw();
//

void Hello() {
	while(1){
		system("cls");


		std::cout << "  ___  ____            _____                                   " << std::endl;
		std::cout << "  |  \\/  (_)          /  ___|                                  " << std::endl;
		std::cout << "  | .  . |_ _ __   ___\\ `--.__      _____  ___ _ __   ___ _ __ " << std::endl;
		std::cout << "  | |\\/| | | '_ \\ / _ \\`--. \\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__|" << std::endl;
		std::cout << "  | |  | | | | | |  __/\\__/ /\\ V  V /  __/  __/ |_) |  __/ |   " << std::endl;
		std::cout << "  \\_|  |_/_|_| |_|\\___\\____/  \\_/\\_/ \\___|\\___| .__/ \\___|_|   " << std::endl;
		std::cout << "                                              | |              " << std::endl;
		std::cout << "                                              |_|              " << std::endl;
		std::cout << "          Please press SPACEBAR to continue..." << std::endl;
		
	if (_kbhit())if (_getch() == 32)break;
	Sleep(200);
	}

}

void Setup() {
	srand(time(NULL));
	user_x = 1; user_y = 1;

	pole = new int* [height];
	for (int i = 0; i < height; i++)pole[i] = new int[wight];
	for (int i = 0; i < height; i++)for (int y = 0; y < wight; y++)pole[i][y] = 0;

	user_pole = new int* [height];
	for (int i = 0; i < height; i++)user_pole[i] = new int[wight];
	for (int i = 0; i < height; i++)for (int y = 0; y < wight; y++)user_pole[i][y] = 10;

	
	Place_Bomb(bomb);
	

	//////Logic bomb
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < wight; j++) {
			if (pole[i][j] == 9) {

				if (i - 1 >= 0 && j - 1 >= 0 && pole[i - 1][j - 1] != 9)
					pole[i - 1][j - 1]++;

				if (i - 1 >= 0 && pole[i - 1][j] != 9)
					pole[i - 1][j]++;

				if (i - 1 >= 0 && j + 1 < wight && pole[i - 1][j + 1] != 9)
					pole[i - 1][j + 1]++;

				if (j - 1 >= 0 && pole[i][j - 1] != 9)
					pole[i][j - 1]++;

				if (j + 1 < wight && pole[i][j + 1] != 9)
					pole[i][j + 1]++;

				if (i + 1 < height && j - 1 >= 0 && pole[i + 1][j - 1] != 9)
					pole[i + 1][j - 1]++;

				if (i + 1 < height && pole[i + 1][j] != 9)
					pole[i + 1][j]++;

				if (i + 1 < height && j + 1 < wight && pole[i + 1][j + 1] != 9)
					pole[i + 1][j + 1]++;
			}
		}
	}
	/////////////////////////////
}

//main function
void MeinMenu() {
	menu = true;
	int temp_bomb = 0;
	int choose = 1;
	bool setup;

	while (menu == true) {
		Sleep(200);
		system("cls");
		bool activ_choose = false;
		
		std::cout << "Mein menu" << std::endl<<std::endl;

		if(choose!=1)std::cout << "Start game" << std::endl;
		else std::cout <<symbol_activ_pole<< "Start game" << symbol_activ_pole << std::endl;

		if (choose != 2)std::cout << "Setup" << std::endl;
		else std::cout << symbol_activ_pole << "Setup" << symbol_activ_pole << std::endl;

		if (choose != 3)std::cout << "Exit" << std::endl;
		else std::cout << symbol_activ_pole << "Exit" << symbol_activ_pole << std::endl;

		if (_kbhit()) {
			switch (_getch())
			{
			case 'w':if (choose > 1)choose--; break;
			case 's':if (choose < 3)choose++; break;
			case 32: case 13: activ_choose = true;
			}
		}
		if (activ_choose == true) {
			switch (choose)
			{
			case 1:activ_choose = false; menu = false; game = true; break;//start game
			case 2:
				////Setup
				activ_choose = false;
				setup = true;
				choose = 1;
				while (setup == true) {
					Sleep(200);
					system("cls");
							//Setup menu
					std::cout << "Setup menu" << std::endl << std::endl;

					if (choose != 1)std::cout << "Change field size" << std::endl;
					else std::cout << symbol_activ_pole << "Change field size" << symbol_activ_pole << std::endl;

					if (choose != 2)std::cout << "Change the number of bombs" << std::endl;
					else std::cout << symbol_activ_pole << "Change the number of bombs" << symbol_activ_pole << std::endl;

					if (choose != 3)std::cout << "Exit to main menu" << std::endl;
					else std::cout << symbol_activ_pole << "Exit to main menu" << symbol_activ_pole << std::endl;

					if (_kbhit()) {
						switch (_getch())
						{
						case 'w':if (choose > 1)choose--; break;
						case 's':if (choose < 3)choose++; break;
						case 32: case 13: activ_choose = true; break;
						case 27: setup = false; break;
						}
					}

					if (activ_choose == true) {
						switch (choose)
						{
						case 1:
							system("cls");
							std::cout << "Current settings:" << std::endl;
							std::cout << "wight: " << wight << std::endl;
							std::cout << "height: " << height << std::endl;

							std::cout << std::endl;

							std::cout << "Enter what you wont size" << std::endl;
							std::cout << "wight: "; std::cin >> wight;
							std::cout << "height: "; std::cin >> height;
							activ_choose = false;
							break;

						case 2:
							system("cls");
							std::cout << "Current settings:" << std::endl;
							std::cout << "bomb: " << bomb << std::endl;

							std::cout << std::endl;

							std::cout << "Enter what you wont bobm" << std::endl;
							std::cout << "bomb: "; std::cin >> temp_bomb;
							if (temp_bomb < (wight * height) - 1) {
								bomb = temp_bomb;
								std::cout << std::endl << "Changed: " << bomb << std::endl;
								activ_choose = false;
								Sleep(900);
							}
							else {
								std::cout << "Error: the number of bombs exceeds the size of the field!";
								Sleep(900);
								}
							
							break;


						case 3: setup = false; break;
						}
					}
				}
				//setup
				break;
			case 3:activ_choose = false; menu = false; work = false; break;//exit
			}
			//loading screen
		}
	}
}

void Logic() {

	////logic draw
	if (open == true) {
		
		bool activ_choose = false;

			std::cout << "Choose what you want:"<<std::endl;

			if (choose != 1)std::cout<< "To open" << "\t\t";
			else std::cout << symbol_activ_pole << "To open" << symbol_activ_pole << "\t";

			if (choose != 2)std::cout<< "Put up a flag" << std::endl;
			else std::cout << symbol_activ_pole << "Put up a flag" << symbol_activ_pole << std::endl;


			if (_kbhit()) {
				switch (_getch())
				{
				case 'a':if (choose > 1)choose--; break;
				case 'd':if (choose < 2)choose++; break;
				case 32: case 13: activ_choose = true;
				case 27: open = false;
				}
			}

			if(activ_choose == true){
				switch (choose){
				case 1: user_pole[user_x - 1][user_y - 1] = pole[user_x - 1][user_y - 1]; open = false; break;
				case 2: user_pole[user_x - 1][user_y - 1] = 11; open = false; break;
				}
			}
			
			//Pole open
			if (user_pole[user_x - 1][user_y - 1] == 0) {
				Open(user_x - 1, user_y - 1);
			}
			///////////
			
	}
	//////////////

	////logic game over
	for (int i = 0; i < height; i++)
		for (int j = 0; j < wight; j++) {
			if(user_pole[i][j] == 9)Game_Over();
		}
		
	////

	count = height * wight - bomb;
	////logic game win or over
	for (int i = 0; i < height; i++)
		for (int j = 0; j < wight; j++) {
			if (pole[i][j] != 9) {
				if (user_pole[i][j] < 10)count--; //win
			}
			
		}
	if (count == 0)Game_Win();
	////

	//Play game
	if (game == false) {
		
		do{
			std::cout << std::endl << std::endl << "Enter:\n (1)For return game\t(2)For exit to main menu" << std::endl;
			std::cin >> choose;
			switch (choose) {
			case 1: Setup(); game = true; system("cls"); std::cout << std::endl << "New game" << std::endl; Sleep(700); break;
			case 2: game = false; break;
			default:  std::cout << std::endl << "Error" << std::endl;
				Sleep(500);
				if (game == false)Game_Over();
				else Game_Win();
			}
		} while (choose < 1 || choose > 2);
	}
	//
}

void Input() {

	if (open != true) {
		if (_kbhit()) {
			switch (_getch())
			{
			case 'w':if (user_x - 1 > 0 && user_x - 1 <= height)user_x -= 1; break;
			case 's':if (user_x + 1 > 0 && user_x + 1 <= height)user_x += 1; break;
			case 'a':if (user_y - 1 > 0 && user_y - 1 <= wight)user_y -= 1; break;
			case 'd':if (user_y + 1 > 0 && user_y + 1 <= wight)user_y += 1; break;
			case 13: case 32:open = true; break;
			case 27:
				game = false; break;
			}
		}
	}

}

void Draw() {
	system("cls");
	
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < wight; y++)
			if (x == user_x-1 && y == user_y-1) {
				if (user_pole[x][y] == 10) {
					std::cout << symbol_activ_pole <<"_" << symbol_activ_pole << " ";
				}
				else if (user_pole[x][y] == 11) {
					std::cout << symbol_activ_pole << symbol_flag << symbol_activ_pole << " ";
				}
				else if (user_pole[x][y] == 9) {
					std::cout << symbol_activ_pole << "*" << symbol_activ_pole << " ";
				}
				else std::cout << symbol_activ_pole << user_pole[x][y] << symbol_activ_pole << " ";
			}

			else{
				if (user_pole[x][y] == 10) {
					std::cout << "|_| ";
				}
				else if (user_pole[x][y] == 11) {
					std::cout << "|" << symbol_flag << "| ";
				}
				else if (user_pole[x][y] == 9) {
					std::cout << "|" << "*" << "| ";
				}
				else std::cout << "|" << user_pole[x][y] << "| ";
				
			}
		std::cout << std::endl;
	}
}
///

void Open(int x, int y) {
	if (pole[x][y] == 0) {

		user_pole[x][y] = 0;

		if (x - 1 >= 0 && pole[x - 1][y] == 0 && user_pole[x - 1][y] == 10)
			Open(x - 1,y);

		if (y - 1 >= 0 && pole[x][y - 1] == 0 && user_pole[x][y - 1] == 10)
			Open(x,y - 1);

		if (y + 1 < wight && pole[x][y + 1] == 0 && user_pole[x][y + 1] == 10)
			Open(x,y + 1);

		if (x + 1 < height && pole[x + 1][y] == 0 && user_pole[x + 1][y] == 10)
			Open(x + 1,y);
	}
}

void Place_Bomb(int bomb) {
	while (bomb > 0) {
		int x = rand() % height;
		int y = rand() % wight;
		if (pole[x][y] != 9) {
			pole[x][y] = 9;
			bomb--;
		}
	}
}

void Game_Over(){
	game = false;
	system("cls");

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < wight; y++) {
			if (pole[x][y] == 9) {
				std::cout << "|" << symbol_bomb << "| ";
			}
			else {
				std::cout << "|_| ";
			}
		}
		std::cout << std::endl;
	}
	//Boom!;
	std::cout<<std::endl << "Game Over" << std::endl;
}

void Game_Win() {
	game = false;
	system("cls");

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < wight; y++)
		{
			if (user_pole[x][y] == 9) {
			std::cout << "|" << "*" << "| ";
				}
			else std::cout << "|"<< pole[x][y] <<"| ";
		}
				
		std::cout << std::endl;
	}
	std::cout << std::endl << "Game WIN" << std::endl;
}

void Exit() {
	for (int i = 0; i < height; i++)delete[] pole[i];
	delete[] pole;
}

int main() {
	Hello();
	while (work == true) {
		MeinMenu();
		Setup();
		while (game == true) {
			Sleep(100);
			Draw();
			Input();
			Logic();
		}
	}
	Exit();
	return 0;
}