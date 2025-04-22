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
        vector<int> ans;
        int n, x;
        cin >> n >> x;
        int cor = 0, cn = 0;
        for(int i=1;i<n;i++){
            if((cn | x) == x){
                ans.push_back(cn);
                cor |= cn;
                cn++;
            }else{
                ans.push_back(x);
            }
        }
        if((cn | x) == x){
            if((cn | cor) == x){
                ans.push_back(cn);
            }else{
                ans.push_back(x);
            }
        }else ans.push_back(x);
        for(auto &x : ans) cout << x << " ";
        cout << "\n";
    }
}
