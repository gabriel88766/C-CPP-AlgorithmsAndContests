#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, sum, cursum, ans = 0;
    int bp = 0, ep = 0;
    cin >> n >> sum;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    cursum = 0;
    while(ep < n){
        cursum += v[ep++];
        while(cursum > sum){
            cursum -= v[bp++];
        }
        if(cursum == sum) ans++;
    }
    cout << ans;
}
