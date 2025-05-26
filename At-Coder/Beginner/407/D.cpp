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
    int h, w;
    cin >> h >> w;
    //if (i % w != w-1), then domino 3*b is allowed
    //if (i / w != h-1), then domino b * (1 + (1 << w)) is allowed;
    vector<vector<ll>> gr(h, vector<ll>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
        }
    }
    auto calc_state = [&](int msk){
        ll ans = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int b = 1 << (i*w + j);
                if(msk & b) ans ^= gr[i][j];
            }
        }
        return ans;
    };
    queue<int> q;
    q.push((1 << (h*w)) - 1);
    vector<bool> vis((1 << h*w), false);
    vis[(1 << (h*w)) - 1] = true;
    ll ans = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        ans = max(ans, calc_state(u));
        for(int xi=0;xi<h*w;xi++){
            if((xi % w) != w-1){
                ll cm = 3 * (1LL << xi);
                if((u & cm) == cm){
                    if(!vis[u ^ cm]){
                        vis[u ^ cm] = true;
                        q.push(u ^ cm);
                    }
                }
            }
            if((xi/w) != h-1){
                ll cm = (1LL << xi) * (1 + (1LL << w));
                if((u & cm) == cm){
                    if(!vis[u ^ cm]){
                        vis[u ^ cm] = true;
                        q.push(u ^ cm);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
