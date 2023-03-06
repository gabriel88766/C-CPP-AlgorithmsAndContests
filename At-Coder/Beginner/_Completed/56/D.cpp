#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[5001];
int v[5001];
int n, k;

bool check(int i){
    if(v[i] >= k){
        return false;
    }
    for(int j=1;j<k;j++) dp[j] = false;
    for(int j=1;j<=n;j++){
        if(i == j) continue;
        for(int w=k-1;w>=0;w--){
            if(dp[w] && v[j] + w < k) dp[w+v[j]] = true;
        }
    }
    bool ok = true;
    for(int j=(k-v[i]); j < k; j++){
        if(dp[j]) ok = false;
    }
    return ok;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v+1, v+n+1);
    dp[0] = true;
    int lo = 1, hi = n, mid;
    while(lo != hi){
        int mid = (lo+hi)/2;
        if(check(mid)) lo = mid+1;
        else hi = mid;
    }
    if(lo == n){
        if(check(n)) lo++;
    }   
    cout << lo-1;
}
