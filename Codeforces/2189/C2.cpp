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
        if(n % 2 == 1){
            cout << n-1 << " ";
            for(int i=2;i<n;i++){
                if(i % 2 == 0) cout << i+1 << " ";
                else cout << i-1 << " ";
            }
            cout << 1 << "\n";
        }else{
            vector<int> ans(n+1, 0);
            if(__builtin_popcount(n) == 1) cout << "-1\n";
            else{
                ans[n] = n;
                ans[1] = n-1;
                vector<bool> free(n+1, true);
                free[n] = false;
                free[n-1] = false;
                for(int i=n-1;i>=2;i--){
                    for(int j=n;j>i;j--){
                        if((i ^ans[j]) <= n &&  (i ^ ans[j]) > 0 && free[i ^ ans[j]]){
                            ans[i] = i ^ ans[j];
                            free[ans[i]] = false;
                            break;
                        }
                    }
                }
                for(int i=1;i<=n;i++) cout << ans[i] << " ";
                cout << "\n";
            }
        }
    }
}
