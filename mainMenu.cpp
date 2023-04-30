#include "mainMenu.h"
#include <iostream>
#include <string>
#include "link.h"
#include <stdexcept>
#include <limits>


user* login(LinkedList &L1) {
	cout << "返回主界面请输入：1       继续登录请输入：2" << endl;
	int choice;
	while (1) {
		string choiceTemp;
		cin >> choiceTemp;//此处缺少合法性检测
		if (!isChoice(choiceTemp)) {
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
			cout << "-----------------------------------" << endl;
			cout << "请重新输入，只能输入1或者2" << endl;
		}
		else {
			choice = stoi(choiceTemp);
			break;
		}
	}
	
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
	if (choice == 1) {
		//mainMenu(L1);
	}
	else if (choice == 2) {
		//L1.print();
		while (1){
			string id = "";
			cout << "-----------------------------------" << endl;
			cout << "请输入您的ID:" << endl;
			char temp;
			string idTemp = "";
			while (1) {
				temp = cin.get();
				if (temp == '\n') {
					id=idTemp;
					//此处应有查重函数
					break;
				}
				if (temp == ' ') {//检测空格
					cout << "ID输入错误，请重新输入ID！" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
					continue;
				}
				idTemp = idTemp + temp;
				if (idTemp.size() > 20) {//检测大小
					cout << "ID输入错误，请重新输入ID！" << endl;
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
					continue;
				}
			}
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
			user* findUser = L1.find(id);
			if (findUser != NULL) { //验证是否找到ID
				cout << "-----------------------------------" << endl;
				cout << "请输入密码：" << endl;
				string password;
				cin >> password;
				
				if (isNum(password)==true) {
					if (stoi(password) == (findUser->getPassword())) {
						cout << "-----------------------------------" << endl;
						cout << "登录成功！" << endl;
						cout << "-----------------------------------" << endl;
						return (findUser);
						break;
					}
					else {
						cout << "密码错误，请重新登录！" << endl;
						cin.get();//吃掉换行符
					}
				}
				else {
					cout << "密码输入有误，请重新登录！" << endl;
					cin.get();//吃掉换行符
				}
			}
			else {
				cout << "ID输入错误，请重新登录！" << endl;
			}
		}
	}
	return NULL;
}

void mainMenu(LinkedList& userlist) {
	cout << "欢迎来到约瑟夫环小游戏" << endl;
	cout << "登录请输入1。" << endl;
	cout << "开户请输入2。" << endl;
	cout << "退出请输入3。" << endl;
	string in;
	while (1) {
		string temp;
		cin >> temp;
		if (isMenu(temp)==true) {
			in = temp;
			break;
		}
		cout << "输入错误，请重新输入!" << endl;
		cout << "-----------------------------------" << endl;
	}
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
	
	if (stoi(in) == 1) {
		//userlist.print();
		login(userlist);

	}
	if (stoi(in) == 2) {
		user u1;
		u1.userRegister();//注册函数
		userlist.insert(u1);//插入用户表
		//mainMenu(userlist);
	}
	if (stoi(in) == 3) {
		cout << "游戏已退出，祝您生活愉快！" << endl;
		cout << "-----------------------------------" << endl;
		exit(0);
	}
}



bool isNum(string s) { //判断是否为整型
	//题目只保证第二个非空，第一个未说
	if (s.length() < 1)
		return false;
	int flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[0] == '-' && flag == 0) {
			flag++;
			continue;
		}
		if ((!isdigit(s[i])))//不是数字，返回false
			return false;
	}
	//遍历完后，可以断定是数字，判断是否越界
	if (stoi(s) <= -1000000 || stoi(s) >= 1000000)
		return false;
	return true;
}

bool isMenu(string s) { //判断是否为整型
	//题目只保证第二个非空，第一个未说
	if (s.length() != 1) {
		//cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
		

	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]))//不是数字，返回false
			return false;
	}
	//遍历完后，可以断定是数字，判断是否越界
	if (stoi(s) < 1 || stoi(s) >= 4)
		return false;
	return true;
}

bool isChoice(string s) { //判断是否为整型
	if (s.length() != 1) {
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}


	if (!isdigit(s[0])){//不是数字，返回false
			return false;
	}

	//遍历完后，可以断定是数字，判断是否越界
	if (stoi(s) < 1 || stoi(s) >= 3)
		return false;

	return true;
}