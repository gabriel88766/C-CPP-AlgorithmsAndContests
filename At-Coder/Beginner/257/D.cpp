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
    vector<pair<ll,ll>> vp(n);
    vector<ll> pw(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second >> pw[i];
    }
    ll lo = 0, hi = 4e9;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        bool ok = false;
        for(int s=0;s<n;s++){
            vector<bool> vis(n, false);
            queue<int> q;
            q.push(s);
            vis[s] = true;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(int d=0;d<n;d++){
                    if(!vis[d]){
                        if(pw[u] * mid >= (abs(vp[d].first - vp[u].first) + abs(vp[d].second - vp[u].second))){
                            vis[d] = true;
                            q.push(d);
                        }
                    }
                }
            }
            bool cok = true;
            for(int j=0;j<n;j++) if(!vis[j]) cok = false;
            if(cok){
                ok = true;
                break;
            }
        }
        if(ok) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
