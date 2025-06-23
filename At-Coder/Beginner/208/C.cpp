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
    ll n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    ll val = k / n;
    ll r = k % n;
    auto aux = v;
    sort(aux.begin(), aux.end());
    int x = aux[r];
    for(int i=1;i<=n;i++){
        if(x >= v[i]) cout << val+1 << "\n";
        else cout << val << "\n";
    }
}
