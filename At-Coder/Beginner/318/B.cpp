#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool cv[101][101];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int i = a; i< b; i++){
            for(int j = c; j < d; j++){
                cv[i][j] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(cv[i][j]) ans++;
        }
    }
    cout << ans << "\n";
}
