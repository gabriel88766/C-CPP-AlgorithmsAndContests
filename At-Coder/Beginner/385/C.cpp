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
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++) cin >> h[i];
    int ans = 1;
    for(int i=1;i<=n-1;i++){
        //i is the interval
        vector<int> lst(i, -1);
        vector<int> cnt(i, 0);
        int cg = 0;
        for(int j=1;j<=n;j++){
            cg++;
            if(cg == i) cg = 0;
            if(h[j] == lst[cg]){
                cnt[cg]++;
                ans = max(ans, cnt[cg]);
            }else{
                cnt[cg] = 1;
                lst[cg] = h[j];
            }
        }
    }
    cout << ans << "\n";
}
