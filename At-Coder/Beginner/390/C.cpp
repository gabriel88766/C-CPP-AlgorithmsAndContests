#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
char gr[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int mni = n+1, mxi = -1;
    int mnj = m+1, mxj = -1;
    bool hx = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
            if(gr[i][j] == '?') hx = true;
            if(gr[i][j] == '#'){
                mni = min(mni, i);
                mxi = max(mxi, i);
                mnj = min(mnj, j);
                mxj = max(mxj, j);
            }
        }
    }
    if(mxi == -1){
        if(hx) cout << "Yes\n";
        else cout << "No\n";
    }else{
        bool ok = true;
        for(int i=mni;i<=mxi;i++){
            for(int j=mnj;j<=mxj;j++){
                if(gr[i][j] == '.') ok = false;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
