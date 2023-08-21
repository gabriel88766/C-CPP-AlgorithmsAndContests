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
    vector<ll> v(n);
    ll S = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        S += v[i];
    }
    ll mean = S / n;
    ll ans = 0;
    if(mean * n == S){
        for(int i=0;i<n;i++) ans += abs(mean-v[i]);
        ans /= 2;
    }else{
        sort(v.begin(), v.end());
        ll qt = S - mean * n;
        for(int i=0;i<n-qt;i++) ans += abs(mean-v[i]);
        for(int i=n-qt;i<n;i++) ans += abs(mean+1-v[i]);
        ans /= 2;
    }
    cout << ans;
}
