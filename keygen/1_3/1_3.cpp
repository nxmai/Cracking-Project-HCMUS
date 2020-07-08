#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int checkValidName(string s) {
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if ((s[i] < 'A' || s[i]>'Z') && (s[i] < 'a' || s[i]>'z'))
			return 0;
	}
	return 1;
}

int main()
{
	string name;
	
	cout << "----CHUYEN TEN THANH SERIAL----";
	while (1) {
		cout << "\nNhap ten: ";
		getline(cin, name);

		if (checkValidName(name) == 0)
			cout << "Ten khong hop le. Vui long nhap lai. ";
		else
			break;
	}

	transform(name.begin(), name.end(), name.begin(), ::toupper);

	int edi = 0;
	for (int i = 0; i < name.length(); i++) {
		edi += int(name[i]);
	}

	int dec5678, dec1234;
	stringstream ss1, ss2;
	ss1 << 5678;
	ss1 >> hex >> dec5678;
	ss2 << 1234;
	ss2 >> hex >> dec1234;
	
	edi ^= dec5678;
	edi ^= dec1234;

	cout << "Serial: " << edi << endl;

	system("pause");
	return 0;
}
