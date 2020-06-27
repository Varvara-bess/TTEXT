#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include <string> 
#include <conio.h>
#include <iostream>
using namespace std;
#include"TText.h"
#include"TTextLink.h"

TText::TText() {
	pFirst = NULL;
	TStack<TTextLink> stack;
}
void TText::GoFirstLink()
{
	pCurr = pFirst;
	stack.Clear();

}
void TText::GoDownLink(){
	if (!pCurr)
		throw - 1;
	if (!pCurr->pDown)
		return;
	stack.Push(pCurr);
	pCurr = pCurr->pDown;
}
int TText::IsEnd() {
	return stack.IsEmpty();
}
int TText::Reset() {
	while (!stack.IsEmpty()) {
		stack.Pop();
	}
	pCurr = pFirst;
	if (pCurr) {
		stack.Push(pCurr);
		if (pCurr->pNext) {
			stack.Push(pCurr->pNext);
		}
		if (pCurr->pDown) {
			stack.Push(pCurr->pDown);
		}
	}
	return IsEnd();
}
int TText::GoNext() {
	if (!IsEnd()) {
		pCurr = stack.Pop();
		if (pCurr != pFirst) {
			if (pCurr->pNext) {
				stack.Push(pCurr->pNext);
			}
			if (pCurr->pDown) {
				stack.Push(pCurr->pDown);
			}
		}
		return true;
	}
	return false;
}
void TText::GoPrevLink(){
	if (pCurr == NULL)
		throw - 1;
	if (stack.IsEmpty())
		return;
	pCurr = stack.Pop();
}
void TText::SetLine(string str1)
{
	if (pCurr == NULL) throw - 1;
	strcpy(pCurr->str, str1.c_str());
}
string TText::GetLine()
{
	string();
	return pCurr->str;

}
void TText::InsNextLine(string str)
{
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pNext;
	pCurr->pNext = p;

}
void TText::InsNextSect(string str){
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pNext = p;
}
void TText::InsDownSect(string str){
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str.c_str());
	p->pDown = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::InsDownLine(string str){
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str.c_str());
	p->pNext = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::delNext(){
	if (!pCurr)
		throw - 1;
	if (!pCurr->pNext)
		return;
	TTextLink *tmp = pCurr->pNext;
	pCurr->pNext = tmp->pNext;
	delete tmp;

}
void TText::delDown(){
	if (!pCurr)
		throw - 1;
	if (!pCurr->pDown)
		return;
	TTextLink *tmp = pCurr->pDown;
	pCurr->pDown = tmp->pNext;
	delete tmp;
}
void TText::Read(string fn){
	ifstream ifs(fn);
	level = 0;
	pFirst = ReadRec(ifs);

}
TTextLink* TText::ReadRec(ifstream& ifs){
	TTextLink *pHead, *p, *tmp;
	pHead = p = NULL;
	char str[81];
	while (!ifs.eof()){
		ifs.getline(str, 80, '\n');
		if (str[0] == '}') { break; }
		else if (str[0] == '{'){
			p->pDown = ReadRec(ifs);
		}
		else
		{
			tmp = new TTextLink(str);
			if (pHead == NULL){
				pHead = p = tmp;
			}
			else
			{
				p->pNext = tmp;
				p = p->pNext;
			}

		}
		if (!p->pDown){}

	}
	return pHead;
}
void TText::write(string fn)
{

	ofstream ofs(fn);
	level = 0;
	writeRec(ofs, pFirst);
}
void TText::writeRec(ofstream& ofs, TTextLink *p){
	for (int i = 0; i < level; i++) {
		cout << "  ";
	}
	ofs << p->str << endl;
	if (p->pDown != NULL){
		level++;
		ofs << '{' << endl;
		writeRec(ofs, p->pDown);
		ofs << '}' << endl;

	}
	if (p->pNext){
		writeRec(ofs, p->pNext);
		level++;
	}
	level--;
}
void TText::Print() {
	level = 0;
	PrintRec(pFirst);
}

void TText::PrintRec(TTextLink* pWC) {
	for (int i = 0; i < level; i++) {
		cout << "  ";
	}
	cout << pWC->str << endl;

	if (pWC->pDown)
	{
		level++;
		PrintRec(pWC->pDown);

	}
	if (pWC->pNext) {
		PrintRec(pWC->pNext);
		level++;
	}
	level--;
}
void TText::GoNextLink() {
	if (!pCurr) throw - 1;
	if (!pCurr->pNext) return;
	stack.Push(pCurr);
	pCurr = pCurr->pNext;
}