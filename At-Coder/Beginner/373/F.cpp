#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[3005];
vector<ll> val[3005];
vector<ll> bst[3005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, w;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        int w, v;
        cin >> w >> v;
        val[w].push_back(v);
    }
    for(int i=1;i<=w;i++){
        multiset<ll> ms;
        for(auto x : val[i]){
            ms.insert(x-1);
        }
        if(!ms.empty()){
            bst[i].push_back(0);
            for(int j=1;j*i<=w;j++){
                auto val = *prev(ms.end());
                ms.erase(prev(ms.end()));
                bst[i].push_back(bst[i].back() + val);
                ms.insert(val - 2);
            }
        }
    }
    for(int i=1;i<=w;i++){
        for(int j=w;j>=i;j--){
            for(int k=1;k*i<=j && k < bst[i].size();k++){
                dp[j] = max(dp[j], dp[j-k*i] + bst[i][k]);
            }
        }
    }
    cout << dp[w] << "\n";
}
