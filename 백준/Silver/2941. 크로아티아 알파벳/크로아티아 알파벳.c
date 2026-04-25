#include <stdio.h>
#include <string.h>
int main() {
    int i, t;
    char str[100];
    t = 0;
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'c' && i < strlen(str) - 1) {
            if (str[i + 1] == '=') {
                t++;
                i++;
            }
            else if (str[i + 1] == '-') {
                t++;
                i++;
            }
            else {
                t++;
            }
        }
        else if (str[i] == 'd' && i < strlen(str) - 1) {
            if (str[i + 1] == '-') {
                t++;
                i++;
            }
            else if (str[i + 1] == 'z' && i < strlen(str) - 2) {
                if (str[i + 2] == '=') {
                    t++;
                    i += 2;
                }
                else {
                    t++;
                }
            }
            else {
                t++;
            }
        }
        else if (str[i] == 'l' && i < strlen(str) - 1) {
            if (str[i + 1] == 'j') {
                t++;
                i++;
            }
            else {
                t++;
            }
        }
        else if (str[i] == 'n' && i < strlen(str) - 1) {
            if (str[i + 1] == 'j') {
                t++;
                i++;
            }
            else {
                t++;
            }
        }
        else if (str[i] == 's' && i < strlen(str) - 1) {
            if (str[i + 1] == '=') {
                t++;
                i++;
            }
            else {
                t++;
            }
        }
        else if (str[i] == 'z' && i < strlen(str) - 1) {
            if (str[i + 1] == '=') {
                t++;
                i++;
            }
            else {
                t++;
            }
        }
        else {
            t++;
        }
    }
    printf("%d", t);
}
