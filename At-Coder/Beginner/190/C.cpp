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
    int ans = 0;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cd;
    for(int i=1;i<=m;i++){  
        int a, b;
        cin >> a >> b;
        cd.push_back({a, b});
    }
    int k;
    cin >> k;
    vector<pair<int, int>> ps;
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        ps.push_back({a, b});
    }
    for(int i=0;i<(1 << k);i++){
        int cur = 0;
        vector<bool> hb(n+1, false);
        for(int j=0;j<k;j++){
            if(i & (1 << j)) hb[ps[j].first] = true;
            else hb[ps[j].second] = true;
        }
        for(auto &[a, b] : cd){
            if(hb[a] && hb[b]) cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
