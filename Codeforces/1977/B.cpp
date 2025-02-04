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
        vector<int> ans;
        while(n){
            if(n & 1) ans.push_back(1);
            else ans.push_back(0);
            n >>= 1;
        }
        ans.push_back(0);
        for(int i=0;i<ans.size();i++){
            if(ans[i] == 0){
                if(i == 0 || i == 1) continue;
                if(ans[i-1] == 0) continue;
                if(ans[i-2] == 0) continue;
                int f1;
                for(int j=i-2;j>=0;j--){
                    if(ans[j] == 1){
                        f1 = j;
                    }else break;
                }
                ans[f1] = -1;
                for(int j=f1+1;j<i;j++) ans[j] = 0;
                ans[i] = 1;
            }
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
