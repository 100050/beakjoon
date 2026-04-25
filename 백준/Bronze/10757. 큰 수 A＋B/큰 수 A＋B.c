#include <stdio.h>
#include <string.h>

int main() {
    int max, val, carry;
    int i, ml, nl;
    char mbuf[10001], nbuf[10001];
    int  m[10001] = { 0, };
    int  n[10001] = { 0, };
    int  s[10002] = { 0, };

    scanf("%s %s", mbuf, nbuf);

    ml = strlen(mbuf);
    nl = strlen(nbuf);

    for (i = 0; i < ml; i += 1) {
        m[ml - i - 1] = mbuf[i] - 48;
    }
    for (i = 0; i < nl; i += 1) {
        n[nl - i - 1] = nbuf[i] - 48;
    }

    max = ml;
    if (nl > ml) max = nl;

    carry = 0;
    for (i = 0; i < max; i += 1) {
        val = m[i] + n[i] + carry;
        carry = val / 10;
        s[i] = val % 10;
    }

    if (carry > 0) {
        s[max] = carry;
        max += 1;
    }

    for (i = 0; i < max; i += 1) {
        printf("%d", s[max - i - 1]);
    }

    return 0;
}
