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
    vector<int> v(8);
    bool ok = true;
    for(int i=0;i<8;i++){
        cin >> v[i];
        if(v[i] % 25) ok = false;
        if(v[i] < 100 || v[i] > 675) ok = false;
    }
    auto u = v;
    sort(u.begin(), u.end());
    if(u != v) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
