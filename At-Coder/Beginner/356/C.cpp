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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> v(m);
    vector<char> r(m);
    for(int i=0;i<m;i++){
        int l;
        cin >> l;
        v[i].resize(l);
        for(int j=0;j<l;j++){
            cin >> v[i][j];
            v[i][j]--;
        }
        cin >> r[i];
    }
    ll ans = 0;
    for(int i=0;i<(1 << n);i++){
        bool ok = true;
        for(int j=0;j<m;j++){
            int cnt = 0;
            for(int x=0;x<v[j].size();x++){
                if(i & (1 << v[j][x])) cnt++;
            }
            if(cnt >= k){
                if(r[j] != 'o') ok = false;
            }else{
                if(r[j] != 'x') ok = false;
            }
        }
        if(ok){
             ans++;
        }
    }
    cout << ans << "\n";
}
