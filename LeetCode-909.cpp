/*************************************************************************
	> File Name: LeetCode-909.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 07:13:08 PM CST
 ************************************************************************/
class Solution {
public:
    struct node {
        int now, step;
    };
    int n, num[415], cnt = 1, check[415] = {0};
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        for (int i = n - 1; i >= 0; --i) {
            if ((n - i) % 2 == 1) {
                for (int j = 0; j < n; ++j) {
                    num[cnt++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    num[cnt++] = board[i][j];
                }
            }
        }
        queue<node> que;
        que.push((node){1, 0});
        check[1] = 1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (temp.now == n * n) {
                return temp.step;
            }
            for (int i = 1; i <= 6; ++i) {
                int t = temp.now + i;
                if (num[t] != -1) {
                    t = num[t];//跳到终点
                }
                if (check[t] == 0 && t <= n * n) {
                    check[t] = 1;
                    que.push((node){t, temp.step + 1});
                }
            }
        }
        return -1;
    }
 }
