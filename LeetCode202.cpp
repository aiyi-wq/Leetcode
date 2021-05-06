/*************************************************************************
	> File Name: LeetCode202.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:39:22 PM CST
 ************************************************************************/
int get_next(int x) {
    int tmp = 0;
    while (x) {
        tmp += (x % 10) * (x % 10);
        x /= 10;
    }
    return tmp;
 }

bool isHappy(int n) {
    int p = n, q = n;
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) break;
    }
    return (q == 1);
}
