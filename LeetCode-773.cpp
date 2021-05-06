/*************************************************************************
	> File Name: LeetCode-773.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 07:27:30 PM CST
 ************************************************************************/
class Solution{
public:
    struct node {
        string status;
        int step, x;
    };
    int dir[6][5] = {
        {2, 1, 3},
        {3, 0, 2, 4},
        {2, 1, 5},
        {2, 0, 4},
        {3, 1, 3, 5},
        {2, 2, 4}
    };
    int slidingPuzzle(vector<int>& borad) {
        string start;
        int sx;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start += '0' + borad[i][j];
                if (borad[i][j] == 0) {
                    sx = i * 3 + j;
                }
            }
        }
        queue<node> que;
        que.push((node){start, 0, sx});
        unordered_map<string, int> m;
        m[start] = 1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (temp.status == '123450') {
                return temp.step;
            }
            for (int i = 1; i <= dir[temp.x][0]; ++i) {
                string t = temp.status;
                swap(t[temp.x], t[dir[temp.x][i]]);
                if (m[t] == 0) {
                    m[t] = 1;
                    que.push((node){t, temp.step + 1, dir[temp.x][i]});
                }
            }
        }
        return -1;
    }
}
