#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//O((V+E) logE) tested https://cses.fi/problemset/task/1671
const int N = 2e5+3;
int dp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    dp[0] = 0;
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + abs(v[i]-v[i-1]);
        if(i > 1) dp[i] = min(dp[i], dp[i-2] + abs(v[i]-v[i-2]));
    }
    cout << dp[n-1];
}
