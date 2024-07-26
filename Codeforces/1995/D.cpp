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
        ll n, k, c;
        string s;
        cin >> n >> c >> k;
        cin >> s;
        s = " " + s;
        vector<int> cnt(c, 0);
        vector<bool> forb(1 << c, false);
        for(int i=1;i<=n;i++){
            cnt[s[i] - 'A']++;
            if(i >= k){
                int msk = 0;
                for(int j=0;j<c;j++){
                    if(!cnt[j]){
                        msk |= (1 << j);
                    }
                }
                forb[msk] = true;
                cnt[s[i-k+1] - 'A']--;
            }
        }
        int x = s[n] - 'A';
        forb[((1 << c) - 1) ^ (1 << x)] = true;
        int ans = INF_INT;
        for(int i=(1<<c)-1;i>=0;i--){
            if(!forb[i]) ans = min(ans, __builtin_popcount(i));
            else{
                for(int k=0;k<c;k++){
                    if(i & (1 << k)){
                        forb[i ^ (1 << k)] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
