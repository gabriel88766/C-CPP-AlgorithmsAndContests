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
    vector<int> pos = {1};
    int aux = 1;
    while(aux <= 100000){
        aux *= 6;
        pos.push_back(aux);
    }
    aux = 1;
    while(aux <= 100000){
        aux *= 9;
        pos.push_back(aux);
    }
    int n;
    cin >> n;
    vector<int> dp(n+1, INF_INT);
    dp[0] = 0;
    sort(pos.begin(), pos.end());
    for(int i=1;i<=n;i++){
        for(auto x : pos){
            if(x > i) break;
            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }
    cout << dp[n] << "\n";

}
