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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    vector<int> dif;
    sort(v.begin(), v.end());
    for(int i=1;i<m;i++) dif.push_back(v[i] - v[i-1]);
    sort(dif.begin(), dif.end());
    while(n > 1 && dif.size()){
        dif.pop_back();
        n--;
    }
    ll ans = 0;
    for(auto x : dif) ans += x;
    cout << ans << "\n";
}
