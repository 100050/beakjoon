#include <stdio.h>
 
void fill_w();
void w_abc(int a, int b, int c);
 
//global paramaters
int w[21][21][21];
 
int main(void){
    fill_w();
    while(1){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
 
        if(a==-1 && b==-1 && c==-1)
            break;
 
        w_abc(a, b, c);
    }
}
 
void fill_w(){
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            for(int k=0; k<21; k++){
                if(i<=0 || j<=0 || k<=0)
                    w[i][j][k] = 1;
                else if(i<j && j<k)
                    w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                else
                    w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
            }
        }
    }
}
 
void w_abc(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0)
        printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
    else if(a<=20 && b<=20 && c<=20)
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
    else
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[20][20][20]);
}