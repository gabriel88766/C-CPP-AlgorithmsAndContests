#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[31];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<ll>> ps(n+1);
    for(int i=1;i<=n/2;i++){
        ps[i].push_back(a[i]);
        for(int j=1;j<i-1;j++){
            for(auto x : ps[j]) ps[i].push_back((x + a[i]) % m);
        }
    }
    for(int i=n;i>n/2;i--){
        ps[i].push_back(a[i]);
        for(int j=n;j>i+1;j--){
            for(auto x : ps[j]) ps[i].push_back((x + a[i]) % m);
        }
    }
    for(int i=1;i<=n;i++){
        sort(ps[i].begin(), ps[i].end());
    }
    ll ans = 1;
    for(int i=1;i<=n/2;i++){
        for(int j=n/2+1;j<=n;j++){
            if(i == n/2 && j == (n/2 + 1)) continue;
            int i1, i2;
            if(ps[i].size() < ps[j].size()) i1 = i, i2 = j;
            else i1 = j, i2 = i;
            for(auto x : ps[i1]){
                int y = (m - x) % m;
                ans += upper_bound(ps[i2].begin(), ps[i2].end(), y) - lower_bound(ps[i2].begin(), ps[i2].end(), y);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto x : ps[i]){
            if(x == 0) ans++;
        }
    }
    cout << ans << "\n";
}
