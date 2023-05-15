#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;

void Crypt()
{
	srand(time(NULL));
	string pass;
	for (int i = 0; i < 64; ++i) {
		switch (rand() % 3) {
		case 0:
			pass = rand() % 10 + '0';
			break;
		case 1:
			pass = rand() % 26 + 'A';
			break;
		case 2:
			pass = rand() % 26 + 'a';
		}
	}
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in DB_Students.txt -out DB_Students.txt.enc -pass pass:";
	command = command + pass;

	system(command.c_str());
	if (remove("DB_Students.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open("key.txt", ios::binary);
	file << pass;
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}
void Decrypt()
{
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());
	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	string pass;

	ifstream file;
	file.open("key.txt", ios::binary);
	file >> pass;
	file.close();
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in DB_Students.txt.enc -out DB_Students.txt -pass pass:";
	command = command + pass;
	system(command.c_str());
	if (remove("DB_Students.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}