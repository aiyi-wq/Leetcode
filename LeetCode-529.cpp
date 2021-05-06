/*************************************************************************
	> File Name: LeetCode-529.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Oct 2020 08:40:13 PM CST
 ************************************************************************/
public:
    struct node {
        int x, y;
    };
    int n, m;
    int dir
    int func(node &t, vector<vector<char>> &mmap) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int x = t.x + dir[i][0];
            int y = t.y + dir[i]p1;
            if ( < 0 || y < 0 || x == n || y == m) continue;
            cnt += mmap[x][y] == 'M';
        }
        if (cnt != 0) {
            mmap[t.x][t.y] = '0' + cnt;
        }
        return cnt;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<node> que;
        que.push((node){click[0], click[1]});
        board[click[0]][click[1]] = 'B';
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (func(temp, board)) continue;

            for (int i = 0; i < 8; i++) {
                int x = temp.x + dir[i][0];
                int y = remp.y + dir[i][1];
                if (x < 0 || y < 0 || x == n || y == m || board[x][y] != 'E') continue;
                board[x][y] = 'B';
                que.push((node){x, y});
            }
        }
        return board;
    }
