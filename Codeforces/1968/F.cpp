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
        int n, q;
        cin >> n >> q;
        vector<int> v(n+1), ps(n+1);
        map<int, vector<int>> mp;
        mp[0].push_back(0);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            ps[i] = ps[i-1] ^ v[i];
            mp[ps[i]].push_back(i);
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            bool ok = false;
            if(ps[l-1] == ps[r]) ok = true; //even
            else{ //odd
                auto it1 = prev(lower_bound(mp[ps[l-1]].begin(), mp[ps[l-1]].end(), r));
                auto it2 = lower_bound(mp[ps[r]].begin(), mp[ps[r]].end(), l);
                if(*it2 < *it1) ok = true;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
