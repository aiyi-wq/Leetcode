/*************************************************************************
	> File Name: LeetCode-127.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Oct 2020 08:52:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct node {
    string word;
    int step;
};

int main() {
    unordered_map<string, int> m;
    queue<node> que;
    for (int i = 0; i < wordlist.size(); i++) {
        m[wordlist[i]] = 1;
    }
    if (m[endword] == 0) {
        return 0;
    }
    //起点也算一步
    que.push((node){beginword, 1});
    m[beginword] = 2;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i <temp.word.size(); i++) {
            string t = temp.word;
            for (int j = 0; j < 26; ++j) {
                t[i] = 'a' + j;
                if (t == endword) {
                    return temp.step + 1;
                }
                if (m[t] == 1) {
                    m[t] = 2;
                    que.push((node){t, temp.step + 1});
                }
            }
        }
    }
    return 0;
}
