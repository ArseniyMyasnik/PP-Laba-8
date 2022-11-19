#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

void GetInput(int& x) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << std::ctime(&end_time) << "Pol'zovatel' vvel: " << x << endl;
}
void GetNum(int& x) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << x;
}
void GetOutput(string& xx) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << std::ctime(&end_time) << xx << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	string xx;
	int n;
	int choice;
	int bochok;
	int temp = 0;
	xx = "Skol'ko bochonkov v meshke?: ";
	cout << xx;
	GetOutput(xx);
	cin >> n;
	GetInput(n);
	vector <int> meshok(n + 2);
	for (int i = 0; i < n + 1; i++) {
		meshok[i] = i;
	}
START1:
	xx = "Vvedite 1 chtoby vytyanut' sluchajnyj bochonok ili 2, chtoby vyjti:";
	cout << xx;
	GetOutput(xx);
	cin >> choice;
	GetInput(choice);
	if (choice == 1) {
		bochok = rand() % n + 1;
		meshok[bochok] = 0;
		xx = "Vypal bochonok s nomerom ";
		cout << xx;
		GetOutput(xx);
		xx = bochok;
		cout << xx << endl;
		GetNum(bochok);
		temp = temp + 1;
	}
	else if (choice == 2) {
		exit(0);
	}
	else {
		xx = "Vvedite ili 1 ili 2!";
		cout << xx << endl;
		GetOutput(xx);
		goto START1;
	}
START3:
	xx = "Prodolzhit' vytyagivat' bochki?(1 - da, 2 - net): ";
	cout << xx;
	GetOutput(xx);
	cin >> choice;
	GetNum(choice);
	if (choice == 1) {
	START2:
		bochok = rand() % n + 1;
		if (meshok[bochok] == 0) {
			goto START2;
		}
		meshok[bochok] = 0;
		xx = "Vypal bochonok s nomerom ";
		cout << xx;
		GetOutput(xx);
		xx = bochok;
		cout << bochok << endl;
		GetNum(bochok);
		temp = temp + 1;
		if (temp == n) {
			xx = " Bochki zakonchilis' ";
			cout << xx;
			GetOutput(xx);
			exit(0);
		}
		goto START3;
	}
	else if (choice == 2) {
		exit(0);
	}
	else {
		xx = "Vvedite ili 1 ili 2! ";
		cout << xx << endl;
		GetOutput(xx);
		goto START3;
	}
}