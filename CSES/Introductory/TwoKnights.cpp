#include <bits/stdc++.h>

using namespace std;

long long int ans[10005];

void solve(long long int n){
    ans[1]=0;
    ans[2]=6;
    ans[3]=28;
    ans[4]=96;
    for(int i=5;i<=n;i++){
        long long int total = i*i;
        ans[i] = total*(total-1);
        ans[i] -= (i-4)*4*4;
        ans[i] -= 4*2;
        ans[i] -= 8*3;
        ans[i] -= 4*4;
        ans[i] -= (i-4)*6*4;
        ans[i] -= (i-4)*(i-4)*8;
        ans[i]/=2;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << endl;
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
long long int n;
cin >> n;
solve(n);

}
