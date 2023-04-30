#ifndef USER
#define USER
#include <string>
#include <iostream>
//#include "Register.h"

using namespace std;

class user {
protected:
	string id;
	string name;
	string teleNum;
	string email;
	int password;
	int score;
public:
	user();//¹¹Ôìº¯Êý
	void userRegister();
	string getId();
	string getName();
	string getTeleNum();
	string getEmail();
	int getPassword();
	int getScore();
};





//Register.h
string idRegister();
string nameRegister();
string teleNumRegister();
string emailRegister();
int passwordRegister();
#endif
