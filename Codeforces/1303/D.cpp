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
        ll n, m;
        cin >> n >> m;
        vector<ll> cnt(64, 0);
        ll sum = 0;
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            sum += x;
            int c = 0;
            while(x != 1){
                c++;
                x /= 2;
            }
            cnt[c]++;
        }
        if(sum < n) cout << "-1\n";
        else{
            //solve.
            ll ans = 0;
            ll cn = n;
            for(int j=62;j>=0;j--){
                if(cn & (1LL << j)){
                    //merge to j
                    if(cnt[j]){
                        cnt[j]--; 
                    }else{
                        //merge the highest possible
                        ll sum = 0;
                        for(int k=j-1;k>=0;k--){
                            if(sum + (1 << k) * cnt[k] >= (1LL << j)){
                                cnt[k] -= ((1LL << j) - sum) / (1 << k);
                                break;
                            }else {
                                sum += (1 << k) * cnt[k];
                                cnt[k] = 0;
                            }
                        }
                    }
                    cn ^= (1LL << j);
                }
                ll sum = 0;
                for(int k=0;k<j;k++){
                    sum += (1LL << k) * cnt[k];
                }
                if(sum < cn){
                    //need to split
                    ll mx = cnt[j];
                    ll nd = (cn - sum + (1LL << j) - 1)/(1LL << j);
                    assert(nd <= mx);
                    ans += nd;
                    cnt[j-1] += 2 * nd;
                }
            }
            cout << ans << "\n";
        }
    }
}
