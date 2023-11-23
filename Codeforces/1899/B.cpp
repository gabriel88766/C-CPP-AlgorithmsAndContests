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
        int n;
        cin >> n;
        vector<ll> v(n);
        ll ans = 0;
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=1;i<n;i++){
            if(!(n % i)){
                vector<ll> sums;
                for(int j=0; j< n; j += i){
                    ll curs = 0;
                    for(int k=j;k<j+i; k++){
                        assert(k < n);
                        curs += v[k];
                    }
                    sums.push_back(curs);
                }
                ans = max(ans, *max_element(sums.begin(), sums.end()) - *min_element(sums.begin(), sums.end()));
            }
        }
        cout << ans << "\n";
    }
}
