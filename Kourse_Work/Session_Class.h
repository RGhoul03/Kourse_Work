#include <string>
#include <iostream>

using namespace std;

struct Exam {
	string subject;
	int count_exams;
	int mark;
};

class Session {
public:
	Exam* session;
	Session() {
		int count_exam;
		cout << "������� ���-�� ���������: "; cin >> count_exam;
		if (count_exam > 0 && count_exam < 11) {
			session = new Exam[count_exam+1];
			for (int i = 0; i < count_exam; i++) {
				session[i].count_exams = count_exam + 1;
				cout << "������� �������� ��������: "; cin >> session[i].subject;
				cout << "������� ������ �� �������: "; cin >> session[i].mark;
			}
			//delete[] session;
			session[count_exam].subject = 'e';
			session[count_exam].mark = 0;
		}
		else { cout << "������� ����� ���������" << endl; }
	}

	void print_session() {
		cout << "�������: " << session->subject << endl;
		cout << "������: " << session->mark << endl;
	}
};