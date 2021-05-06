/*************************************************************************
	> File Name: LeetCode20.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Jun 2020 07:39:17 PM CST
 ************************************************************************/
bool isValid(char *s) {
    int len = strlen(s), top = -1, flag = 1;
    char *stack = (char *)malloc(sizeof(char) *len);
    while (s[0]) {
        switch (s[0]) {
            case '(':
            case '[':
            case '{':
                stack[++top] = s[0];
                break;
            case ')': flag = (top != -1 && stack[top--] == '('); break;
            case ']': flag = (top != -1 && stack[top--] == '['); break;
            case '}': flag = (top != -1 && stack[top--] == '{'); break;
        }
    if (!flag) break;
    ++s;
    }
    free(stack);
    return (flag && top == -1);
 }
