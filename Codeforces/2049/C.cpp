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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans(n+1);
        int p = 0;
        for(int i=x;i>=1;i--){
            ans[i] = p;
            p ^= 1;
        }
        for(int i=n;i>y;i--){
            ans[i] = p;
            p ^= 1;
        }
        p = 1;
        for(int i=x+1;i<y;i++){
            ans[i] = p;
            p ^= 1;
        }
        vector<int> has(2, false);
        has[0] = true;
        has[ans[y-1]] = true;
        if(y == n) has[ans[1]] = true;
        else has[ans[y+1]] = true;
        if(has[1]) ans[y] = 2;
        else ans[y] = 1;
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
