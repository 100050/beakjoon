#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 4000001

bool not_prime[MAX];
int sum_prime[MAX/10];

int main(){
    int N;
    scanf("%d", &N);
    int sq = sqrt(N);
    for (int i = 2; i <= sq; i++)
        for (int j = 2*i; j <= N; j += i)
            not_prime[j] = 1;
	
    sum_prime[0] = 0;
    int size = 1;
    for (int i = 2, sum = 0; i <= N; i++)
        if (!not_prime[i])
            sum_prime[size++] = (sum += i);

	
    int left = 0, right = 1, cnt = 0;
    while (left <= right && right < size){
        int temp = sum_prime[right] - sum_prime[left];
        if (temp > N) left++;
        else {
            if (temp == N) cnt++;
            right++;
        }
    }
    printf("%d", cnt);
}