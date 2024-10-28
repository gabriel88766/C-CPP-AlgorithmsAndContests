#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n+1), ans(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<int> vis(n+1, false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> cv;
            int cur = i;
            do{
                cv.push_back(cur);
                cur = p[cur];
            }while(cur != i);
            ll d = binpow(2, k, cv.size());
            for(int i=0;i<cv.size();i++){
                ans[cv[i]] = cv[(i + d) % cv.size()];
                vis[cv[i]] = true;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
