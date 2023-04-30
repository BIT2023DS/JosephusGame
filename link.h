#ifndef LINK
#define LINK
#include "user.h"
using namespace std;
class Node {
public:
    user data;
    Node* next;
};

class LinkedList {
public:
	//创建链表 
    LinkedList() {
        head = NULL;
    }
	//删除链表 
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void insert(user user1);
    void remove(string id);
    user* find(string id);
    void print();
private:
    Node* head;
};
#endif
