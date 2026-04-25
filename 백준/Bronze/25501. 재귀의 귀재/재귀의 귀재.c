#include <stdio.h>
#include <string.h>

int n;
int recursion(const char* s, int l, int r) {
    n++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}
int main() {
    int t, i, result;
    char s[1000];
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%s", s);
        n = 0;
        result = isPalindrome(s);
        printf("%d %d\n", result, n);
    }
}