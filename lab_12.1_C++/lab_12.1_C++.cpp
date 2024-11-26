#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isValidForFunction(double value) {
	return value >= 0;
}

void parseFile(string name_1, string name_2) {
	ifstream file_1(name_1, ios::binary);

	if (!file_1) {
		ofstream file_1_new(name_1, ios::binary);
		file_1_new.close();
		cout << "Empty file was created.\n";
		return;
	}

	ofstream file_2(name_2, ios::binary);

	double value;
	while (file_1.read((char*)&value, sizeof(double))) {
		if (!isValidForFunction(value)) {
			file_2.write((char*) &value, sizeof(double));
		}
	}

	file_1.close();
	file_2.close();
}

void printFile(string name, string text) {
	ifstream file(name, ios::binary);
	if (!file) {
		cout << "Could not open file for reading: " << name << endl;
		return;
	}

	double value;
	cout << "¬м≥ст " << text << " файлу: ";
	while (file.read((char*)&value, sizeof(double))) {
		cout << value << ' ';
	}
	file.close();
	cout << endl;
}

void writeFile(string name) {
	ofstream file(name, ios::binary);
	if (!file) {
		cout << "Could not open file for writing: " << name << endl;
		return;
	}

	cout << "Add data (type 'end' to finish): \n";
	string data;

	while (true) {
		cout << "> ";
		getline(cin, data);

		if (data == "end") {
			break;
		}

		double value;
		try {
			value = stod(data);
		}
		catch (invalid_argument) {
			cout << "Invalid input, only numbers are accepted." << endl;
			continue;
		}

		file.write((char*)&value, sizeof(double));
	}
	file.close();
}


int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string name_1;
	string name_2;

	cout << "Enter first filename: "; cin >> name_1;
	cin.ignore();
	cout << "Enter second filename: "; cin >> name_2;
	cin.ignore();

	writeFile(name_1);

	parseFile(name_1, name_2);

	printFile(name_1, "вх≥дного");
	printFile(name_2, "вих≥дного");

}