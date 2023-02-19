#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 20;
pair<ll,ll> dp[1 << N];

pair<ll,ll> cmp(pair<ll,ll> u, pair<ll,ll> v){
    if(u.first < v.first) return u;
    else if(u.first > v.first) return v;
    else if(u.second > v.second) return u;
    else return v;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    dp[0] = {1LL, x};
    for(int i=1;i< (1 << n);i++) dp[i] = {INF_LL, 0};
    for(int i=1; i < (1 << n); i++){
        for(int j=0;j<n;j++){
            if(i & 1 << j){
                int state = i ^ (1 << j);
                if(dp[state].second >= v[j]){
                    pair<ll,ll> nst = {dp[state].first, dp[state].second - v[j]};
                    dp[i] = cmp(dp[i], nst);
                }else{
                    pair<ll,ll> nst = {dp[state].first+1, max(dp[state].second, x-v[j])};
                    dp[i] = cmp(dp[i], nst);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}
