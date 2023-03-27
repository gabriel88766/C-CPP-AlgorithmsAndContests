#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[205][205];
ll cur[205][205];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    int k = s.size();

    int cnt=0, l=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) l = max(l, abs(cnt));
    }


    if(l == 0) { dp[k][cnt] = 1;}

    for(int i=k+1;i<=2*n;i++){
        for(int j=0;j+k<=i;j++){
            memset(cur, 0, sizeof(cur));
            cur[0][0] = 1;
            for(int u=1;u<=j;u++){
                for(int v=0;v<=u;v++){
                    if(!v) cur[u][v] = cur[u-1][v+1];
                    else cur[u][v] = (cur[u-1][v-1] + cur[u-1][v+1]) % MOD;
                }
            }
            for(int v=0;v<=j;v++) cur[j][v] = (cur[j][v] + MOD  - dp[j][v]) % MOD;

            for(int u=j+1;u<=k+j;u++){
                if(s[u-j-1] == '('){
                    for(int v=1;v<=u;v++){
                        cur[u][v] = cur[u-1][v-1];
                    }
                }else{
                    for(int v=0;v<u;v++){
                        cur[u][v] = cur[u-1][v+1];
                    }
                }   
            }
            for(int u=k+j+1;u<=i;u++){
                for(int v=0;v<=u;v++){
                    if(!v) cur[u][v] = cur[u-1][v+1];
                    else cur[u][v] = (cur[u-1][v-1] + cur[u-1][v+1]) % MOD;
                }
            }
            for(int v=0;v<=i;v++) dp[i][v] = (dp[i][v] + cur[i][v]) % MOD;
        }
    }
    cout << dp[2*n][0];
    
}
