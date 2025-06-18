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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v[i] %= (a+b);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    ll mx = 0;
    if(v.size() == 1) cout << "Yes\n";
    else{
        for(int i=1;i<v.size();i++){
            mx = max(mx, v[i] - v[i-1] - 1);
        }
        mx = max(mx, a + b + v[0] - v.back() - 1);
        if(mx >= b) cout << "Yes\n";
        else cout << "No\n";
    }
}   
