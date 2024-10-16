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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = 0;
    for(int b = 30; b>=0;b--){
        //check if possible
        int cur = ans | (1 << b);
        vector<ll> d;
        for(int i=0;i<n;i++){
            if((v[i] & cur) == cur) d.push_back(0);
            else{
                int x = v[i] | cur;
                bool flg = false;
                for(int j=30;j>=0;j--){
                    int cb = 1 << j;
                    if((x & cb) != (v[i] & cb)) flg = true;
                    if(flg && ((x & cb) != (cur & cb))) x ^= cb;
                }
                d.push_back(x - v[i]);
            }
        }
        sort(d.begin(), d.end());
        ll sum = 0;
        for(int i=0;i<k;i++) sum += d[i];
        if(sum <= m) ans = cur;
    }
    cout << ans << "\n";
}
