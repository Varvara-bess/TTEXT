#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <string>
#include<fstream>

using namespace std;
#include "TTextLink.h"
#include "TText.h"


TTextMem TTextLink::MemHeader;

void TextMenu(TText &txt) 
{
	cout << endl;
	cout << "1 - printing text " << endl;
	cout << "2- go to beginning of text" << endl;
	cout << "3 - go to the next link" << endl;
	cout << "4 - go to the down link" << endl;
	cout << "5 - go to previous link" << endl;
	cout << "6 - delete the down link" << endl;
	cout << "7 - delete  the next link" << endl;
	cout << "8 - adding the down line" << endl;
	cout << "9 - adding the down sectoin" << endl;
	cout << "10 - adding the next line" << endl;
	cout << "11 - adding the next sectoin" << endl;
	cout << "12 - show free memory" << endl;
	cout << "13 - exit" << endl;
	string st;
	int i;


	do {
		
		cin >> i;
		switch (i){

		case 1: {
			txt.Print();
			cout << endl;
			break;
		}

		case 2: {
			txt.GoFirstLink();
			cout << "Start at " << txt.GetLine() << endl;
			break;
		}
		case 3:  {
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		}
		case 4: {
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		}
		case 5:  {
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		}
		case 6: {
			txt.delDown();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		}
		case 7: {
			txt.delNext();
			cout << "Now in " << txt.GetLine() << endl;
			break;
		}
		case 8: {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownLine(st);
			break;
		}
		case 9: {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownSect(st);
			break;
		}
		case 10: {
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
			break;
		}
		case 11:{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSect(st);
			break;
		}
		case 12: {
			TTextLink::PintFreeLink();
			break;
		}

		case 13: {
		
			cout << "exit" << endl;
			break;
		}
		}
	} while (i != 13);
}

	int main() {
		TTextLink::InitMemSystem(100);
		TText t;
		string ddd;
		t.Read("text.txt");
		t.write("text.txt");
		TextMenu(t);

		TTextLink::MemCleaner(t);
		TTextLink::PintFreeLink();
	}
				
			


		

