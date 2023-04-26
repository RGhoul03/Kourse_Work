﻿#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Session_Class.h"

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
	unsigned short int Gender;
	Session* term;

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
			if (!check(studentInfo.SurName)) { break; }
			cout << "Вы ввели что-то не так." << endl;
			Clear();
		}
		while (true) {
			cout << "Ввод имени: "; cin >> studentInfo.Name;
			if (!check(studentInfo.Name)) { break; }
			cout << "Вы ввели что-то не так." << endl;
			Clear();
		}
		while (true) {
			cout << "Ввод отчества: "; cin >> studentInfo.MiddleName;
			if (!check(studentInfo.MiddleName)) { break; }
			cout << "Вы ввели что-то не так." << endl;
			Clear();
		}
		int Day, Month, Year;
		cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
		Birthday.setDate(Day, Month, Year);

		while (true) {
			string gender;
			cout << "Пол: "; cin >> gender;
			if (!check(gender)) {
				if (gender == "м") { Gender = 1; break; }
				else if (gender == "ж") { Gender = 0; break; }
				else { cout << "Такого пола не существует. Поменяй." << endl; }
			}
			Clear();
		}

		cout << "студак: "; cin >> uniqueID;

		cout << "Год поступления" << endl;
		cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
		EntranceYear.setDate(Day, Month, Year);

		cout << "Ввод группы: "; cin >> study_place.Group;

		while (true) {
			cout << "Ввод института: "; cin >> study_place.Institute;
			if (!check(study_place.Institute)) { break; }
			cout << "Вы ввели что-то не так." << endl;
			Clear();
		}

		int count_sessions;
		cout << "Введите кол-во сессий: "; cin >> count_sessions;
		if (count_sessions > 0 && count_sessions < 11) {
			term = new Session[count_sessions];
			for (int i = 0; i < count_sessions; i++) {
				term[i];
			}
			//delete[] term;
		}
		else { cout << "Слишком много сессий" << endl; }

	}

	void printStudent() {
			cout << studentInfo.SurName << " " << studentInfo.Name << " " << studentInfo.MiddleName << endl;
			Birthday.printDate();
			if (Gender == 0) { cout << "Женщина" << endl; }
			else { cout << "Мужчина" << endl; }
			cout << uniqueID << endl;
			EntranceYear.printDate();
			cout << study_place.Group << endl;
			cout << study_place.Institute << endl;
			term->print_session();
		}

	void printShortInfo() {
			cout << uniqueID << " " << studentInfo.SurName << " " << studentInfo.Name << " " << studentInfo.MiddleName << endl;;
		}

	void Clear() {
			cin.clear(); cin.ignore(INT_MAX, '\n');
		}
};

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

void Clear() {
	cin.clear(); cin.ignore(INT_MAX, '\n');
}

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

		fout.open("DB_Sessions.txt", ofstream::app);
		fout << student_add.uniqueID << " " << student_add.term->session->subject << " " << student_add.term->session->mark << endl;

		fout.close();

		unsigned short int option;
		cout << "Добавить еще одного студента? (1 - да, 2 - нет): "; cin >> option;
		switch (option) {
		case 1: Clear(); break;
		case 2: chek = false; Clear(); break;
		}
	}
}

bool FileIsExist(std::string filePath) {
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}

int line_count() {
	if (FileIsExist("DB_Students.txt")) {
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
	else { return 0; }
}

void delLogic(bool flag, string UID) {
	int LineCount = line_count();

	if (flag) {
		ifstream in("DB_Students.txt");
		for (int i = 0; i < LineCount; i++) {
			Student student_see;
			in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
				student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
				student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
				student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
				student_see.study_place.Group >> student_see.study_place.Institute;

			ofstream fout;
			fout.open("DB_Students_temp.txt", ofstream::app);

			if (student_see.uniqueID != UID) {
				fout << student_see.uniqueID << " " << student_see.studentInfo.SurName << " " <<
					student_see.studentInfo.Name << " " << student_see.studentInfo.MiddleName << " " <<
					student_see.Birthday.day << " " << student_see.Birthday.month << " " << student_see.Birthday.year << " " <<
					student_see.Gender << " " << student_see.EntranceYear.day << " " << student_see.EntranceYear.month << " " << student_see.EntranceYear.year << " " <<
					student_see.study_place.Group << " " << student_see.study_place.Institute << endl;
			}
			fout.close();

		}
		in.close();
		string file_name = "DB_Students.txt";
		std::remove(file_name.c_str());

		char oldfilename[] = "DB_Students_temp.txt";
		char newfilename[] = "DB_Students.txt";
		std::rename(oldfilename, newfilename);
	}

}

void deleteStudent() {
	int LineCount = line_count();

	bool chek = true;
	while (chek == true) {
		string unique_id;
		cout << "Введите номер студенческого билета: "; cin >> unique_id;

		ifstream in("DB_Students.txt");
		bool flag = false;
		for (int i = 0; i < LineCount; i++) {
			Student student_see;
			in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
				student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
				student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
				student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
				student_see.study_place.Group >> student_see.study_place.Institute;
			if (student_see.uniqueID == unique_id) {
				flag = true; cout << "Этот студент будет удален из базы: "; student_see.printShortInfo(); break;
			}
		}
		if (flag == false) { cout << "Студента с таким номером студенческого билета нет." << endl; }

		in.close();

		delLogic(flag, unique_id);
		
		bool Return = true;
		while (Return == true) {
			unsigned short int option;
			cout << "Удалить кого-то еще? (1 - да, 2 - нет): "; cin >> option;
			switch (option) {
			case 1: break;
			case 2: chek = false; break;
			default: cout << "Действие не определено. Повторите выбор действия." << endl; Clear();
			}
		}
	}
}

void editLogic(bool flag, Student& editStud) {
	while (true) {
		cout << "Какие данные вы хотите изменить?" << endl;
		cout << "1 - Имя" << endl;
		cout << "2 - Фамилию" << endl;
		cout << "3 - Отчество" << endl;
		cout << "4 - Дату рождения" << endl;
		cout << "5 - Номер студенческого билета" << endl;
		cout << "6 - Год поступления" << endl;
		cout << "7 - Группу" << endl;
		cout << "8 - Институт" << endl;
		cout << "9 - Вернуться назад" << endl << endl;

		bool Return = true;
		while (Return == true) {
			unsigned short int option; int Day, Month, Year;
			cout << "Введите номер выбранного действия: "; cin >> option;

			switch (option)
			{
			case 1:
				while (true) {
					cout << "Введите новое имя: "; cin >> editStud.studentInfo.Name;
					if (!check(editStud.studentInfo.Name)) { Return = false; break; }
					cout << "bad" << endl;
					Clear();
				}
				break;
			case 2:
				while (true) {
					cout << "Введите новую фамилию: "; cin >> editStud.studentInfo.SurName;
					if (!check(editStud.studentInfo.SurName)) { Return = false; break; }
					cout << "bad" << endl;
					Clear();
				}
				break;
			case 3:
				while (true) {
					cout << "Введите новое отчество: "; cin >> editStud.studentInfo.MiddleName;
					if (!check(editStud.studentInfo.MiddleName)) { Return = false; break; }
					cout << "bad" << endl;
					Clear();
				}
				break;
			case 4:
				cout << "Введите новую дату дня рождения:" << endl;
				cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
				editStud.Birthday.setDate(Day, Month, Year);
				Return = false;
				break;
			case 5:
				cout << "Введите новый номер студенческого билета: " << endl; cin >> editStud.uniqueID;
				Return = false;
				break;
			case 6:
				cout << "Введите новую дату поступления:" << endl;
				cout << "день"; cin >> Day; cout << endl << "месяц"; cin >> Month; cout << endl << "год"; cin >> Year;
				editStud.EntranceYear.setDate(Day, Month, Year);
				Return = false;
				break;
			case 7:
				cout << "Введите новый номер группы: " << endl; cin >> editStud.study_place.Group;
				Return = false;
				break;
			case 8:
				while (true) {
					cout << "Введите название института: "; cin >> editStud.study_place.Institute;
					if (!check(editStud.study_place.Institute)) { Return = false; break; }
					cout << "bad" << endl;
					Clear();
				}
				break;
			case 9:
				return;
			default:
				cout << "Действие не определено. Повторите выбор действия." << endl;
				Clear();
			}
		}
	}
}

void editStudent() {
	int LineCount = line_count();

	bool chek = true;
	while (chek == true) {
		string unique_id;
		cout << "Введите номер студенческого билета: "; cin >> unique_id;
		Student student_see;

		ifstream in("DB_Students.txt");
		bool flag = false;
		for (int i = 0; i < LineCount; i++) {
			in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
				student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
				student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
				student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
				student_see.study_place.Group >> student_see.study_place.Institute;
			if (student_see.uniqueID == unique_id) {
				flag = true; cout << "Данные этого студента вы хотите изменить: "; student_see.printShortInfo(); break;
			}
		}
		if (flag == false) { cout << "Студента с таким номером студенческого билета нет." << endl; }

		in.close();

		delLogic(flag, unique_id);

		Student* ed_stud = new Student(student_see);
		editLogic(flag, *ed_stud);

		cout << "Измененные данные:" << endl;
		ed_stud->printStudent();

		ofstream fout;
		fout.open("DB_Students.txt", ofstream::app);

		fout << ed_stud->uniqueID << " " << ed_stud->studentInfo.SurName << " " <<
			ed_stud->studentInfo.Name << " " << ed_stud->studentInfo.MiddleName << " " <<
			ed_stud->Birthday.day << " " << ed_stud->Birthday.month << " " << ed_stud->Birthday.year << " " <<
			ed_stud->Gender << " " << ed_stud->EntranceYear.day << " " << ed_stud->EntranceYear.month << " " << ed_stud->EntranceYear.year << " " <<
			ed_stud->study_place.Group << " " << ed_stud->study_place.Institute << endl;

		fout.close();

		bool Return = true;
		while (Return == true) {
			unsigned short int option;
			cout << "Изменить чьи-то еще данные? (1 - да, 2 - нет): "; cin >> option;
			switch (option) {
			case 1: Return = false; break;
			case 2: chek = false; Return = false; break;
			default: cout << "Действие не определено. Повторите выбор действия." << endl; Clear();
			}
		}
	}
}

void getStudent() {
	int LineCount = line_count();

	bool chek = true;
	while (chek == true) {
		ifstream in("DB_Students.txt");
		string unique_id; bool flag = false;
		cout << "Введите номер студенческого билета: "; cin >> unique_id;
		for (int i = 0; i < LineCount; i++) {
			Student student_see;
			in >> student_see.uniqueID >> student_see.studentInfo.SurName >>
				student_see.studentInfo.Name >> student_see.studentInfo.MiddleName >>
				student_see.Birthday.day >> student_see.Birthday.month >> student_see.Birthday.year >>
				student_see.Gender >> student_see.EntranceYear.day >> student_see.EntranceYear.month >> student_see.EntranceYear.year >>
				student_see.study_place.Group >> student_see.study_place.Institute;

			if (student_see.uniqueID == unique_id) {
				student_see.printStudent(); flag = true; break;
			}

		}
		if (flag == false) { cout << "Студента с таким номером студенческого билета нет." << endl; }

		bool Return = true;
		while (Return == true) {
			unsigned short int option;
			cout << "Совершить поиск еще раз? (1 - да, 2 - нет): "; cin >> option;
			in.close();
			switch (option) {
			case 1: flag = true; Return = false; break;
			case 2: chek = false; Return = false; break;
			default: cout << "Действие не определено. Повторите выбор действия." << endl; Clear();
			}
		}
	}
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

	bool Return = true;
	while (Return == true) {
		int option;
		cout << "Вывести подробные данные о конкретном студенте? (1 - да, 2 - нет): "; cin >> option;
		switch (option) {
		case 1: getStudent(); Return = false; break;
		case 2: Return = false; break;
		default: cout << "Действие не определено. Повторите выбор действия." << endl; Clear();
		}
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

		if (line_count() == 0) {
			cout << "База данных пуста! Вывод, изменение и удаление данных не доступны!" << endl;
			cout << "Вы можете добавить новые данные." << endl;
		}

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
				editStudent();
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