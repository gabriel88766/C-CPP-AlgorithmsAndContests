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
    string s;
    cin >> n >> s;
    vector<int> oc;
    int p = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '0') p++;
        else oc.push_back(p);
    }
    int hf = oc[oc.size()/2];
    // cout << hf << "\n";
    // cout << oc[0] << " " << oc.back() << "\n";
    ll ans = 0;
    for(auto &x : oc) ans += abs(x - hf);
    cout << ans << "\n";
}
