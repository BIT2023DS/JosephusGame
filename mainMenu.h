#ifndef MAINMENU
#define MAINMENU

#include <iostream>
#include "link.h"
#include <string>
using namespace std;

user* login(LinkedList &L1);//打开登录界面,返回登录的用户对象的指针

void mainMenu(LinkedList &userlist);//打开主界面

bool isNum(string s);

bool isMenu(string s);

bool isChoice(string s);

#endif