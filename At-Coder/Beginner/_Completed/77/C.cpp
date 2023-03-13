#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
    vector<int> a(n), b(n), c(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<ll> ansb(n), ans(n);

    for(int i=0;i<n;i++){
        ansb[i] = (lower_bound(a.begin(), a.end(), b[i])-a.begin());
        if(i) ansb[i] += ansb[i-1];
    }
    for(int i=0;i<n;i++){
        int ind = lower_bound(b.begin(),b.end(), c[i]) - b.begin();
        if(ind > 0) ans[i] = ansb[ind-1];
        if(i) ans[i] += ans[i-1];
    }
    cout << ans[n-1];
}
