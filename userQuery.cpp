#include "userQuery.h"

// The function userQuery is for search user from its own information
// input the userlist
bool userQuery(LinkedList &userlist)
{
    std::cout << "You can query users' information now!";
    std::cout << "Our game enable us to look for specific user by its own information like ID, email, name..." << endl;
    // string id;
    // string name;
    // string teleNum;
    // string email;
    // int password;
    // int score;
    while (1)
    {
        std::cout << "What do you know about the user that you want to inquire?" << endl;
        std::cout << "1: ID" << endl;
        std::cout << "2: name" << endl;
        std::cout << "3: teleNum" << endl;
        std::cout << "4: email" << endl;
        // std::cout <<"5: password(not recommend)" << endl;
        // std::cout <<"6: score" << endl;
        std::cout << "Input a number for your choice(0 to quit)" << endl;

        int Choice;
        std::cin >> Choice;

        if (Choice == 0)
        {
            std::cout << "Exit user query." << endl;
            return true;
        }
        else if (Choice < 1 || Choice > 4)
        {
            std::cout << "The number of your choice is invalid, please enter valid number in 1~4 or enter 0 to quit" << endl;
        }
        else
        {
            // Goal: to construct a sorted <pointer,similarities> array of user
            // similarity is in [0,100], if similarity of s1 and s2 is 100,which means s1=s2
            //  if max(similarity) == 100, only display the matched user information
            //  else show some users whose information is similar to the entered information

            //=========================================================
            // N is not neccesary but there are some problems here to calculate
            int N = sizeof(userlist.getHead()) / sizeof(user);
            //=========================================================

            std::vector<userCmpNode> userWithSim;
            if (Choice == 1)
            {
                std::cout << "Input ID:" << endl;
                string id;
                std::cin >> id;
                // for(*Node it=userlist;it->next!=NULL;it=it->next){
                // }
                userWithSim = userQuerySearch(id, userlist, Choice);
            }
            else if (Choice == 2)
            {
                std::cout << "Input name:" << endl;
                string name;
                std::cin >> name;
                userWithSim = userQuerySearch(name, userlist, Choice);
            }
            else if (Choice == 3)
            {
                std::cout << "Input telephone number::" << endl;
                string teleNum;
                std::cin >> teleNum;
                userWithSim = userQuerySearch(teleNum, userlist, Choice);
            }
            else //(Choice == 4)
            {
                std::cout << "Input email:" << endl;
                string email;
                std::cin >> email;
                userWithSim = userQuerySearch(email, userlist, Choice);
            }
            // sort userWithSim by similarities
            sort(userWithSim.begin(), userWithSim.end(), cmp);

            // display the only user matching to entered information or
            // display a list of users who has similiar information(not matched) with entered information
            display(userWithSim);
        }

        while (1)
        {
            cout << "Enter c to continue, or q to quit" << endl;
            char op;
            cin >> op;
            if (op == 'c')
                break;
            else if (op == 'q')
                return true;
            else
                cout << "Input Error, please input again." << endl;
        }
    }
    return true;
}
bool cmp(userCmpNode user1, userCmpNode user2)
{
    return (user1.second > user2.second);
}

// input s, and choice
// return an array of user pointers with similarites
std::vector<userCmpNode>
userQuerySearch(string s, LinkedList &userlist, int opt)
{
    std::vector<userCmpNode> results;

    rapidfuzz::fuzz::CachedRatio<string::value_type> scorer(s);

    const double score_cutoff = 50.0;

    if (opt < 1 || opt > 4)
    {
        cout << "std::vector<userCmpNode> userQuerySearch(string s, LinkedList &userlist, int opt) error" << endl;
        return results;
    }

    else if (opt == 1)
    {
        for (Node *choice = userlist.getHead(); choice->next != NULL; choice = choice->next)
        {
            double score = scorer.similarity(choice->data.getId(), score_cutoff);
            if (score >= score_cutoff)
            {
                results.emplace_back(userCmpNode(&(choice->data), score));
            }
        }
        return results;
    }
    else if (opt == 2)
    {
        for (Node *choice = userlist.getHead(); choice->next != NULL; choice = choice->next)
        {
            double score = scorer.similarity(choice->data.getName(), score_cutoff);
            if (score >= score_cutoff)
            {
                results.emplace_back(userCmpNode(&(choice->data), score));
            }
        }
        return results;
    }
    else if (opt == 3)
    {
        for (Node *choice = userlist.getHead(); choice->next != NULL; choice = choice->next)
        {
            double score = scorer.similarity(choice->data.getTeleNum(), score_cutoff);
            if (score >= score_cutoff)
            {
                results.emplace_back(userCmpNode(&(choice->data), score));
            }
        }
        return results;
    }
    else //(opt == 4)
    {
        for (Node *choice = userlist.getHead(); choice->next != NULL; choice = choice->next)
        {
            double score = scorer.similarity(choice->data.getEmail(), score_cutoff);
            if (score >= score_cutoff)
            {
                results.emplace_back(userCmpNode(&(choice->data), score));
            }
        }
        return results;
    }
}

// template <typename Sentence1,
//           typename Iterable, typename Sentence2 = typename Iterable::value_type>
// std::vector<std::pair<Sentence2, double>>
// extract(const Sentence1 &query, const Iterable &choices, const double score_cutoff = 0.0)
//{
//     std::vector<std::pair<Sentence2, double>> results;
//
//     rapidfuzz::fuzz::CachedRatio<typename Sentence1::value_type> scorer(query);
//
//     for (const auto &choice : choices)
//     {
//         double score = scorer.similarity(choice, score_cutoff);
//
//         if (score >= score_cutoff)
//         {
//             results.emplace_back(choice, score);
//         }
//     }
//
//     return results;
// }

void display(std::vector<userCmpNode> userWithSim)
{
    auto itr = userWithSim.begin();
    if (itr->second == 100) // find user in userlist
    {
        // show itr->data
        userQuery_userShow(itr->first);
    }
    else
    {
        cout << "Sorry, we can't find the player with your entered information" << endl;
        if (!userWithSim.empty())
        {
            cout << "Here are some players with similiar imformation in the playlist" << endl;
        }
        userQuery_userShow(itr->first);
        if (userWithSim.size() > 1)
        {
            itr++;
            userQuery_userShow(itr->first);
        }
    }
}

void userQuery_userShow(user *u)
{
    cout << "===============================" << endl;
    cout << "ID:" << u->getId() << endl;
    cout << "Name:" << u->getName() << endl;
    cout << "Telephone Number:" << u->getId() << endl;
    cout << "Email:" << u->getId() << endl;
    cout << "Password:" << u->getId() << endl;
    cout << "Score:" << u->getScore() << endl;
    cout << "===============================" << endl;
}