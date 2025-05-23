#include <bits/stdc++.h>

const int N = 1e5+3;
int ord[N], v[N];
char ans[N];

int main(){
    int n, x, i;
    char p;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &x);
        v[i] = x;
        ord[x] = i;
    }
    p = 'a';
    for(i=1;i<=n;i++){
        if(p > 'z') break;
        if(i == 1){
            ans[v[i]] = p;
        }else{
            if(ord[v[i-1]+1] < ord[v[i]+1]){
                ans[v[i]] = p;
            }else{
                ans[v[i]] = ++p;
            }
        }
    }
    if(p > 'z') printf("-1\n");
    else{
        for(int i=1;i<=n;i++) printf("%c", ans[i]);
        printf("\n");
    }
}
