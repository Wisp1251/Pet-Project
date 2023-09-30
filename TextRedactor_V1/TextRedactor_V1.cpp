#include <iostream>
#include <windows.h>

void f_create();
void checking(int &Var, int min, int max);

int choose;
bool check;
bool exit_prog;
enum class Function {Start = -1, Exit, Create, Open };
Function function_prog;

void setup() {
	exit_prog = false;
	check = false;
	function_prog = Function::Start;
	choose = 0;
	std::cin.clear();
}

void start() {
	std::cout << "Hello user please choose your function:\n(0)\"Exit\"	(1)\"Create\"	(2)\"Open\"\n";
}

void input() {
	while (check == false)
	{
		system("cls");
		start();

	//checking(choose, 0, 2);
	
		std::cin >> choose;
		switch (choose) {
		case 0:
			function_prog = Function::Exit;
			check = true;
			break;
		case 1:
			function_prog = Function::Create;
			check = true;
			break;
		case 2:
			function_prog = Function::Open;
			check = false;
			break;
		default:
			std::cout << "Error plese enter 0 or 2 number!\n";
			check = false;
		}
		system("pause");
	}
}

void logic() {
	switch(function_prog){

	case Function::Exit:
		std::cout << "Have a good day\n";
		exit_prog = true;
		break;

	case Function::Create:
		f_create();
	}
}



int main() {

	setup();
	while (exit_prog == false) {
		system("cls");
		input();
		logic();
	}
	
system("pause");
		 system("cls");
	return 0;
}

void checking(int &Var, int min, int max) {
	bool check = false;
	while (check == false) {
		
		std::cin >> Var;
		if (Var >= min && Var <= max) {
			check = true;
		}
		else {
			std::cout << "Error plese enter " << min << " or " << max << " number!\n";
		}
	}
}

void f_create() {
//File name
	char* Name = new char[10];
	
	std::cout << "Please enter file name: ";
	std::cin >> Name;
//

//File path
	char* Path = new char[20];

	std::cout << "Please enter file path: ";
	std::cin >> Path;

	system("dir");
	
	}