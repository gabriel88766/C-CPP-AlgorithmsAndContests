//test, fast code..
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<3005> bs[3005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(s[j] == '1') bs[i][j] = 1;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            ll x = (bs[i] & bs[j]).count();
            ans += (x * (x-1))/2;
        }
    }
    cout << ans;

}
