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
    ll m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    map<int, vector<int>> mp;
    for(int i=1;i<=n;i++){
        mp[a[i]].push_back(i);
        mp[b[i]].push_back(i);
    }
    cin >> m;
    ll ans = 1;
    for(auto &[k, v] : mp){
        sort(v.begin(), v.end());
        int c2 = 0;
        for(int j=1;j<v.size();j++){
            if(v[j] == v[j-1]) c2++;
        }
        ll cur = 1;
        for(int j=1;j<=v.size();j++){
            ll cf = j;
            while(cf % 2 == 0 && c2 > 0){
                cf /= 2;
                c2--;
            }
            cur = (cur * cf) % m;
        }
        ans = (ans * cur) % m;
    }
    cout << ans << "\n";
    
}
