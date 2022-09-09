#include<iostream>
#include<map>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string firstWord, secondWord;

    //cout<<"Ievadiet pirmo vārdu:"<<endl;
    cin >> firstWord;
    //cout<<"Ievadiet otro vārdu:"<<endl;
    cin >> secondWord;

    map<char, int>f1;
    map<char, int>f2;

    cout << endl;
    int lettercount = 1;

    for (char ch : firstWord) {

        for (int j = 1; j < firstWord.length(); j++) {
            if (ch == firstWord[j] && j != firstWord.find(ch)) {
                lettercount++;
            }

        }
        f1.insert(make_pair(ch, lettercount));
        lettercount = 1;
    }

    for (char ch : secondWord) {

        for (int j = 1; j < secondWord.length(); j++) {
            if (ch == secondWord[j] && j != secondWord.find(ch)) {
                lettercount++;
            }

        }
        f2.insert(make_pair(ch, lettercount));
        lettercount = 1;
    }



    for (auto item : f1) {
        cout << item.first << "-> " << item.second << endl;
    }

    cout << endl;

    for (auto item : f2) {
        cout << item.first << "-> " << item.second << endl;
    }

    if (f1 == f2) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }



}