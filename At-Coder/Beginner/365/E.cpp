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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    for(int i=0;i<27;i++){
        ll ce = 1, co = 0, cur = 0;
        ll qt = 0;
        ll po = 1 << i;
        for(int j=0;j<n;j++){
            if(v[j] & po){
                cur++;
                qt--; //i == j
            }
            if(cur % 2){
                qt += ce;
                co++;
            }else{
                qt += co;
                ce++;
            }
        }
        ans += qt * po;
    }
    cout << ans << "\n";
}
