#include <string>
#include <iostream>

using namespace std;

struct Exam {
	string subject;
	int mark;
};

class Session {
public:
	Exam* session;
	Session() {
		int count_exams;
		cout << "������� ���-�� ���������: "; cin >> count_exams;
		if (count_exams > 0 && count_exams < 11) {
			session = new Exam[count_exams];
			for (int i = 0; i < count_exams; i++) {
				cout << "������� �������� ��������: "; cin >> session[i].subject;
				cout << "������� ������ �� �������: "; cin >> session[i].mark;
			}
			//delete[] session;
		}
		else { cout << "������� ����� ���������" << endl; }
	}

	void print_session() {
		cout << "�������: " << session->subject << endl;
		cout << "������: " << session->mark << endl;
	}
};