/*************************************************************************
	> File Name: LeetCode-417.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Oct 2020 10:09:31 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class solution: {
public:
    struct node {
        int x, y;
    };
    int n, m;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int check[155][155] = {0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        n = matrix.size();
        if (n == 0) return ans;
        m = matrix[0].size();
        queue<node> que;
        for (int i = 0; i < m; ++i) {
            que.push((node){0, i});
            check[0][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            que.push((node){i, 0});
            check[i][0] = 1;
        }
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || y == m || x == n || check[x][y] == 1) continue;
                if (matrix[x][y] >= matrix[temp.x][temp.y]) {
                    check[x][y] = 1;
                    que.push((node){x, y});
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            que.push((node){n - 1, i});
            check[n - 1][i] |= 2;
        }
        for (int i = 0; i < n - 1; ++i) {
            que.push((node){i, m - 1});
            check[i][m - 1] |= 2;
        } 
        while(!que.empty()) {
            node temp = que.front();
            if (check[temp.x][temp.y] == 3) {
                ans.push_back(vector<int>{temp.x, temp.y});
            }
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m || (check[x][y] & 2)) continue;
                if (matrix[x][y] >= matrix[temp.x][temp.y]) {
                    check[x][y] |= 2;
                    que.push((node){x, y});
                }
            }
        }
        return ans;
    }
}
