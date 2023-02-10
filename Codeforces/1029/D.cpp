#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll pot[11];
ll rem[N][11];
map<pair<int,int>, vector<int>> xs;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n+1), len(n+1, 0);
    for(int i=1;i<=n;i++) cin >> v[i];
    pot[0] = 1;
    for(int i=1;i<=10;i++) pot[i] = 10 * pot[i-1];
    for(int i=1;i<=n;i++){
        ll aux = v[i];
        while(aux){
            len[i]++;
            aux /= 10;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++){
            rem[i][j] = ((pot[j]%k) * v[i]) % k;
        }
        xs[{len[i], rem[i][0]}].push_back(i);
    }  
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            int cr = k - rem[i][j];
            if(cr == k) cr = 0;
            if(xs.count({j, cr})){
                auto it = lower_bound(xs[{j, cr}].begin(), xs[{j, cr}].end(), i);
                ans += xs[{j, cr}].size();
                if(it != xs[{j, cr}].end() && *it == i) ans--;
            }
            
            
        }
    }
    cout << ans;
}
