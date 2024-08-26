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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp;
    for(int i=2;i<=n;i++) vp.push_back({1, i});
    if(vp.size() > m) cout << "Impossible\n";
    else{
        if(vp.size() != m){
            for(int i=2;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(gcd(i, j) == 1) vp.push_back({i, j});
                    if(vp.size() == m) break;
                }
                if(vp.size() == m) break;
            }
        }
        if(vp.size() == m){
            cout << "Possible\n";
            for(auto [u, v] : vp) cout << u << " " << v << "\n";
        }else cout << "Impossible\n";
    }
}
