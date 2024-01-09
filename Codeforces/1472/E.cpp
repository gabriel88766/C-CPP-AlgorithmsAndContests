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
        vector<pair<int,int>> vp(n+1);
        vector<int> ans(n+1);
        vector<int> ord;
        for(int i=1;i<=n;i++){
            cin >> vp[i].first >> vp[i].second;
            if(vp[i].first > vp[i].second) swap(vp[i].first, vp[i].second);
            ord.push_back(i);
        }
        sort(ord.begin(), ord.end(), [&](int u, int v){
            return vp[u] < vp[v];
        });
        int p = 0;
        pair<int,int> lg = {INF_INT, 0};
        for(int i=0;i<n;i++){
            while(vp[ord[p]].first < vp[ord[i]].first){
                lg = min(lg, {vp[ord[p]].second, ord[p]});
                p++;
            }
            if(lg.first < vp[ord[i]].second) ans[ord[i]] = lg.second;
            else ans[ord[i]] = -1; 
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
