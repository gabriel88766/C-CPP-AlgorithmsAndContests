#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ans solve(vector<pair<ll,ll>> &vp){
    
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<ll, ll>> vp1, vp2;
    for(int i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        if(x % 2 == y % 2){
            vp1.push_back({x, y});
        }else{
            vp2.push_back({x, y});
        }
    }
    cout << solve(vp1) + solve(vp2) << "\n";
}
