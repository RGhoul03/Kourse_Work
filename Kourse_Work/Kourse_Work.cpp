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
public:
	unsigned short day, month, year;

	Date() {
		day = 0; month = 0; year = 0;
	}

	Date(unsigned short d, unsigned short m, unsigned short y) {
		setDate(d, m, y);
	}

	int GetDate() {
		return day, month, year;
	}

	void setDate(unsigned short d, unsigned short m, unsigned short y) {
		if (chekDate(d, m, y)) {
			this->day = d;
			this->month = m;
			this->year = y;
		}
	}

	bool chekDate(unsigned short d, unsigned short m, unsigned short y) {
		if (m > 0 && m < 13) {
			unsigned short maxDay;
			switch (m) {
			case 2: maxDay = (y % 4 == 0) ? 29 : 28; break;
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
		cout << year << endl;
	}
};

class Student {
public:
	student studentInfo;
	Date Birthday;
	string uniqueID;
	Date EntranceYear;
	StudyPlace study_place;
	bool Gender;

	Student() {
		studentInfo.SurName = "Иванов"; studentInfo.Name = "Иван"; studentInfo.MiddleName = "Иванович";
		Gender = true;
		Birthday.setDate(1,1,2000);
		uniqueID = "00А0000";
		EntranceYear.setDate(1,1,2017);
		study_place.Group = "AAAA-00-00";
		study_place.Institute = "ИКБ";
	}
	bool check(string& line)
	{
		const string NUMBERS = "0123456789";

		for (int x = 0; x < (int)(line.size()); x++)
		{
			for (int y = 0; y < (int)(NUMBERS.size()); y++)
			{
				if (NUMBERS[y] == line[x])
					return true;
			}
		}

		return false;
	}

	void StudentSet() {
		while (true){
			cout << "Ввод фамилии: "; cin >> studentInfo.SurName;
			if (!check(studentInfo.SurName)) { cout << "good" << endl; break; }
			cout << "bad" << endl;
			Clear();
		}
		while (true) {
			cout << "Ввод имени: "; cin >> studentInfo.Name;
			if (!check(studentInfo.Name)) { cout << "good" << endl; break; }
			cout << "bad" << endl;
			Clear();
		}
		while (true) {
			cout << "Ввод отчества: "; cin >> studentInfo.MiddleName;
			if (!check(studentInfo.MiddleName)) { cout << "good" << endl; break; }
			cout << "bad" << endl;
			Clear();
		}
		int Day, Month, Year;
		cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
		Birthday.setDate(Day, Month, Year);

		while (true) {
			string gender;
			cout << "Пол: "; cin >> gender;
			if (!check(gender)) { 
				if (gender == "м") { Gender = true; break; }
				else if (gender == "ж") { Gender = false; break; }
				else { cout << "gender bad" << endl; }
			}
			else { cout << "bad" << endl; }
			Clear();
		}

		cout << "студак: "; cin >> uniqueID;

		cout << "Год поступления" << endl;
		cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
		EntranceYear.setDate(Day, Month, Year);

		cout << "Ввод группы: "; cin >> study_place.Group;

		while (true) {
			cout << "Ввод института: "; cin >> study_place.Institute;
			if (!check(study_place.Institute)) { cout << "good" << endl; break; }
			cout << "bad" << endl;
			Clear();
		}
	}

	void printStudent() {
		cout << studentInfo.SurName << " " << studentInfo.Name << " " << studentInfo.MiddleName << endl;
		Birthday.printDate(); 
		if (Gender = true) { cout << "man" << endl; }
		else { cout << "woman" << endl; }

	}

	void Clear() {
		cin.clear(); cin.ignore(INT_MAX, '\n');
	}
};

void addStudent() {
	cout << "--- Добавление данных о студенте ---" << endl;
	
	Student student;
	student.StudentSet();
	student.printStudent();

	ofstream fout;
	fout.open("DB_Students.txt", ofstream::app);

	fout << student.uniqueID << " " << student.studentInfo.SurName << " " <<
		student.studentInfo.Name << " " << student.studentInfo.MiddleName << " " <<
		student.Birthday.day << " " << student.Birthday.month << " " << student.Birthday.year << " " <<
		student.Gender << " " << student.EntranceYear.day << " " << student.EntranceYear.month << " " << student.EntranceYear.year << " " <<
		student.study_place.Group << " " << student.study_place.Institute << endl;

	fout.close();
}

void Clear() {
	cin.clear(); cin.ignore(INT_MAX, '\n');
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
				Clear();
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	MainMenu();
}