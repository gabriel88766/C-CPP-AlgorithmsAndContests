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
    vector<int> p(m);
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int aux;
            cin >> aux;
            v[i].push_back(aux);
        }
    }
    for(int i=0;i<m;i++) cin >> p[i];
    int ans = 0;
    for(int i=0;i< (1 << n); i++){//brute force.
        bool ok = true;
        for(int j=0;j<m;j++){
            int cur = 0;
            for(int k=0;k<v[j].size();k++){
                if(i & (1 << (v[j][k]-1))) cur ^= 1;
            }
            if(cur != p[j]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans;
}
