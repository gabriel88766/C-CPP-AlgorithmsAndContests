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
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v(n*k);
    for(int i=0;i<n*k;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int mn = v[0];
    int mx = v[n-1];
    if(mx - mn > l) cout << "0\n";
    else{
        //is possible.
        ll ans = 0;
        int lm = n*k-1;
        for(int i=0;i<n*k;i++){
            if(v[i] - v[0] > l){
                lm = i-1;
                break;
            }
        }
        int p = 0;
        for(int i=0;i<n;i++){
            ans += v[p];
            int f = n - i - 1;
            p = min(lm - f + 1, p + k);
        }
        cout << ans << "\n";
    }
}
