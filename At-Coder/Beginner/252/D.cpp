#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int l[N], r[N], v[N], cnt[N];
vector<int> p[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        cnt[v[i]]++;
        l[i] = i - cnt[v[i]];
        p[v[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) cnt[v[i]]--;
    ll ans = 0;
    for(int i=n;i>=1;i--){
        cnt[v[i]]++;
        r[i] = n - i + 1 - cnt[v[i]];
        ll v1 = r[i], v2 = l[i];
        ans += v1*v2;
    }
    // cout << ans << "\n";
    //now subtract tuples a, x, a (x != a)
    for(int i=1;i<=200000;i++){
        ll cs = 0;
        for(int j=1;j<p[i].size();j++){
            ll cur = p[i][j] - p[i][j-1] - 1;
            ll f1 = j;
            ll f2 = p[i].size() - j;
            ans -= cur * f1 * f2; 
        }
    }
    cout << ans << "\n";

}
