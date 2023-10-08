#include <stdio.h>
 
int main(){
    int v[] = {1, 5, 10, 20, 100};
    int n, i, cur;
    int ans = 0;
    scanf("%d",&n);
    for(i = 4; i >= 0; i--){
        cur = n / v[i];
        ans += cur;
        n -= cur * v[i];
    }
    printf("%d", ans);
    return 0;
}