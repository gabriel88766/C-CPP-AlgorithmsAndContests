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
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<ll> ans(2*n+1);
        ll cx = 0;
        int pr = 2*n-2, pl = 0;
        ans[0] = v[2*n-1];
        for(int i=2;i<ans.size();i++){
            if(i % 2 == 0){
                cx -= v[pr];
                ans[i] = v[pr];
                pr--;
            }else{
                cx += v[pl];
                ans[i] = v[pl];
                pl++;
            }
        }
        assert(cx < 0);
        // ans[1] + cx = ans[0]
        ans[1] = ans[0] - cx;
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
