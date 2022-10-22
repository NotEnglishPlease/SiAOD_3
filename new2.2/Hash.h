#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

const int N = 100;

struct cashReg
{
	int num; //����� �����
	int code; //��� ������
	int sum; //���������� ������
	float price; //���� ������
	float discount; //���������� ������ �� �����
	float disc_price; //���� � ������ ������
};

struct hashS //��������� ����
{
	int num; // ����� ������ � �����
	//cashReg reg;
	int numKey; // ����� ����� (����)
	//int hashKey; // ���
	hashS* next; // ������ �� �������� ������� ������ 
};
hashS table[N]; //������ �� ����������� ����

int hashing(int x) {
	string y = to_string(x);
	int key = char(y[y.length()-1]);
	return key;
}

void inputHash(cashReg tempReg, int num) {
	int key;
	key = hashing(tempReg.num);
	hashS* s = new hashS(table[key]);
	if (table[key].num != NULL) {
		while (s->num != NULL) s = s->next;
		s->next = s;
		s->numKey = tempReg.num;
		s->num = num;
	}
	else {
		table[key].numKey = tempReg.num;
		table[key].num = num;
	}
}

hashS* searchHash(int key) {
	int hashKey = hashing(key);
	hashS* s = new hashS(table[hashKey]);
	while (key != s->numKey) {
		s = s->next;
	}
	return s;
}

void delHash(int key) {
	int hashKey = hashing(key);
	hashS* s = searchHash(key);
	s->numKey = NULL;
	s->num = NULL;
	while (s->next != NULL) {
		s = s->next;
	}
}

void outHash() {
	int k = 0;
	for (int i = 1; i < 100; i++) {
		hashS* s = new hashS(table[i]);
		if (s->next == NULL) {
			cout << "______________________________________________\n";
			cout << "��� ����� " << i << '\n';
			cout << "����� �����: " << s->numKey << '\n';
			cout << "______________________________________________\n";
		}
		else {
			while (s->next != NULL) {
				k = k + 1;
				cout << "______________________________________________\n";
				cout << "��� ����� " << i << "." << k << '\n';
				cout << "����� �����: " << s->numKey << '\n';
				cout << "______________________________________________\n";
				s = s->next;
			}
			k = 0;
		}
	}
}