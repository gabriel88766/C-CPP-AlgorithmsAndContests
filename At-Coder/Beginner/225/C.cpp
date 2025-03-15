#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+3;
int gr[N][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    bool ok = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
            if(i >= 2 && gr[i][j] != gr[i-1][j] + 7) ok = false;
        }
    }
    for(int j=2;j<=m;j++){
        if(gr[1][j] != gr[1][j-1] + 1) ok = false;
        if(gr[1][j] % 7 == 1) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    
}
