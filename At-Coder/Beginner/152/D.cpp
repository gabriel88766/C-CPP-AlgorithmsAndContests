#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll tt[10][10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int ld = i % 10, fd;
        int aux = i;
        while(aux){
            if(aux < 10) fd = aux;
            aux /= 10;
        }
        tt[fd][ld]++;
    }
    ll ans = 0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans += tt[i][j] * tt[j][i];
        }
    }
    cout << ans << "\n";
}
