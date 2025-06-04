#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<tuple<int, int, int>> genall(int val){
    vector<tuple<int, int, int>> ans;
    for(int i=1;i<=val-2;i++){
        for(int j=1;i+j<=val-1;j++){
            ans.push_back({i, j, val-i-j});
        }
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    auto v1 = genall(h1);
    auto v2 = genall(h2);
    auto v3 = genall(h3);
    assert(v1.size() <= 500 && v2.size() <= 500 && v3.size() <= 500);
    int ans = 0;
    for(auto &[a, b, c] : v1){
        for(auto &[d, e, f] : v2){
            for(auto &[g, h, i] : v3){
                if(a + d + g == w1 && b + e + h == w2 && c + f + i == w3) ans++;
            }
        }
    }
    cout << ans << "\n";
}
