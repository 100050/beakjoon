#include <stdio.h>

#define CLM 1005
#define HLM 3015

char HT[HLM][CLM], s[CLM], subS[CLM];
int sLen, res;

int my_strlen(const char* a) {
	int len = 0;
	while (*a++) ++len;
	return len;
}

int my_strcmp(const char* a, const char* b) {
	while (*a && *b && *a == *b) *a++, *b++;
	return *a - *b;
}

void my_strncpy(const char* src, char* des, int len) {
	int n = 0;
	while (*src && n++ < len) *des++ = *src++;
	*des = 0;
}

int hash(const char* s) {
	unsigned long int hash = 5381;
	int c;
	while (c = *s++) hash = (((hash << 5) + hash) + c) % HLM;
	return hash % HLM;
}

void h_add(const char* s, int idx) {
	int h = hash(s);
	int cnt = HLM;
	while (HT[h][idx] && cnt--) {
		if (!my_strcmp(s, HT[h])) return;
		h = (h + 1) % HLM;
	}
	my_strncpy(s, HT[h], CLM);
	++res;
}

int main() {
	scanf("%s", s);
	sLen = my_strlen(s);
	for (int i = 1; i <= sLen; ++i) {
		for (int j = 0; j <= sLen - i; ++j) {
			my_strncpy(&s[j], subS, i);
			h_add(subS, i - 1);
		}
	}

	printf("%d\n", res);
	return 0;
}