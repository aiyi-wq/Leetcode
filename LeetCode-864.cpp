/*************************************************************************
	> File Name: LeetCode-864.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 08:22:14 PM CST
 ************************************************************************/
class Solution {
    public:
    struct node {
        int x, y, step, status;
    };
    int n, m, sx, sy, end_key, end_status, check[35][35][70];
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int n2[10] = {1, 2, 4, 8, 16, 32, 64};
    int shortesPathAllKeys(vector<string>& grid) {
        n = gid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    end_key++;
                }
                if (grid[i][j] == '@') {
                    sx = i, sy = j;
                    grid[i][j] = '.';
                }
            }
        }
        end_status = n2[end_key] - 1;
        queue<node> que;
        que.push((node){sx, sy, 0, 0});
        check[sx][sy][0] = 1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (temp.status == end_status) {
                return temp.step;
            }
            for (int i = 0; i < 4; ++i) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 0 || y < 0 ||x == n || y == m || check[x][y][temp.status] == 1) {
                    continue;
                }
                if (grid[x][y] == '.') {
                    check[x][y][temp.status] = 1;
                    que.push((node){x, y, temp.step + 1, temp.status});
                } else if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                    check[x][y][temp.status] = 1;
                    check[x][y][temp.status | n2[grid[x][y] - 'a']] = 1;
                    que.push((node){x, y, temp.step + 1, temp.status | n2[grid[x][y]- 'a']});
                } else if (grid[x][y] >= 'A' && grid[x][y] <= 'F' && (temp.status & n2[grid[x][y] - 'A']) != 0) {
                    check[x][y][temp.status] = 1;
                    que.push((node){x,y, temp.step + 1, temp.status});
                }
            }
        }
        return -1;
    }
}
