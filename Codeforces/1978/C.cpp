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
        ll n, k;
        cin >> n >> k;
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++) ans[i] = i;
        if(k % 2) cout << "No\n";
        else{
            for(int i=1;i<=n;i++){
                int ms = n - i + 1;
                if(ms < 0) break;
                int cur = 2 * (ms - i);
                if(cur <= k){
                    swap(ans[i], ans[ms]);
                    k -= cur;
                }else{
                    int tgt = i + k/2;
                    swap(ans[i], ans[tgt]);
                    k = 0;
                }
                if(!k) break;
            }
            if(k) cout << "No\n";
            else{
                cout << "Yes\n";
                for(int i=1;i<=n;i++) cout << ans[i] << " ";
                cout << "\n";
            }
        }
    }
}
