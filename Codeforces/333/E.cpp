#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
//double rad[3005][3005];
bitset<3005> bs[3005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++) cin >> p[i].first >> p[i].second;
    vector<pair<double, pair<int,int>>> vp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dx = abs(p[j].first - p[i].first);
            int dy = abs(p[j].second - p[i].second);
            int sq = dx*dx + dy*dy;
            //rad[j][i] = rad[i][j] = sqrt(sq)/2.0;
            vp.push_back({sqrt(sq)/2.0, {i, j}});
            bs[i][j] = bs[j][i] = 1;
        }
    }
    sort(vp.begin(), vp.end());
    double ans = 0;
    cout << fixed << setprecision(18);
    for(auto [d, x] : vp){
        auto [i, j] = x;
        if((bs[i] & bs[j]).count()) ans = d;
        bs[i][j] = bs[j][i] = 0;
    }
    cout << ans << "\n";
} 