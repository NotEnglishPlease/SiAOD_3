#include <iostream>
#include <time.h>
#include <string>
#include "Hash.h"

using namespace std;

void createF(string name);
void createRandF(string name);
void addToBin(string name);
void txtToBin(string name, string nameBin);
void printBin(string name);
void hashBin(string name);
cashReg getByNum(string name, int num);
cashReg searchByKey(string name, int key);
void delEl(int key, string name);
void delByKey(string name, int key, cashReg x);
cashReg getLast(string name);
cashReg searchByKey(string name, int key);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true;
	string s, fileName, fileName2;
	int n, typeCreate, key;
	cashReg x;
	while (flag)
	{
		system("cls");
		cout << "Практическая работа №3 ИКБО-06-21 Эрднеева Н.Д. Варинат 30" << "\n\n"
			"Меню\n"
			"0) +Вывод содержимого двоичного файла\n"
			"1) +Создание текствого файла.\n"
			"2) +Cоздание двоичного файла из текстового.\n"
			"3) +Добавить запись в двоичный файл.\n"
			"4) +Хэшировать содержимое двоичного файла.\n"
			"5) +Вывод содержимого хэш-таблицы.\n"
			"6) +Прочитать запись из файла по заданному номеру.\n"
			"7) -Удалить запись из таблицы при заданном значении ключа и соответственно из файла.\n"
			"8) +Найти запись в файле по значению ключа.\n"
			"9) -Рехэшированиеа.\n"; //увелич табл
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 0:
		{
			cout << "Введине имя двоичного файла: ";
			cin >> fileName2;
			printBin(fileName2);
			system("pause");
			break;
		}
		case 1:
		{
			cout << "Введине имя текстового файла: ";
			cin >> fileName;
			cout << "Для заполнение с клавиатуры введите 0, иначе (случайными числами) любую другую цифру: ";
			cin >> typeCreate;
			if (typeCreate == 0) createF(fileName);
			else createRandF(fileName);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введине имя двоичного файла: ";
			cin >> fileName2;
			txtToBin(fileName, fileName2);
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введине имя двоичного файла: ";
			cin >> fileName2;
			addToBin(fileName2);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введине имя двоичного файла: ";
			cin >> fileName2;
			hashBin(fileName2);
			system("pause");
			break;
		}
		case 5:
		{
			outHash();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Введите порядковый номер записи в файле: ";
			cin >> n;
			x = getByNum(fileName2, n);
			if (x.num == NULL)
			{
				cout << x.num << '\n';
				cout << x.code << '\n';
				cout << x.sum << '\n';
				cout << x.price << '\n';
				cout << x.discount << '\n';
				cout << x.disc_price << '\n';
			}
			else cout << "Данной записи в файле нет\n";
			system("pause");
			break;
		}
		case 7:
		{
			system("pause");
			break;
		}
		case 8:
		{
			cout << "Введите ключ: ";
			cin >> key;
			cout << "Введине имя двоичного файла: ";
			cin >> fileName2;
			searchByKey(fileName2, key);
			system("pause");
			break;
		}
		case 9:
		{
			system("pause");
			break;
		}
		break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз.\n";
			system("pause");
			break;
		}
	}
	return 0;
}

void createF(string name) {
	int structs;
	cout << "Введите количество структур в файле: ";
	cin >> structs;
	cout << "Введите содержимое файла: \n";
	cashReg s;
	ofstream f(name);
	cin.ignore();
	for (int i = 0; i < structs; i++) {
		cout << "Структура 1:" << "\nНомер кассы: ";
		cin >> s.num;
		cout << "Код товкара: ";
		cin >> s.code;
		cout << "Количество товкара: ";
		cin >> s.sum;
		cout << "Цена товкара: ";
		cin >> s.price;
		cout << "Процентная скидка на товкар: ";
		cin >> s.discount;
		s.disc_price = s.price - s.price * (s.discount / 100);
		f << s.num << '\n';
		f << s.code << '\n';
		f << s.sum << '\n';
		f << s.price << '\n';
		f << s.discount << '\n';
		f << s.disc_price << '\n';
	}
	f.close();
}

void createRandF(string name) {
	int structs = 2 + (rand() % 3);
	int j = 0;
	cashReg s;
	ofstream f(name);
	bool flag = false;
	int* arr = NULL;
	arr = new int[structs];
	for (int i = 0; i < structs; i++) {
		s.num = 1 + (rand() % 3);
		if (i == 0) {
			arr[i] = s.num;
		}
		else {
			while (flag == false) {
				for (j = 0; j < structs; j++) {
					if (arr[j] == s.num) {
						s.num = 1 + (rand() % 3);
						break;
					}
				}
				if (j+1 >= structs) {
					flag = true;
				}
			}
			flag = false;
			arr[i] = s.num;
		}
		s.code = 1 + (rand() % 1000);
		s.sum = 1 + (rand() % 100);
		s.price = 1 + (rand() % 1000);
		s.discount = 1 + (rand() % 100);
		s.disc_price = s.price - s.price * (s.discount / 100);
		f << s.num << '\n';
		f << s.code << '\n';
		f << s.sum << '\n';
		f << s.price << '\n';
		f << s.discount << '\n';
		f << s.disc_price << '\n';
	}
	f.close();
}

void txtToBin(string name, string nameBin)
{
	ifstream ft;
	ofstream fb;
	ft.open(name, ios::in);
	if (!ft) cout << "Файл не открыт\n";
	fb.open(nameBin, ios::out | ios::binary | ios::trunc);
	while (!ft.eof())
	{
		cashReg newS;
		ft >> newS.num;
		ft >> newS.code;
		ft >> newS.sum;
		ft >> newS.price;
		ft >> newS.discount;
		ft >> newS.disc_price;
		if (!ft.eof()) {
			ft.get();
			fb.write((char*)&newS, sizeof(cashReg));
		}
	}
	ft.close();
	fb.close();
}

void addToBin(string name) {
	ofstream fb;
	fb.open(name, ios::out | ios::binary);
	cashReg s;
	cout << "Номер кассы : ";
	cin >> s.num;
	cout << "Код товкара: ";
	cin >> s.code;
	cout << "Количество товкара: ";
	cin >> s.sum;
	cout << "Цена товкара: ";
	cin >> s.price;
	cout << "Процентная скидка на товкар: ";
	cin >> s.discount;
	s.disc_price = s.price - s.price * (s.discount / 100);
	fb.write((char*)&s, sizeof(cashReg));
	fb.close();
}

void printBin(string name)
{
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "Файл не открыт\n";
	cashReg x;
	fb.read((char*)&x, sizeof(cashReg));
	while (!fb.eof())
	{
		cout << x.num << '\n';
		cout << x.code << '\n';
		cout << x.sum << '\n';
		cout << x.price << '\n';
		cout << x.discount << '\n';
		cout << x.disc_price << "\n\n";
		fb.read((char*)&x, sizeof(cashReg));
	}
	fb.close();
}

void hashBin(string name) {
	int k = 0;
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "Файл не открыт\n";
	cashReg x;
	fb.read((char*)&x, sizeof(cashReg));
	while (!fb.eof())
	{
		inputHash(x, k);
		k = k + 1;
		fb.read((char*)&x, sizeof(cashReg));
	}
	fb.close();
}

cashReg getByNum(string name, int num) {
	ifstream fb;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "Файл не открыт\n";
	fb.seekg((num - 1) * sizeof(cashReg), ios::beg);
	cashReg x;
	fb.read((char*)&x, sizeof(cashReg));
	fb.close();
	return x;
}

void delByKey(string name, int key, cashReg x) {
	fstream fb;
	cashReg y;
	int pos;
	bool flag = false;
	fb.open(name, ios::in | ios::out | ios::binary);
	if (!fb) cout << "Файл не открыт\n";
	fb.read((char*)&y, sizeof(cashReg));
	int i = 0;
	while (!fb.eof())
	{
		if (y.num == key)
		{
			fb.seekg(i * sizeof(cashReg), ios::beg);
			fb.write((char*)&x, sizeof(cashReg));
			flag = true;
			break;
		}
		else
		{
			i++;
			fb.read((char*)&y, sizeof(cashReg));
		}
	}
	if (flag == false) cout << "Данной записи в файле нет\n";
	fb.close();
}

cashReg getLast(string name)
{
	int i = 0;
	fstream fb;
	cashReg x;
	fb.open(name, ios::in | ios::binary);
	if (!fb) cout << "Файл не открыт\n";
	fb.read((char*)&x, sizeof(cashReg));
	while (!fb.eof())
		fb.read((char*)&x, sizeof(cashReg));
	fb.close();
	return (x);
}

void delEl(int key, string name) {
	delHash(key);
	hashS* x = searchHash(key);
	int k = x->num;
	delByKey(name, key, getLast(name));
}

cashReg searchByKey(string name, int key) {
	hashS* x = searchHash(key);
	return getByNum(name, x->num);
}