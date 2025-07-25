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
    ll tt = 0;
    cin >> n >> k;
    vector<pair<int, int>> rdc;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        tt += b;
        rdc.push_back({a+1, b});
    }
    sort(rdc.begin(), rdc.end());
    if(tt <= k) cout << "1\n";
    else{
        for(auto [a, b] : rdc){
            tt -= b;
            if(tt <= k){
                cout << a << "\n";
                break;
            }
        }
    }
}
