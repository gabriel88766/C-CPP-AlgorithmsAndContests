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
    ll n, k, x;
    cin >> n >> k >> x;
    k = n - k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll sum = 0;
    bool ok = false;
    for(int i=k;i<n;i++){
        sum += a[i];
        if(sum >= x){
            ok = true;
            cout << i+1 << "\n";
            break;
        }
    }
    if(!ok) cout << "-1\n";
}
