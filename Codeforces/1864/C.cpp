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
        int x;
        cin >> x;
        vector<int> ans;
        ans.push_back(x);
        while(__builtin_popcount(x) > 1){
            for(int i=0;i<30;i++){
                if(x & (1 << i)){
                    x -= (1 << i);
                    break;
                }
            }
            ans.push_back(x);
        }
        int k = 0;
        for(k=0;k<30;k++){
            if(x == (1 << k)) break;
        }
        for(int i=k-1;i>=0;i--){
            x -= (1 << i);
            ans.push_back(x);
        }
        cout << ans.size() << "\n";
        for(auto y : ans) cout << y << " ";
        cout << "\n";
    }
}
