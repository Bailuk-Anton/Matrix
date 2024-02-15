#pragma once
#include "matrix.h"

class Application {
public:

	void UserSpot() {
		Menu();
		while (true) {
			chr = _getch();
			if ((chr == 'w') && (cursorY > 5)) { UpCur(); }
			if ((chr == 's') && (cursorY < 10)) { DownCur(); }
			if ((chr == (char)13) && (cursorY == 5)) { mrtx.SetMatrix(); Menu(); };
			if ((chr == (char)13) && (cursorY == 6)) { mrtx.FindDet(); Menu(); };
			if ((chr == (char)13) && (cursorY == 7)) { mrtx.TransposeMatrix(); Menu();};
			if ((chr == (char)13) && (cursorY == 8)) { mrtx.Rang(); Menu();	};
			if ((chr == (char)13) && (cursorY == 9)) { mrtx.Show(mrtx); Menu();};
			if ((chr == (char)13) && (cursorY == 10))break;
		}
		cout << "\n\n\n";
	};
private:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	void SetCursorPosition(short x, short y) {
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x , y };
		SetConsoleCursorPosition(output, pos);
	}

	void UpCur() {
		SetCursorPosition(cursorX, cursorY);
		cout << " ";
		this->cursorY = cursorY - 1;
		SetCursorPosition(cursorX, cursorY);
		cout << ">";
	}

	void DownCur() {
		SetCursorPosition(cursorX, cursorY);
		cout << " ";
		this->cursorY = cursorY + 1;
		SetCursorPosition(cursorX, cursorY);
		cout << ">";
	}

	void Menu() {
		system("cls");
		SetCursorPosition(40, 0);
		cout << "\'w\' up";
		SetCursorPosition(40, 1);
		cout << "\'s\' down";
		SetCursorPosition(40, 2);
		cout << "\'enter\' for enter";
		SetCursorPosition(5, 5);
		cout << "Enter matrix";
		SetCursorPosition(5, 6);
		cout << "Get Determinant of matrix";
		SetCursorPosition(5, 7);
		cout << "Get Transpose matrix";
		SetCursorPosition(5, 8);
		cout << "Get rang of matrix";
		SetCursorPosition(5, 9);
		cout << "Show matrix";
		SetCursorPosition(5, 10);
		cout << "Exit";

		SetCursorPosition(4, 5);
		cout << ">";
		this->cursorX = 4;
		this->cursorY = 5;
	};

	Matrix mrtx;

	short cursorX, cursorY;

	char chr;
};