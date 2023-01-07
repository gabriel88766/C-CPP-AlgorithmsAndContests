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
    ll n, ans = 0;

    cin >> n;
    vector<ll> v(n+1);
    vector<ll> ps(n+1, 0);

    for(int i=1;i<=n;i++) {
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }

    map<ll,int> mp; // map of # ps lesser than i
    mp[0] = 1;

    for(int i = 1; i <= n; i++){
        ll rem = ps[i] % n;
        if(rem < 0) rem += n;
        ans += mp[rem];
        mp[rem]++;
    }

    cout << ans;
}
