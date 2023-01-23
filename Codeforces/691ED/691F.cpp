#include <bits/stdc++.h>
 
using namespace std;
 
long long int dp[3000001],qnt[3000001], sum=0,ans[3000001];
const int N = 3000001;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    long long int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        qnt[aux]++;
    }
    for(int i=1;i<1735;i++){
        if((i*i)<N) dp[i*i] += qnt[i]*(qnt[i]-1), sum += qnt[i]*(qnt[i]-1);
        for(int j=(i+1);j<N;j++){
            if((i*j)>=N) break;
            dp[i*j] += qnt[i]*qnt[j]*2;
            sum += qnt[i]*qnt[j]*2;
        }
    }
    dp[N-1] += (n)*(n-1) - sum;
    ans[N-1] = dp[N-1];
    for(int i=(N-2);i>0;i--){
        ans[i] = ans[i+1];
        ans[i] += dp[i];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        cout << ans[a] << "\n";
    }
 
}