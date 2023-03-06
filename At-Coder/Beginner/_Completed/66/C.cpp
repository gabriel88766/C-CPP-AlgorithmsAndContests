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
    vector<int> v(n), ans(n);
    for(int i=0;i<n;i++) cin >> v[i];
    //solve
    for(int i=0;i<n/2;i++) ans[i] = v[n-2*i-1], ans[n-i-1] = v[n-2*i-2];
    if(n%2) ans[n/2] = v[0];

    for(int i=0;i<n;i++) cout << ans[i] << " "; 
}
