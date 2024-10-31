#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> pr = {0};
ll dp[76][76];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    for(int i=2;i<=100;i++){
        bool np = false;
        for(int j=2;j<i;j++){
            if(!(i % j)) np = true;
        }
        if(!np) pr.push_back(i);
    }
    cin >> n;
    dp[0][1] = 1;
    for(int i=1;i<pr.size();i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            int aux = j;
            while(!(aux % pr[i])){
                cnt++;
                aux /= pr[i];
            }
        }
        for(int d = 1;d<=cnt+1;d++){
            for(int k=1;k<=75;k++){
                if(!(k % d)){
                    dp[i][k] += dp[i-1][k/d];
                }
            }
        }
    }
    cout << dp[pr.size()-1][75] << "\n";
}
