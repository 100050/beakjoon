#include <stdio.h>
#include <math.h>

int main(){
    int testcase;
    double x1, x2, y1, y2;
    int planet_num;
    double xx, yy, r;
    int count1, count2, result;
    
    scanf("\n%d\n", &testcase);
    for(int i = 0; i < testcase; i++){
        result = 0;
        scanf("\n%lf %lf %lf %lf\n", &x1, &y1, &x2, &y2);
        scanf("\n%d\n", &planet_num);
        for(int j = 0; j < planet_num; j++){
            count1 = 0;
            count2 = 0;
            scanf("\n%lf %lf %lf\n", &xx, &yy, &r);
            if(pow(x1 - xx, 2) + pow(y1 - yy, 2) < pow(r, 2)) // 행성계 안쪽에 있다면
                count1 = 1;
            if(pow(x2 - xx, 2) + pow(y2 - yy, 2) < pow(r, 2)) // 행성계 안쪽에 있다면
                count2 = 1;
            result += pow((count1 - count2), 2); // 두 지점이 행성계의 안쪽과 바깥쪽에 각각 하나씩 있다면 카운트
        }
        printf("%d\n", result);
    }
    
    return 0;
}