#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int N;
    int i, j;
    int* A;
    
    scanf("%d", &N);
    A = (int*)malloc(sizeof(int) * N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
 
    int* left; 
    left = (int*)malloc(sizeof(int) * N);
    int* right; 
    right = (int*)malloc(sizeof(int) * N);
 
    left[0]=1;
    right[N-1]=1;
    for(i=1; i<N; i++){
        left[i]=1;
        right[N-1-i]=1;
        for(j=0; j<i; j++){
            if(A[i]>A[j])
                left[i] = left[i] > left[j]+1 ? left[i] : left[j]+1;
            if(A[N-1-i]>A[N-1-j])
                right[N-1-i] = right[N-1-i] > right[N-1-j]+1 ? right[N-1-i] : right[N-1-j]+1;
        }
    }
 
    int* bitonic;
    bitonic = (int*)malloc(sizeof(int) * N);
    for(i=0; i<N; i++){
        bitonic[i] = left[i] + right[i]-1;
    }
 
    int max=0;
    for(i=0; i<N; i++){
        if(bitonic[i]>max)
            max = bitonic[i];
    }
    printf("%d\n", max);
    
    free(bitonic);
    free(left);
    free(right);
    free(A);
}
