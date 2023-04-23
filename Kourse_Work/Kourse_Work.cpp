﻿#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>

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
		Birthday.setDate(1, 1, 2000);
		uniqueID = "00А0000";
		EntranceYear.setDate(1, 1, 2017);
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
		while (true) {
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
		cout << uniqueID << endl;
		EntranceYear.printDate();
		cout << study_place.Group << endl;
		cout << study_place.Institute << endl;
	}

	void printShortInfo() {
		cout << uniqueID << " " << studentInfo.SurName << " " << studentInfo.Name << " " << studentInfo.MiddleName << endl;;
	}

	void Clear() {
		cin.clear(); cin.ignore(INT_MAX, '\n');
	}
};

void addStudent() {
	cout << "--- Добавление данных о студенте ---" << endl;

	bool chek = true;
	while (chek == true) {
		Student student_add;
		student_add.StudentSet();

		ofstream fout;
		fout.open("DB_Students.txt", ofstream::app);

		fout << student_add.uniqueID << " " << student_add.studentInfo.SurName << " " <<
			student_add.studentInfo.Name << " " << student_add.studentInfo.MiddleName << " " <<
			student_add.Birthday.day << " " << student_add.Birthday.month << " " << student_add.Birthday.year << " " <<
			student_add.Gender << " " << student_add.EntranceYear.day << " " << student_add.EntranceYear.month << " " << student_add.EntranceYear.year << " " <<
			student_add.study_place.Group << " " << student_add.study_place.Institute << endl;

		fout.close();
		unsigned short int option;
		cout << "Добавить еще одного студента? (1 - да, 2 - нет): "; cin >> option;
		switch (option) {
		case 1: break;
		case 2: chek = false; break;
		}
	}
}

void Clear() {
	cin.clear(); cin.ignore(INT_MAX, '\n');
}

int line_count() {
	int x = 0;
	ifstream f("DB_Students.txt");
	while (true)
	{
		string v;
		getline(f, v);
		if (!f.eof())
			x++;
		else
			break;
	}
	return x;
}

void deleteStudent() {
	int LineCount = line_count();
	Student student_see;
	Student* arr = new Student[LineCount];
	ifstream in("DB_Students.txt");

	for (int i = 0; i < LineCount; i++) {
		in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
			student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
			student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
			student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
			student_see.study_place.Group >> student_see.study_place.Institute;

		arr[i] = student_see;
	}
	in.close();

	int x;
	string unique_id; bool flag = false;
	cout << "Введите номер студенческого билета: "; cin >> unique_id;
	for (int i = 0; i < LineCount; i++) {
		if (arr[i].uniqueID == unique_id) { cout << "Этот студент будет удален:" << endl; arr[i].printStudent(); x = i; flag = true; break; }
	}
	if (flag == false) { cout << "Студента с таким номером студенческого билета нет." << endl; }

	ofstream ofs;
	ofs.open("DB_Students.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	ofstream fout;
	fout.open("DB_Students.txt", ofstream::app);

	for (int i = 0; i < LineCount; i++) {
		if (arr[i].uniqueID != arr[x].uniqueID) {
			fout << arr[i].uniqueID << " " << arr[i].studentInfo.SurName << " " <<
				arr[i].studentInfo.Name << " " << arr[i].studentInfo.MiddleName << " " <<
				arr[i].Birthday.day << " " << arr[i].Birthday.month << " " << arr[i].Birthday.year << " " <<
				arr[i].Gender << " " << arr[i].EntranceYear.day << " " << arr[i].EntranceYear.month << " " << arr[i].EntranceYear.year << " " <<
				arr[i].study_place.Group << " " << arr[i].study_place.Institute << endl;
		}
	}

	fout.close();

	delete[]arr;
}

void getStudent() {
	int LineCount = line_count();
	Student student_see;
	Student* arr = new Student[LineCount];
	ifstream in("DB_Students.txt");

	for (int i = 0; i < LineCount; i++) {
		in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
			student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
			student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
			student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
			student_see.study_place.Group >> student_see.study_place.Institute;

		arr[i] = student_see;
	}
	in.close();

	bool chek = true;
	while (chek == true) {
		string unique_id; bool flag = false;
		cout << "Введите номер студенческого билета: "; cin >> unique_id;
		for (int i = 0; i < LineCount; i++) {
			if (arr[i].uniqueID == unique_id) { arr[i].printStudent(); flag = true; break; }
		}
		if (flag == false) { cout << "Студента с таким номером студенческого билета нет." << endl; }

		unsigned short int option;
		cout << "Совершить поиск еще раз? (1 - да, 2 - нет): "; cin >> option;
		switch (option) {
		case 1: break;
		case 2: chek = false; break;
		}
	}
	delete[]arr;
}

void getAllStudents() {
	cout << "--- Вывод данных о студенте ---" << endl;

	int LineCount = line_count();
	Student student_see;
	ifstream in("DB_Students.txt");

	for (int i = 0; i < LineCount; i++) {
		in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
			student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
			student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
			student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
			student_see.study_place.Group >> student_see.study_place.Institute;

		cout << i + 1 << ". "; student_see.printShortInfo();
	}
	cout << endl;
	in.close();

	int option;
	cout << "more info?: "; cin >> option;
	switch (option) {
	case 1: getStudent(); break;
	case 2: break;
	}
}

void MainMenu() {
	while (true) {
		cout << "========== ГЛАВНОЕ МЕНЮ ==========" << endl;
		cout << "----- Введите номер действия -----" << endl;
		cout << "1 - Добавить    данные    студента" << endl;
		cout << "2 - Показать данные всех студентов" << endl;
		cout << "3 - Показать    данные    студента" << endl;
		cout << "4 - Изменить    данные    студента" << endl;
		cout << "5 - Удалить     данные    студента" << endl;
		cout << "6 - Выйти       из       программы" << endl << endl;

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
				getAllStudents();
				Return = false;
				break;
			case 3:
				getStudent();
				Return = false;
				break;
			case 4:
				cout << "Функция изменения данных о студенте в разработке. Приносим свои извинения" << endl;
				Return = false;
				break;
			case 5:
				deleteStudent();
				Return = false;
				break;
			case 6:
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