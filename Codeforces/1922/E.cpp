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
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        int bt = 63 - __builtin_clzll(x);
        vector<int> ans = {1};
        int p = 2;
        if(x & (1LL << (bt-1))) ans.push_back(1);
        for(int i=bt-1;i>=1;i--){
            ans.push_back(p++);
            if(x & (1LL << (i-1))) ans.push_back(1);
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
