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
    int n, w;
    cin >> n >> w;
    vector<vector<pair<int, int>>> bl(w+1);
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        bl[x].push_back({y, i});
    }
    int msz = INF_INT;
    for(int i=1;i<=w;i++){
        sort(bl[i].begin(), bl[i].end());
        msz = min(msz, (int)bl[i].size());
    }
    vector<int> dt(n+1, -1);
    for(int i=1;i<=msz;i++){
        int t = 0;
        for(int j=1;j<=w;j++) t = max(t, bl[j][i-1].first);
        for(int j=1;j<=w;j++) dt[bl[j][i-1].second] = t;
    }
    int q;
    cin >> q;
    while(q--){
        int t, a;
        cin >> t >> a;
        if(dt[a] == -1 || dt[a] > t) cout << "Yes\n";
        else cout << "No\n";
    }

}
