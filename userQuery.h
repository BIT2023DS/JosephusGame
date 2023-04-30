// I need userlist.head, so i add a function getHead() in LinkedList.cpp
#ifndef USERQUERY
#define USERQUERY

#include<iostream>
#include<vector>
#include "link.h"
#include "user.h"
#include <rapidfuzz/fuzz.hpp>
using namespace std;

//userCmpNode = pair<a pointer to user , double similarities>
//for example <*Li,90.1>
typedef std::pair<user*,double> userCmpNode;

// 查询的主函数
//input the userlist
bool userQuery(LinkedList &userlist);

//define cmp function used for sort()
bool cmp(userCmpNode user1,userCmpNode user2);

// compare s with opt information(name, email ...) in userlist and return a vector of userCmpNode represents the similarities between s and userlist
std::vector<userCmpNode>
userQuerySearch(string s, LinkedList &userlist, int opt);

// Template of userCmpNode, you can ignore this function which doesn't run in UserQuery
template <typename Sentence1,
          typename Iterable, typename Sentence2 = typename Iterable::value_type>
std::vector<std::pair<Sentence2, double>>
extract(const Sentence1 &query, const Iterable &choices, const double score_cutoff = 50);

//Show matched User or nearly matched User
void display(vector<userCmpNode> userWithSim);

void userQuery_userShow(user*);

#endif