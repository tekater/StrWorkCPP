#pragma warning(disable:4996) // Очень важно - без этого strcat не работает.

#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>

using namespace std;

void remover(char*& word) {
	char* copy = new char[127];
	cout << word << endl;
	int remove = 0; cout << "Какой символ удалить ?\n"; cin >> remove; remove--;
	for (int i = 0, j = 0; i < strlen(word); i++, j++) {
		if (i != remove) {
			copy[j] = word[i];
		}
		else {
			j--;
		}
	}
	copy[strlen(word) - 1] = '\0';
	delete word;
	word = copy;
}

void remover2(char*& word) {
	char* copy = new char[127];
	cout << word << endl;
	int remove = 0; cout << "C какого символа удалять ?\n"; cin >> remove; remove--;
	for (int i = 0, j = 0; i < strlen(word); i++, j++) {
		if (i != remove) {
			copy[j] = word[i];
		}
		else {
			copy[j] = '\0';
			i = remove;
		}
	}
	copy[strlen(word) - 1] = '\0';
	delete word;
	word = copy;
}

void adder(char*& word) {

	char* copy = new char[127];
	cout << word << endl;

	int add = 0; cout << "Выберите позицию:\n";  cin >> add; add--;
	char sym; cout << "Введите символ:\n"; cin >> sym;
	for (int i = 0, j = 0; i < strlen(word); i++, j++) {
		if (i != add) {
			copy[j] = word[i];
		}
		else {
			copy[j] = sym;
		}
	}
	copy[strlen(word) - 1] = '\0';
	delete word;
	word = copy;
}
void changer(char*& word) {
	cout << word << endl;
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == '.') {
			word[i] = '!';
		}
	}
}
void searcher(char*& word) {
	cout << word << endl;
	char sym; cout << "Введите символ который хотите посчитать:\n"; cin >> sym;
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == sym) {
			count++;
		}
	}
	cout << "Ваш символ встречался в строке " << count << " раз.\n";
}
void Counter(char word[127]) {
 int num = 0; int sym = 0; 
 int bukv = 0; int space = 0;

 for (int i = 0; i < strlen(word); i++) {
	 if (isalpha(word[i])) {
		 bukv++;
	 }
	 else if (isdigit(word[i])) {
		 num++;
	 }
	 else if (isspace(word[i])) {
		 space++;
	 }
	 else {
		 sym++;
	 }
 }

	cout << word << endl;
	cout << "Букв: " << bukv << "\nЦифр: " << num << "\nСимволов: " << sym << "\nПробелов: " << space;
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    //system("color B5");

	cout << "Задание 1\n";

	char* tabuta = new char[127] {"Привет, тебе очень нужно удалить мой символ"};
	remover(tabuta);
	cout << tabuta << endl;


	cout << "\n\nЗадание 2\n";
	char* tabuter = new char[127] {"Привет, тебе очень нужно удалить мои драгоценные символы"};
	remover2(tabuter);
	cout << tabuter << endl;


	cout << "\n\nЗадание 3\n";
	char* tadd = new char[127] {"Привет, тебе очень нужно добавть мне новые символы"};
	adder(tadd);
	cout << tadd << endl;


	cout << "\n\nЗадание 4\n";
	char* tochker = new char[127] {"Привет,.тебе.очень.нужно.заменить.все.мои.точки)"};
	changer(tochker);
	cout << tochker << endl;


	cout << "\n\nЗадание 5\n";
	char* symvoler = new char[127] {"u m8nya 2 0ch3an mbn*ga #### sym60lov p0310my vvodi "};
	searcher(symvoler);


	cout << "\n\nЗадание 6\n";
	char strcount[127] = "Abc 123 *** 12 - morkovok. 15 - yablok";
	Counter(strcount);

}
