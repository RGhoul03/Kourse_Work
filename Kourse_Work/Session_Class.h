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
		cout << "Введите кол-во экзаменов: "; cin >> count_exams;
		if (count_exams > 0 && count_exams < 11) {
			session = new Exam[count_exams];
			for (int i = 0; i < count_exams; i++) {
				cout << "Введите название экзамена: "; cin >> session[i].subject;
				cout << "Введите оценку за экзамен: "; cin >> session[i].mark;
			}
			//delete[] session;
		}
		else { cout << "Слишком много экзаменов" << endl; }
	}

	void print_session() {
		cout << "Экзамен: " << session->subject << endl;
		cout << "Оценка: " << session->mark << endl;
	}
};