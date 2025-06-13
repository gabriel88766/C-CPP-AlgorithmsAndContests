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
        ll k;
        cin >> n >> k;
        int ans = 0;
        vector<int> cnt(61);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            for(int j=0;j<=60;j++){
                if(x & (1LL << j)){
                    ans++;
                }else{
                    cnt[j]++;
                }
            }
        }
        for(int i=0;i<=60;i++){
            if(cnt[i] * (1LL << i) <= k){
                ans += cnt[i];
                k -= cnt[i] * (1LL << i);
            }else{
                ans += k / (1LL << i);
                break;
            }
        }
        cout << ans << "\n";
    }
}
