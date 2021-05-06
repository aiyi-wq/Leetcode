/*************************************************************************
	> File Name: LeetCode-934-最短的桥.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Oct 2020 08:11:30 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
    int x, y , step;
};
int n;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
queue<node> que;

void func(int x, int y, vector<vector<int>> &mmap) {
    que.push((node){x, y, 0});
    mmap[x][y] = 2;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx == n || yy == n || mmap[xx][yy] == 2) {
            continue;
        }
        if (mmap[xx][yy] == 1) {
            func(xx, yy, mmap);
        }
    }
}

int main() {
    n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 1) {
                func(i, j, A);
                break;
            }
        }
        if (que.size()) {
            break;
        }
    }
    //bfs找最小步数
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || y < 0 || x == n || y == n || A[x][y] == 2) {
                continue;
            }
            if (A[x][y] == 1) {
                return temp.step;
            }
            A[x][y] = 2;
            que.push((node){x, y, temp.step + 1});
        }
    }
    return -1;
}
