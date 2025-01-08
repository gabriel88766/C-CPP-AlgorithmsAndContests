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
        if(n % 2){
            if(n <= 25) cout << "-1\n";
            else{
                vector<int> ans(n+1, 0);
                ans[1] = ans[10] = ans[26] = 1;
                ans[27] = ans[23] = 2;
                int px = 3;
                int c = 0;
                for(int i=2;i<=n;i++){
                    if(ans[i] == 0){
                        if(c == 1){
                            ans[i] = px;
                            px++;
                            c = 0;
                        }else{
                            ans[i] = px;
                            c++;
                        }
                    }
                }
                for(int i=1;i<=n;i++) cout << ans[i] << " ";
                cout << "\n";
            }
        }else{
            for(int i=1;i<=n/2;i++) cout << i << " " << i << " ";
            cout << "\n";
        }
    }
}
