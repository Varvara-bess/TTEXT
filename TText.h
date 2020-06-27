#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include <conio.h>
using namespace std;
#include"TTextLink.h"
#include"Stack.h"
class TText{
	int level;
	TTextLink *pFirst;
	TTextLink *pCurr;
	TStack<TTextLink*> stack;
public:
	TText();
	void GoFirstLink();
	void GoDownLink();
	int IsEnd();
	int Reset();
	int GoNext();
	void GoNextLink();
	void GoPrevLink();
	void SetLine(string str1);
	string  GetLine();
	void InsNextLine(string str);
	void  InsNextSect(string str);
	void  InsDownSect(string str);
	void  InsDownLine(string str);
	void delNext();
	void delDown();
	void Read(string fn);
	TTextLink *ReadRec(ifstream & ifs);
	void write(string fn);
	void writeRec(ofstream& ofs, TTextLink *p);
	void Print();
	void TText::PrintRec(TTextLink* pWC);


};