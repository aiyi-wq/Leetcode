/*************************************************************************
	> File Name: LeetCode-752-转盘锁.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Oct 2020 08:36:29 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
    string status;
    int step;
};

int main() {
    unordered_map<string, int> m;
    for (int i = 0; i < deadends.size(); ++i) {
        m[deadends[i]] = 1;
    }
    if (m["0000"] == 1) {
        return -1;
    }
    m["0000"] = 1;
    queue<node> que;
    que.push((node){"0000", 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.status == target) {
            return temp.step;
        }
        for (int i = 0; i < 4; ++i) {
            string t = temp.status;
            t[i]++;
            if (t[i] >'9') {
                t[i] = '0';
            }
            if 
        }(m[t] == 0) {
            m[t] = 1;
            que.push((node){t, temp.step + 1});
            t = temp.status;
            t[i]--;
            if (t[i] < '0') {
                t[i] = '9';
            }
            if (m[t] == 0) {
                m[t] = 1;
                que.push((node){t, temp.step + 1});
            }
        }
    }
    return -1;
}
