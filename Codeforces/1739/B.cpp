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
        bool ok = true;
        int n;
        cin >> n;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(i == 0) ans[i] = x;
            else{
                if(x == 0) ans[i] = ans[i-1];
                else if(ans[i-1]-x >= 0){
                    ok = false;
                }else ans[i] = ans[i-1]+x;
            }
        }
        if(ok){
            for(int i=0;i<n;i++) cout << ans[i] << " ";
            cout << "\n";
        }else cout << "-1\n";
    }
}
