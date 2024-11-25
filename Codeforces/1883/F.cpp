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
        int n;
        cin >> n;
        vector<int> v(n), rv, lv;
        for(int i=0;i<n;i++) cin >> v[i];
        set<int> s;
        for(int i=0;i<n;i++){
            if(!s.count(v[i])) lv.push_back(i);
            s.insert(v[i]);
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            if(!s.count(v[i])) rv.push_back(i);
            s.insert(v[i]);
        }
        sort(rv.begin(), rv.end());
        ll ans = 0;
        for(int i=0;i<lv.size();i++){
            ll cur = rv.end() - lower_bound(rv.begin(), rv.end(), lv[i]);
            ans += cur;
        }
        cout << ans << "\n";
    }
}
