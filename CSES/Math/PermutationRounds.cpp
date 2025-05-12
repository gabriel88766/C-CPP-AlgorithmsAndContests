#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
    vector<int> v(n+1);
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<int> mul;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> vx = {i};
            int cur = i;
            while(v[cur] != i){
                cur = v[cur];
                vx.push_back(cur);
            }
            for(auto &x : vx) vis[x] = true;
            mul.push_back(vx.size());
        }
    }
    vector<int> mp(n+1, 0);
    for(auto &x : mul){
        auto y = x;
        for(int d=2;d<=y;d++){
            int c = 0;
            while(y % d == 0){
                c++;
                y /= d;
            }
            if(c){
                mp[d] = max(mp[d], c);
            }
        }
    }
    ll ans = 1;
    for(int a=1;a<=n;a++){
        int b = mp[a];
        int cm = 1;
        for(int j=0;j<b;j++) cm *= a;
        ans = (ans * cm) % MOD;
    }
    cout << ans << "\n";
}
