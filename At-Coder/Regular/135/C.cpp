#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cnt[30];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        for(int j=29;j>=0;j--){
            if(v[i] & (1 << j)){
                cnt[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<=n;i++){
        ll cur = 0;
        for(int j=29;j>=0;j--){
            if(v[i] & (1 << j)) cur += (n - cnt[j]) * (1LL << j);
            else cur += cnt[j] * (1LL << j);
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";

}
