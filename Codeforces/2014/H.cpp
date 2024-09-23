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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        const int B = 4;
        map<int, int> bs[B];
        vector<vector<int>> xs(B, vector<int>(n+1));
        vector<int> v(n+1), xx;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            xx.push_back(v[i]);
        }
        sort(xx.begin(), xx.end());
        xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
        for(auto x : xx){
            for(int i=0;i<B;i++){
                bs[i][x] = uniform_int_distribution<int>(1, 1000000000)(rng);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<B;j++){
                xs[j][i] = xs[j][i-1] ^ bs[j][v[i]];
            }
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            bool ok = true;
            for(int j=0;j<B;j++){
                if(xs[j][r] != xs[j][l-1]) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
