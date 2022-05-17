#include <iostream>
#include <string>
#include <fstream>
using namespace std;



void foo(string f1, string f2)
{
	string s, s1;
	int nRes[255] = { 0 };

	fstream f(f1, ios_base::in);
	// Переносим файл в строку
	while (!f.eof())
	{
		getline(f, s1);
		s.append(s1);
	}

	for (char &c : s) {
		if (c != ' ') {

			nRes[(int)c] += 1;
		}
	}

	fstream fOut(f2, ios_base::out);

	for (int i = 0; i < 128; i++) {

		if (nRes[i] != 0) {
			fOut << (char)i << " - " << nRes[i] << "; ";
		}
	}
	f.close();
	fOut.close();
}

int main(){
	foo("in.txt", "out.txt");
}