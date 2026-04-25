int main() {
    int n, idx;
    int a, b;
    int arr[1000000] = { 0, };
    
    scanf("%d", &n);
    
    idx = 0;
    while(n--) {
        scanf("%d", &a);
        switch(a) {
            case 1:
                scanf("%d", &b);
                arr[idx++] = b;
                break;
            case 2:
                if (idx == 0) {
                    printf("-1\n");
                }
                else {
                    printf("%d\n", arr[--idx]);
                }
                break;
            case 3:
                printf("%d\n", idx);
                break;
            case 4:
                if (idx == 0)
                    printf("1\n");
                else
                    printf("0\n");
                break;
            case 5:
                if (idx == 0)
                    printf("-1\n");
                else
                    printf("%d\n", arr[idx-1]);
                break;
        }
    }
    
    return 0;
}