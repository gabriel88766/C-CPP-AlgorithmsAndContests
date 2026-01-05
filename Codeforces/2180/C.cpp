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
        int n, k;
        cin >> n >> k;
        if(k % 2){
            for(int i=1;i<=k;i++) cout << n << " ";
            cout << "\n";
        }else{
            vector<int> ans(k, n);
            int bc = min(__builtin_popcount(n), k);
            vector<int> bs;
            for(int j=30;j>=0;j--){
                if(n & (1 << j)) bs.push_back(j);
            }
            for(int i=0;i<bc;i++) ans[i] ^= (1 << bs[i]);
            for(int i=bc;i<bs.size();i++) ans[0] ^= (1 << bs[i]);

            for(int j=1;j<bc;j+=2){
                for(int u=bs[j]-1;u>=0;u--){
                    if(!(n & (1 << u))){
                        ans[j] |= (1 << u);
                        ans[j-1] |= (1 << u);
                    }
                }
            }
            for(int j=0;j<k;j++) cout << ans[j] << " ";
            cout << "\n";
        }
    }
}
