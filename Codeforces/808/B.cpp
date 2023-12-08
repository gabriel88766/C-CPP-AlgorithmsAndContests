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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll sum = 0;
    for(int i=0;i<k;i++) sum += v[i];
    ll ans = sum;
    ll cnt = 1;
    for(int i=k;i<n;i++){
        sum += v[i] - v[i-k];
        cnt++;
        ans += sum;
    }
    cout << fixed << setprecision(15) << ((double)ans)/cnt << "\n";
}
