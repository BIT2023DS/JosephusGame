#include <iostream>
#include <string>
#include "user.h"
#include "link.h"


	//插入新链用户 
    void LinkedList::insert(user user1) {
        Node* newNode = new Node;
        newNode->data = user1;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
	//移除id为某个字符串的用户 
    void LinkedList::remove(string id) {
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL) {
            if (current->data.getId() == id) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
            }
            previous = current;
            current = current->next;
        }
    }
	//找到id为某个字符串的用户在链表中的地址，找不到返回NULL 
    user* LinkedList::find(string id) {
        Node* current = head;

        while (current != NULL) {
            if (current->data.getId() == id) {
                return &current->data;
            }
            current = current->next;
        }

        return NULL;
    }

    void LinkedList::print(){
    	Node* current = head;
    	while(current != NULL){
    		cout<<current->data.getId()<<endl;
    		cout<<current->data.getName()<<endl;
    		cout<<current->data.getTeleNum()<<endl;
    		cout<<current->data.getEmail()<<endl;
    		cout<<current->data.getPassword()<<endl;
    		current = current ->next;
		}
	}
