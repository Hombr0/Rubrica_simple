#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int max_length = 20;
string names[max_length];
string surnames[max_length];
string numbers[max_length];

int len(string array[max_length]) {
	for (int i = 0; i < max_length; i++) {
		if (array[i] == "\0") {
			return i;
		}
	}
	return max_length;
};
void switch_element(string array[max_length], int first, int second) {
	string y;
	y = array[second];
	array[first] = y;
}

void delete_element(int index, int num_elements) {
	if (index >= 0 && index <= num_elements - 1) {
		if (index != num_elements - 1) {
			if (num_elements == 2) {
				switch_element(names, 0, 1);
				switch_element(surnames, 0, 1);
				switch_element(numbers, 0, 1);
			}
			else if (num_elements > 2) {
				for (int i = index; i < num_elements - 1; i++) {
					switch_element(names, i, i + 1);
					switch_element(surnames, i, i + 1);
					switch_element(numbers, i, i + 1);
				}
			}
		}
		names[num_elements - 1] = "\0";
		surnames[num_elements - 1] = "\0";
		numbers[num_elements - 1] = "\0";
	}
};

int string_len(string array[max_length]) {
	unsigned int max_size = 0;
	int size = len(array);
	if (size != 0) {
		string y;
		if (size == 1) {
			y = array[0];
			max_size = y.length();
		}
		else if (size == 2) {
			if (array[0].length() >= array[1].length()) {
				y = array[0];
				max_size = y.length();
			}
			else {
				y = array[1];
				max_size = y.length();
			}
		}
		else {
			for (int i = 0; i < size; i++) {
				if (array[i].length() >= max_size) {
					y = array[i];
					max_size = y.length();
				}
			};

		};
	};
	return max_size;
};

void print_contacts() {
	int l_names;
	int l_surnames;
	int l_numbers;
	int l_id;
	int size = len(names);
	if (size != 0) {
		l_names = string_len(names) + 4;
		l_surnames = string_len(surnames) + 4;
		l_numbers = string_len(numbers) + 4;
		l_id = 6;
		cout << setfill(' ') << setw(l_id) << "ID" << setw(l_names) << 
			"NOME" << setw(l_surnames) << "COGNOME" << setw(l_numbers) << 
			"NUMERO" << endl;
		for (int i = 0; i < size; i++) {
			cout << setfill(' ') << setw(l_id) << i + 1 << setw(l_names) <<
				names[i] << setw(l_surnames) << surnames[i] << setw(l_numbers) <<
				numbers[i] << endl;
		};
	};
};

void create_contact() {
	string a, b, c;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(17) << "" <<
		"CREA CONTATTO " << setfill(' ') << setw(17) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << "NOME: ";
	cin >> a;
	cout << "COGNOME: ";
	cin >> b;
	cout << "NUMERO DI TELEFONO: ";
	cin >> c;
	if (len(names) != max_length){
		names[len(names)] = a;
	}
	if (len(surnames) != max_length) {
		surnames[len(surnames)] = b;
	}
	if (len(numbers) != max_length) {
		numbers[len(numbers)] = c;
	}
};

void Title() {
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(15) << "" << "RUBRICA TELEFONICA" <<
		setfill(' ') << setw(15) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << endl <<
		"a. CREA CONTATTO" << endl <<
		"b. SELEZIONA CONTATTO" << endl << "c.ESCI" <<
		endl << endl;
	print_contacts();
	cout << endl << "Scegliere una delle opzioni (a o b) : ";
};

void Select() {
	int y, x;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(20) << "" <<
		"CONTATTI" << setfill(' ') << setw(20) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << endl;
	print_contacts();
	cout <<	endl << endl << "Scegliere il contatto da selezionare : ";
	cin >> y;
	int l_id = 6;
	int l_name = names[y - 1].length() + 4;
	int l_surname = surnames[y - 1].length() + 4;
	int l_number = numbers[y - 1].length() + 4;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(14) << "" <<
		"CONTATTO SELEZIONATO" << setfill(' ') << setw(14) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << "1. ELIMINA CONTATTO" <<
		endl << "2. ESCI" << endl  << endl << setfill(' ') << setw(l_id) << "ID" << 
		setw(l_name) << "NOME" << setw(l_surname) << "COGNOME" << setw(l_number) <<
		"NUMERO" << endl << setfill(' ') << setw(l_id) << y << setw(l_name) <<
		names[y - 1] << setw(l_surname) << surnames[y - 1] << setw(l_number) <<
		numbers[y - 1] << endl << endl << "Scegliere una delle opzioni (1 o 2) : ";
	cin >> x;
	switch (x) {
	case 1:
		delete_element(y - 1, len(names));
		break;
	case 2:
		break;
	}
}

int main() {
	char a;
	char stop = 'z';
	while (1) {
		Title();
		cin >> a;
		if (a == 'a') {
			create_contact();
			a = stop;
		}
		else if (a == 'b') {
			Select();
			a = stop;
		}
		else if (a == 'c') {
			break;
		}
		system("cls");
	};
}
