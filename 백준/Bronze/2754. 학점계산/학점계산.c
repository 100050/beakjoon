#include <string.h>

int main() {
	char str[3] = "";
	double t;
	scanf("%s", str);
	t = 0;
	switch (str[0]) {
	case 'A': t += 4;
		break;
	case 'B': t += 3;
		break;
	case 'C': t += 2;
		break;
	case 'D': t += 1;
		break;
	case 'F': t += 0;
	}
	switch (str[1]) {
	case '+': t += 0.3;
		break;
	case '0': t += 0;
		break;
	case '-': t += -0.3;
	}
	printf("%.1lf", t);
}