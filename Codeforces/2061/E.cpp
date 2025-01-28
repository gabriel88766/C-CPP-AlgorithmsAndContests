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
        int n, m, k;
        cin >> n >> m >> k;
        int msk = (1 << 30) - 1; //all set
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        vector<int> nums[11];
        vector<int> bs(1 << m);
        bs[0] = msk;
        for(int i=1;i<(1 << m);i++){
            int nb = __builtin_popcount(i);
            int mb =  31 - __builtin_clz(i);
            bs[i] = bs[i ^ (1 << mb)] & b[mb];
            nums[nb].push_back(bs[i]);
        }
        ll sum = 0;
        vector<int> ad;
        for(int i=0;i<n;i++){
            sum += a[i];
            int on = a[i];
            for(int j=1;j<=m;j++){
                int nn = INT_MAX;
                for(auto &x : nums[j]){
                    nn = min(nn, x & a[i]);
                }
                ad.push_back(on - nn);
                on = nn;
            }
        }
        sort(ad.begin(), ad.end(), greater<int>());
        for(int i=0;i<k;i++) sum -= ad[i];
        cout << sum << "\n";
        
    }
}
