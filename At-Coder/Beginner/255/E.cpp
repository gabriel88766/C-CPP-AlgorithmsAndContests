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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n-1);
    for(int i=0;i<n-1;i++){
        cin >> v[i];
    }
    vector<ll> xv(m);
    for(int i=0;i<m;i++) cin >> xv[i];

    map<ll, ll> mp;
    for(int i=0;i<m;i++) mp[xv[i]]++;

    ll cs = 0;
    for(int i=0;i<n-1;i++){
        cs = v[i] - cs;
        for(auto &x : xv){
            if(i % 2 == 0){
                // cout << cs - x << " ";
                mp[cs - x]++;
            }else{
                mp[x - cs]++;
                // cout << x - cs << " ";
            }
        }
        // cout << "\n";
    }

    ll ans = 0;
    for(auto &[k, v] : mp) ans = max(ans, v);
    cout << ans << "\n";
}
