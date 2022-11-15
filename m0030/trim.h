#ifndef __TRIM__H__
#define __TRIM__H__

#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <string>
using namespace std;


// put enum here
enum trimType{BOTH, FRONT, END};

// put prototypes here
void cTrim(char* str, trimType type);
void sTrim(string &str, trimType type);

#endif