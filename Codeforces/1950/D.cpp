#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> bd;
bool dp[100005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<(1 << 5);i++){
        int cn = 0;
        int p = 1;
        for(int k=0;k<5;k++){
            if(i & (1 << k)) cn += p;
            p *= 10;
        }
        bd.push_back(cn);
    }
    dp[1] = 1;
    for(int i=1;i<=100000;i++){
        if(dp[i]){
            for(auto x : bd){
                if(i <= 100000/x) dp[i*x] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}
