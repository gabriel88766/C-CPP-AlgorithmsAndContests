#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char img1[51][51], img2[51][51];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin >> img1[i][j];
    
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) cin >> img2[i][j];
    
    for(int i=1;i<=(n-m+1);i++){
        for(int j=1;j<=(n-m+1);j++){
            bool ok = true;
            for(int u=1;u<=m;u++){
                for(int v=1;v<=m;v++){
                    if(img2[u][v] != img1[i+u-1][j+v-1]){
                        ok = false;
                    }
                }
            }
            if(ok){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No";
    
}
