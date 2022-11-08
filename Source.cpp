#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	int choice;
	int bochok;
	int temp = 0;
	cout << "Сколько бочонков в мешке?: ";
	cin >> n;
	vector <int> meshok(n + 2);
	for (int i = 0; i < n+1; i++) {
		meshok[i] = i;
	}
	START1:
	cout << "Введите 1 чтобы вытянуть случайный бочонок или 2, чтобы выйти:";
	cin >> choice;
	if (choice == 1) {
		bochok = rand() % n + 1;
		meshok[bochok] = 0;
		cout << "Выпал бочонок с номером " << bochok << endl;
		temp = temp + 1;
	}
	else if (choice == 2) {
		exit(0);
	}
	else {
		cout << "Введите или 1 или 2!" << endl;
		goto START1;
	}
	START3:
	cout << "Продолжить вытягивать бочки?(1 - да, 2 - нет): ";
	cin >> choice;
	if (choice == 1) {
	START2:
		bochok = rand() % n + 1;
		if (meshok[bochok] == 0) {
			goto START2;
		}
		meshok[bochok] = 0;
		cout << "Выпал бочонок с номером " << bochok << endl;
		temp = temp + 1;
		if (temp == n) {
			cout << " Бочки закончились ";
			exit(0);
		}
		goto START3;
	}
	else if (choice == 2) {
		exit(0);
	}
	else {
		cout << "Введите или 1 или 2! " << endl;
		goto START3;
	}
}