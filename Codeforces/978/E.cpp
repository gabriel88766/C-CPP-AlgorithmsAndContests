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
    //freopen("in", "r", stdin); test input
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int l = 0, r = w, cur = 0;
    for(int i=0;i<n;i++){
        cur += v[i];
        l = max(l, -cur);
        r = min(r, w-cur);
    }


    if(r >= l) cout << r - l + 1;
    else cout << 0;
}
