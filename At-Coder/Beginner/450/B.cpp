#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int c[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin >> c[i][j];
        }
    }
    bool ok = false;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){
                if(c[i][k] + c[k][j] < c[i][j]) ok = true;
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
