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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ll aux;
            cin >> aux;
            ans += aux / k;
            v.push_back(aux % k);
        }
        int p1 = 0, p2 = n-1;
        sort(v.begin(), v.end());
        while(p1 < p2){
            if(v[p1] + v[p2] >= k){
                ans++;
                p1++;
                p2--;
            }else p1++;
        }
        cout << ans << "\n";
    }
}
