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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<ll>> v(n, vector<ll>(m));
        ll s1 = 0, s2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        vector<string> vs(n);
        for(int i=0;i<n;i++) cin >> vs[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vs[i][j] == '1') s1 += v[i][j];
                else s2 += v[i][j];
            }
        }
        ll dif = abs(s1-s2);
        vector<ll> ms;
        vector<vector<int>> ps(n+1, vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j];
                if(vs[i][j] == '1') ps[i+1][j+1]++;
                else ps[i+1][j+1]--;
            }
        }
        for(int i=k;i<=n;i++){
            for(int j=k;j<=m;j++){
                int d = ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k];
                d = abs(d);
                if(d != 0) ms.push_back(d);
            }
        }
        sort(ms.begin(), ms.end());
        ms.resize(unique(ms.begin(), ms.end()) - ms.begin());
        ll g = 0;
        for(auto x : ms) g = gcd(g, x);
        if(dif){
            if(g == 0 || dif % g) cout << "No\n";
            else cout << "Yes\n";
        }else cout << "Yes\n";
    }
}
