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
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({b, a});
    }
    sort(vp.begin(), vp.end());
    bool ok = true;
    int tt = 0;
    for(auto [b, a] : vp){
        tt += a;
        if(tt > b){
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
