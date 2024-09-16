#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    int tst[2];
    int val = -1;
    for(int i=0;i<n;i++){
        if(v[i].first > val){
            val = v[i].first;
            tst[0] = i;
        }
    }
    val = INF_INT;
    for(int i=0;i<n;i++){
        if(v[i].second < val){
            val = v[i].second;
            tst[1] = i;
        }
    }
    int ans = 0;
    for(int i=0;i<2;i++){
        int l = 0, r = INF_INT;
        for(int j=0;j<n;j++){
            if(j == tst[i]) continue;
            l = max(l, v[j].first);
            r = min(r, v[j].second);
        }
        ans = max(ans, r-l);
    }
    cout << ans << "\n";
}
