#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    ll curug = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i == 0) curug += v[i];
        else curug += abs(v[i] - v[i-1]);
    }
    curug += v[n-1];
    if(n == 1){
        cout << curug/2 << "\n";
        return;
    }
    if(n >=2 && v[0] > v[1]) {
        curug -= v[0] - v[1];
        v[0] = v[1];
    }
    for(int i=1;i<(n-1);i++){
        if(v[i] > v[i-1] && v[i] > v[i+1]){
            curug -= v[i] - max(v[i-1], v[i+1]);
            v[i] = max(v[i-1], v[i+1]);
        }
    }
    if(n >= 2) curug -= max(v[n-1] - v[n-2], 0);
    cout << curug << "\n";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
