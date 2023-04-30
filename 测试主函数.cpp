// #include "Register.h"
#include <iostream>
#include "user.h"
#include <string>
#include "link.h"
#include "mainMenu.h"
#include <stdexcept>
#include <limits>

// for testing vvv
#include "userQuery.h"
// for testing ^^^

using namespace std;

int main()
{
	LinkedList userlist;

	user u1("1120214567", "Yuan", "18573323445", "1161871240@qq.com", 123456, 60);
	user u2("1120210000", "Wang", "18673300000", "111111111@gmail.com", 123456, 60);
	user u3("1120211111", "Li", "18320001111", "222222222@outlook.com", 123456, 60);
	user u4("1120212222", "Liu", "12300009999", "333333333@qq.com", 123456, 60);
	user u5("1120213333", "Dou", "98712340000", "444444444@qq.com", 123456, 60);
	user u6("1120214444", "FANG", "96312345678", "555555555@qq.com", 123456, 60);
	userlist.insert(u1);
	userlist.insert(u2);
	userlist.insert(u3);
	userlist.insert(u4);
	userlist.insert(u5);
	userlist.insert(u6);

	// You can uncomment this line for UserQuery
	// userQuery(userlist);

	while (1)
	{
		mainMenu(userlist);
	}
	// user u1;
	// u1.userRegister();
	// userlist.insert(u1);
	char temp;
	string idTemp = "";
	string id = "";
	while (1)
	{
		temp = cin.get();
		if (temp == '\n')
		{
			id = idTemp; // 此处应有查重函数
			break;
		}
		if (temp == ' ')
		{ // 检测空格
			cout << "ID输入错误，请重新输入ID！" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓存区
			continue;
		}
		idTemp = idTemp + temp;
		if (idTemp.size() > 20)
		{ // 检测大小
			cout << "ID输入错误，请重新输入ID！" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓存区
			continue;
		}
	}
	user *user1 = userlist.find(id);
	if (userlist.find(id) != NULL)
	{
		cout << 1 << endl;
	}
	return 0;
}
