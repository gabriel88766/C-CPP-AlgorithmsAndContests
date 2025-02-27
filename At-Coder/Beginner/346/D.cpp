#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<ll> cost(n+1);
    for(int i=1;i<=n;i++) cin >> cost[i];
    //010101 00 101010101
    vector<ll> p0(n+1), p1(n+1), s0(n+1), s1(n+1);
    for(int i=1;i<=n;i++){
        p0[i] += p0[i-1];
        p1[i] += p1[i-1];
        int x = i % 2;
        if(s[i]-'0' == x){
            //ok for p1
            p0[i] += cost[i];
        }else{
            //ok for p0
            p1[i] += cost[i];
        }
    }
    reverse(s.begin() + 1, s.end());
    reverse(cost.begin() + 1, cost.end());
    for(int i=1;i<=n;i++){
        s0[i] += s0[i-1];
        s1[i] += s1[i-1];
        int x = i % 2;
        if(s[i]-'0' == x){
            //ok for p1
            s0[i] += cost[i];
        }else{
            //ok for p0
            s1[i] += cost[i];
        }
    }
    reverse(s0.begin() + 1, s0.end());
    reverse(s1.begin() + 1, s1.end());
    ll ans = INF_LL;
    for(int i=1;i<n;i++){
        //if odd 10  010  (1 and 0)
        //or even 1010 01  (1 and 1)
        if(n % 2){
            ans = min(ans, p0[i] + s1[i+1]);
            ans = min(ans, p1[i] + s0[i+1]);
        }else{
            ans = min(ans, p0[i] + s0[i+1]);
            ans = min(ans, p1[i] + s1[i+1]);
        }
    }
    cout << ans << "\n";
}
