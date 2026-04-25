#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[200001]; //문자열을 담을 배열
	scanf("%s", arr); //문자열 입력
	int len = strlen(arr); //입력받은 문자열의 길이
	int a[27][len]; //알파벳은 26개다.  2차원 배열 선언
	
	for(int i = 0; i<len; i++) //문자열에 무슨 알파벳이 있는지, 한칸 한칸 이동하면서 구하기
	{	
		for(int j = 0; j<27; j++) a[j][i] = 0; // 이차원 배열 a의 모든값을 0으로 초기화
		int tmp = arr[i]-97; //a ASCII : 97(d) //특정 문자가 있으면
		a[tmp][i]++; //a[특정문자][그 때의 문자열의 길이]을 1 증가 시킨다.
	}
	
	for(int i = 1; i<len; i++) //이차원 배열 a의 알파벳에 따른 부분합들 구하기
	{
		for(int j = 0; j<26; j++) //a~z
		{
			a[j][i] += a[j][i-1]; 
		}
	}
	
	
	int q = 0;
	scanf("%d", &q); //몇 번?
	
	while(q>0)
	{
		char ch = 0; //무슨 문자?
		int x, y; //범위
		scanf(" %c%d%d", &ch, &x, &y); //입력받음
		if(x == 0) printf("%d\n", a[ch-97][y]); //x가 0이면 y의 부분합만 출력하면 됨
		else printf("%d\n", a[ch-97][y]-a[ch-97][x-1]); //부분합끼리 빼면, 범위 내 합을 알 수 있음
		q--;
	}

	return 0; //main 함수 종료
}