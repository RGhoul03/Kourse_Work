#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

struct student {
	string Name;
	string SurName;
	string MiddleName;

};

struct StudyPlace {
	string Institute;
	string Group;
};

class Date {
private:
	unsigned short day, month, year;
public:

	Date() {
		day = 0; month = 0; year = 0;
	}

	Date(unsigned short d, unsigned short m, unsigned short y) {
		setDate(d, m, y);
	}

	void setDate(unsigned short d, unsigned short m, unsigned short y) {
		if (chekDate(d, m, y)) {
			this->day = d;
			this->month = m;
			this->year = y;
		}
	}

	// Геттер
	//MyDate getDate() {
	//	MyDate MD;
	//	MD.day = day; MD.month = month; MD.year = year;
	//	return MD;
	//}
	// Проверка даты 
	bool chekDate(unsigned short d, unsigned short m, unsigned short y) {
		if (m > 0 && m < 13) {
			unsigned short maxDay;
			switch (m) {
			case 2: maxDay = (y % 4 == 0) ? 29 : 28; break;// високосный год
			case 1: case 3: case 5: case 7:case 8: case 10: case 12: maxDay = 31; break;
			default: maxDay = 30; break;
			}
			if (d > 0 && d <= maxDay) {
				day = d; month = m; year = y;
				return true;
			}
			else {
				cout << "\nДата не корректна. Исправьте день, он не должен быть больше 31. Введенный номер дня: " << d << endl;
				return false;
			}
		}
		cout << "\nДата не корректна. Исправьте номер месяца, номер месяца не должен быть больше 12. Введенный номер месяца: " << m << endl;
		return false;
	}
	// Редактирование даты
	void addDay(unsigned short delta) {
		if (chekDate(day + delta, month, year)) {
			this->day = day;
			this->month = month;
			this->year = year;
			cout << endl << "Новая дата: ";
			printDate();
			//cout << "\n Новая дата: " << day + delta << "." << month << "." << year << endl;
		}
	}

	void printDate() {
		if (day > 9) {
			cout << day;
		}
		else {
			cout << "0" << day;
		}
		cout << ".";
		if (month > 9) {
			cout << month;
		}
		else {
			cout << "0" << month;
		}
		cout << ".";
		cout << year;
	}
};

class Student {
private:
	student studentInfo;
	Date Birthday;
	string uniqueID;
	Date EntranceYear;
	StudyPlace study_place;
	bool sex;
public:
	Student() {
		studentInfo.SurName = "Иванов"; studentInfo.Name = "Иван"; studentInfo.MiddleName = "Иванович";
		sex = true;
		Birthday.setDate(1,1,2000);
		uniqueID = "00А0000";

	}
};

void addStudent() {
	cout << "--- Добавление данных о студенте ---" << endl;

}

void MainMenu() {
	while (true) {
		cout << "======== ГЛАВНОЕ МЕНЮ ========" << endl;
		cout << "--- Введите номер действия ---" << endl;
		cout << "1 - Добавить данные о студенте" << endl;
		cout << "2 - Показать данные о студенте" << endl;
		cout << "3 - Изменить данные о студенте" << endl;
		cout << "4 - Удалить данные о студенте" << endl;
		cout << "5 - Выйти из программы" << endl << endl;

		bool Return = true;
		while (Return == true) {
			unsigned short int option;
			cout << "Введите номер выбранного действия: "; cin >> option;

			switch (option)
			{
			case 1:
				addStudent();
				Return = false;
				break;
			case 2:
				cout << "Функция отображения данных о студенте в разработке. Приносим свои извинения" << endl;
				Return = false;
				break;
			case 3:
				cout << "Функция изменения данных о студенте в разработке. Приносим свои извинения" << endl;
				Return = false;
				break;
			case 4:
				cout << "Функция удаления данных о студенте в разработке. Приносим свои извинения" << endl;
				Return = false;
				break;
			case 5:
				cout << "До свидания!" << endl;
				exit(0);
			default:
				cout << "Действие не определено. Повторите выбор действия." << endl;
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MainMenu();
}