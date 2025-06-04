#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> addn(m+1);
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;  
        ll vs = x >= 0 ? 0 : (abs(x) + i - 1) / i;
        // vs(vs * i + x >= 0 && vs * i + x < i);
        if(vs <= m && vs*i+x <= n) addn[vs].push_back(make_pair(vs*i+x, i));
    }
    vector<pair<int, int>> acn;
    for(int i=0;i<=m;i++){
        vector<pair<int, int>> nacn;
        for(auto &[a, b] : acn){
            if(a + b <= n) nacn.push_back({a+b, b});
        }
        acn = nacn;
        for(auto &v : addn[i]){
            acn.push_back(make_pair(v.first, v.second));
        }
        if(i == 0) continue;
        for(auto &[a, b] : acn) cnt[a]++;
        for(int j=0;j<=n;j++){
            if(cnt[j] == 0){
                cout << j << "\n";
                break;
            }
        }
        for(auto &[a, b] : acn) cnt[a]--;

    }
}
