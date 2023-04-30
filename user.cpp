#include <string>
#include <iostream>
#include "user.h"
#include <time.h>
using namespace std;


user::user() {
	id = "";
	name = "";
	teleNum = "";
	email = "";
	password = 0;
	score = 0;
}

void user::userRegister() {
	id = idRegister();
	name = nameRegister();
	teleNum = teleNumRegister();
	email = emailRegister();
	password = passwordRegister();
}

string user::getId() {
	return id;
}

string user::getName() {
	return name;
}

string user::getTeleNum() {
	return teleNum;
}

string user::getEmail() {
	return email;
}

int user::getPassword() {
	return password;
}

int user::getScore() {
	return score;
}






string idRegister() {//�û�������ID���뺯��
	string id = "";
	while (1) {
		id = "";
		cout << "������ID,ID��󳤶�Ϊ20���ַ���������ʹ�ÿո�ֻ����ʹ����ĸ�����֣����ţ�������Ϻ���Enter������" << endl;
		char temp;
		int flag = 0;
		while (1) {
			temp = cin.get();
			if (temp == '\n') {
				//�˴�Ӧ�в��غ���
				break;
			}
			if (temp == ' ') {//���ո�
				cout << "ID���벻�Ϸ�������������ID��" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
			id = id + temp;
			if (id.size() > 20) {//����С
				cout << "ID���벻�Ϸ�������������ID��" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
		}

		if (flag == 0) {
			break;
		}
	}
	return id;
}

string nameRegister() {
	string name = "";
	while (1) {
		name = "";
		cout << "����������,������󳤶�Ϊ20���ַ���������ʹ�ÿո�ֻ����ʹ����ĸ�����֣����ţ�������Ϻ���Enter������" << endl;
		char temp;
		int flag = 0;
		while (1) {
			temp = cin.get();
			if (temp == '\n') {
				//�˴�Ӧ�в��غ���
				break;
			}
			if (temp == ' ') {//���ո�
				cout << "�������벻�Ϸ����������������֣�" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
			name = name + temp;
			if (name.size() > 20) {//����С
				cout << "�������벻�Ϸ����������������֣�" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
		}

		if (flag == 0) {
			break;
		}
	}
	return name;
}

string teleNumRegister() {
	string teleNum;
	while (1) {
		teleNum = "";
		cout << "������11λ�绰����,������Ϻ���Enter������" << endl;
		char temp;
		int flag = 0;
		while (1) {
			temp = cin.get();
			if (temp == '\n') {
				//�˴�Ӧ�в��غ���
				if (teleNum.size() != 11) {//���绰�����Ƿ�Ϸ�
					cout << "�绰�������벻�Ϸ�������������绰���룡" << endl;
					flag++;
				}
				break;
			}
			else if (!(temp >= 48 && temp <= 57)) {//���ո�
				cout << "�绰�������벻�Ϸ�������������绰���룡" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
			teleNum = teleNum + temp;
		}
		if (flag == 0) {
			break;
		}
	}
	return teleNum;
}

string emailRegister() {//��������⻹����дд
	string email = "";
	while (1) {
		email = "";
		cout << "����������,������Ϻ���Enter������" << endl;
		char temp;
		int flag = 0;
		while (1) {
			temp = cin.get();
			if (temp == '\n') {
				//�˴�Ӧ�в��غ���
				break;
			}
			if (temp == ' ') {//���ո�
				cout << "�������벻�Ϸ����������������䣡" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');//������뻺����
				flag++;
				break;
			}
			email = email + temp;
		}
		if (flag == 0) {
			break;
		}
	}
	return email;
}

int passwordRegister() {
	int password = 0;
	int k = rand() % 5 + 1;        //�������һ��1-6λ����ֵ 
	int s;
	s = rand() % 2;                     //���ʹsΪ1��0��Ϊ1��������Ϊ0���Ǹ� 
	for (int i = 1; i <= k; i++)
	{
		srand(time(NULL));
		int x;                        //x��ʾ����ַ���ascii�� ��s��ʾ����ַ��Ĵ�Сд  
		x = rand() % 10;
		for (int l = 0; l < i; l++) {
			x = x * 10;
		}
		password += x;
	}
	if (s == 0) {
		password = -password;
	}
	cout << "���룺" << password << endl;
	return password;
}