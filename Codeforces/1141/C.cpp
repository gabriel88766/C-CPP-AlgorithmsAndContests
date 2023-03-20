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
    int n;
    cin >> n;
    vector<ll> dif(n-1), ans(n);
    for(int i=0;i<(n-1);i++) cin >> dif[i];
    ans[0] = 1;
    ll minv = 1;
    for(int i=0;i<(n-1);i++){
        ans[i+1] = ans[i] + dif[i];
        minv = min(minv, ans[i+1]);
    }
    if(minv < 1){
        ll add = abs(1-minv);
        for(int i=0;i<n;i++) ans[i] += add;
    }
    bool ok = true;
    vector<bool> cnt(n+1, false);
    for(int i=0;i<n;i++){
        if(ans[i] > n || cnt[ans[i]]) ok = false;
        else cnt[ans[i]] = true;
    }
    if(!ok) cout << -1;
    else{
        for(int i=0;i<n;i++) cout << ans[i] << " ";
    }
}
