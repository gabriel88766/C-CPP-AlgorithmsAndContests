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
    cin >> n;
    string s;
    cin >> s;
    vector<int> ps;
    for(int i=0;i<s.size();i++) if(s[i] == 'A') ps.push_back(i);
    ll ans = INF_LL;
    for(int i=0;i<2;i++){
        ll cur = 0;
        for(int j=0;j<ps.size();j++){
            cur += abs(2*j + i  - ps[j]);
        }
        ans = min(cur, ans);
    }
    cout << ans << "\n";
}
