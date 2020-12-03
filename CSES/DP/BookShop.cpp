#include <bits/stdc++.h>

using namespace std;

const int W  = 1e5+3;
const int N = 1e3+3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int dp[N][W];


int main() {
    int k,n,w,aux,posmax;
    vector <int> wv,pv;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> aux;
        wv.push_back(aux);
    }
    for(int i=0;i<n;i++){
        cin >> aux;
        pv.push_back(aux);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i&&j){
                if(wv[i-1]<=j){
                    posmax=dp[i-1][j-wv[i-1]]+ pv[i-1];
                }else{
                    posmax=0;
                }
                dp[i][j] = max(dp[i-1][j],posmax);
            }


        }
    }
    cout << dp[n][w];
}
