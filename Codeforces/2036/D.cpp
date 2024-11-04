#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[1005][1005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gr[i][j];
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ci = i, cj = j;
                string cur = "";
                for(int k=0;k<4;k++){
                    cur += gr[ci][cj];
                    //make the rotation
                    int layer = min(min(ci, n-ci+1), min(cj, m-cj+1));
                    if(ci == layer){
                        //layer 1
                        if(m-cj+1 == layer) ci++; //border layer 2
                        else cj++;
                    }else if(m-cj+1 == layer){
                        //layer 2
                        if(n-ci+1 == layer) cj--; //border layer 3
                        else ci++;
                    }else if(n-ci+1 == layer){
                        //layer 3
                        if(cj == layer) ci--; //border layer 4
                        else cj--;
                    }else{
                        //layer 4
                        ci--;
                    }
                }
                if(cur == "1543") ans++;
            }
        }
        cout << ans << "\n";
    }
}
