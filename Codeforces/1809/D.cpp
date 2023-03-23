#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll c1 = 1e12, c2 = 1e12+1; 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> v;
        int c0 = 0;
        v.push_back(0);
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') c0++;
            else if(c0) v.push_back(c0);
        }
        ll n = v.size();

        ll ans = min((n-1)*c2, v.back()*c2);

        for(ll i=1; i < n; i++){
            if(v[i] - v[i-1]  == 1) ans = min(v[i-1]*c2+c1+(n-i-1)*c2, ans);
            ans = min(ans, v[i-1]*c2 + (n-i)*c2);
        }
        cout << ans << "\n";
    }
}
