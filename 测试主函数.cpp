//#include "Register.h"
#include <iostream>
#include "user.h"
#include <string>
#include "link.h"
#include "mainMenu.h"
using namespace std;

int main() {
	LinkedList userlist;
	while (1) {
		mainMenu(userlist);
	}
	//LinkedList userlist;
	//user u1;
	//u1.userRegister();
	//userlist.insert(u1);
	//char temp;
	//string idTemp = "";
	//string id = "";
	//while (1) {
	//	temp = cin.get();
	//	if (temp == '\n') {
	//		id = idTemp;//此处应有查重函数
	//		break;
	//	}
	//	if (temp == ' ') {//检测空格
	//		cout << "ID输入错误，请重新输入ID！" << endl;
	//		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
	//		continue;
	//	}
	//	idTemp = idTemp + temp;
	//	if (idTemp.size() > 20) {//检测大小
	//		cout << "ID输入错误，请重新输入ID！" << endl;
	//		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
	//		continue;
	//	}
	//}
	//user* user1 = userlist.find(id);
	//if (userlist.find(id) != NULL) {
	//	cout << 1 << endl;
	//}
	return 0;
}




