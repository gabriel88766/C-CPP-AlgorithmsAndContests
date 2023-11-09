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
    vector<vector<int>> div(400005);
    for(int i=1;i<=400000;i++){
        for(int j=i;j<=400000;j+=i){
            div[j].push_back(i);
        }
    }
    while(t--){
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        for(int i = l; i <= r-2;i++){ //easy to improve
            ll el = r-i;
            ans += (el * (el-1))/2;
        }
        for(int i=l+2;i<=r;i++){
            // lcm = k
            int p = 0;
            while(div[i][p] < l) p++;
            ll d = div[i].size() - p;
            d--;
            ans -= (d*(d-1))/2;
            //lcm = 2*k and i+j > k
            int xx = 2*i;
            p = 0;
            while(div[xx][p] < l) p++;
            for(int j = p; j < div[xx].size();j++){
                for(int k = j+1; k < div[xx].size();k++){
                    if(div[xx][k] >= i) break;
                    if((i % div[xx][j]) || (i % (div[xx][k]))){
                        if(div[xx][j] + div[xx][k] > i) ans--;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
