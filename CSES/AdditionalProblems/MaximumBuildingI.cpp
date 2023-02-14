#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char arr[1005][1005];
int v[1005][1005];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int k, m;
    cin >> k >> m;
    for(int i=1;i<=k;i++){ //O(N^2)
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=m;i++){ // O(N^2)
        for(int j=k;j>=1;j--){
            if(arr[j][i] == '.') v[j][i] = v[j+1][i]+1;
        }
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        stack<pair<int,int>> stp;
        for(int j=1;j<=m;j++){
            if(!stp.empty() && stp.top().first > v[i][j]){
                int fi;
                while(!stp.empty() && stp.top().first > v[i][j]){
                    ans = max(ans, stp.top().first * (j-stp.top().second));
                    fi = stp.top().second;
                    stp.pop();
                }
                stp.push({v[i][j], fi});
            }else stp.push({v[i][j], j});
        }
        while(!stp.empty()){
            ans = max(ans, stp.top().first * (m+1-stp.top().second));
            stp.pop();
        }
    }
    cout << ans;
}
