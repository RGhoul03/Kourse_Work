#include <string>
#include <iostream>

using namespace std;

struct Exam {
	string subject = "#";
	int count_exams = 0;
	int mark = 0;
};

class Session {
public:
	Exam* session;
	void SessionSet() {
		int count_exam;
		cout << "������� ���-�� ���������: "; cin >> count_exam;
		if (count_exam > 0 && count_exam < 11) {
			session = new Exam[count_exam+1];
			for (int i = 0; i < count_exam; i++) {
				session[i].count_exams = count_exam + 1;
				cout << "������� �������� ��������: "; cin >> session[i].subject;
				cout << "������� ������ �� �������: "; cin >> session[i].mark;
			}
			session[count_exam].subject = 'e';
			session[count_exam].mark = 0;
		}
		else { cout << "������� ����� ���������" << endl; }
	}

	void print_session(int max_ex) {
		for (int i = 0; i < max_ex; i++) {
			if (session[i].subject != "#" and session[i].mark != 0) {
				cout << "�������: " << session[i].subject << "\n";
				cout << "������: " << session[i].mark << endl;
			}
		}
	}
};