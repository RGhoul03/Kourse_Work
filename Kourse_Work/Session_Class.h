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
		cout << "Введите кол-во экзаменов: "; cin >> count_exam;
		if (count_exam > 0 && count_exam < 11) {
			session = new Exam[count_exam+1];
			for (int i = 0; i < count_exam; i++) {
				session[i].count_exams = count_exam + 1;
				cout << "Введите название экзамена: "; cin >> session[i].subject;
				cout << "Введите оценку за экзамен: "; cin >> session[i].mark;
			}
			//delete[] session;
			session[count_exam].subject = 'e';
			session[count_exam].mark = 0;
		}
		else { cout << "Слишком много экзаменов" << endl; }
	}

	void print_session() {
		cout << "Экзамен: " << session->subject << endl;
		cout << "Оценка: " << session->mark << endl;
	}
};