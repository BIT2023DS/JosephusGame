//#include <string>
//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//#include "Register.h"
//using namespace std;
//
//string idRegister() {//用户创建，ID输入函数
//	string id = "";
//	while (1) {
//		id = "";
//		cout << "请输入ID,ID最大长度为20个字符，不允许使用空格，只允许使用字母，数字，符号，输入完毕后摁Enter继续：" << endl;
//		char temp;
//		int flag = 0;
//		while (1) {
//			temp = cin.get();
//			if (temp == '\n') {
//				此处应有查重函数
//				break;
//			}
//			if (temp == ' ') {//检测空格
//				cout << "ID输入不合法，请重新输入ID！" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//			id = id + temp;
//			if (id.size() > 20) {//检测大小
//				cout << "ID输入不合法，请重新输入ID！" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//		}
//
//		if (flag == 0) {
//			break;
//		}
//	}
//	return id;
//}
//
//string nameRegister() {
//	string name = "";
//	while (1) {
//		name = "";
//		cout << "请输入名字,名字最大长度为20个字符，不允许使用空格，只允许使用字母，数字，符号，输入完毕后摁Enter继续：" << endl;
//		char temp;
//		int flag = 0;
//		while (1) {
//			temp = cin.get();
//			if (temp == '\n') {
//				此处应有查重函数
//				break;
//			}
//			if (temp == ' ') {//检测空格
//				cout << "名字输入不合法，请重新输入名字！" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//			name = name + temp;
//			if (name.size() > 20) {//检测大小
//				cout << "名字输入不合法，请重新输入名字！" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//		}
//
//		if (flag == 0) {
//			break;
//		}
//	}
//	return name;
//}
//
//string teleNumRegister() {
//	string teleNum;
//	while (1) {
//		teleNum = "";
//		cout << "请输入11位电话号码,输入完毕后摁Enter继续：" << endl;
//		char temp;
//		int flag = 0;
//		while (1) {
//			temp = cin.get();
//			if (temp == '\n') {
//				此处应有查重函数
//				if (teleNum.size() != 11) {//检查电话号码是否合法
//					cout << "电话号码输入不合法，请重新输入电话号码！1" << endl;
//					flag++;
//				}
//				break;
//			}
//			else if (!(temp >= 48 && temp <= 57)) {//检测空格
//				cout << "电话号码输入不合法，请重新输入电话号码！2" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//			teleNum = teleNum + temp;
//		}
//		if (flag == 0) {
//			break;
//		}
//	}
//	return teleNum;
//}
//
//string emailRegister() {//这个邮箱检测还得再写写
//	string email = "";
//	while (1) {
//		email = "";
//		cout << "请输入邮箱,输入完毕后摁Enter继续：" << endl;
//		char temp;
//		int flag = 0;
//		while (1) {
//			temp = cin.get();
//			if (temp == '\n') {
//				此处应有查重函数
//				break;
//			}
//			if (temp == ' ') {//检测空格
//				cout << "邮箱输入不合法，请重新输入邮箱！" << endl;
//				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//清空输入缓存区
//				flag++;
//				break;
//			}
//			email = email + temp;
//		}
//		if (flag == 0) {
//			break;
//		}
//	}
//	return email;
//}
//
//string passwordRegister() {
//	string password = "";
//	int k = rand() % 10 + 6;                  //随机生成一个6-15位的字符串 
//
//	for (int i = 1; i <= k; i++)
//	{
//		int x, s;                        //x表示这个字符的ascii码 ，s表示这个字符的大小写  
//		s = rand() % 2;                     //随机使s为1或0，为1就是大写，为0就是小写 
//		if (s == 1) {
//			x = rand() % ('Z' - 'A' + 1) + 'A'; //如果s=1,将x赋为大写字母的ascii码 
//		}
//		else {
//			x = rand() % ('z' - 'a' + 1) + 'a';       //如果s=0，x赋为小写字母的ascii码 
//		}
//		password = password + char(x);
//	}
//	cout << "密码：" << password << endl;
//	return password;
//}