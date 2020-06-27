#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MemSize 100
#include<string>
#include <conio.h>
using namespace std;
class TText;
class TTextLink;
struct TTextMem {
	TTextLink* pFirst; 
	TTextLink* pLast; 
	TTextLink* pFree; 
	friend class TTextLink;
};
class TTextLink
{
protected:
	static TTextMem MemHeader; 
	friend class TText;
public:
	TTextLink *pNext;
	TTextLink *pDown;
	int level;
	char str[81];
	TTextLink(const char *c=NULL, TTextLink *pn = NULL, TTextLink *pd = NULL){
		level = 0;
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy(str, c);
	}
	static void InitMemSystem(int size = MemSize);
	static void PintFreeLink(void);
	void* operator new (size_t size);
	void operator delete (void* pM);
	static void MemCleaner(TText& txt);

};