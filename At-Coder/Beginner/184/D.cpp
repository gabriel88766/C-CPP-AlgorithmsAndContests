#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double d[102][102][102];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a, b, c;
    cin >> a >> b >> c;
    int mx = 300 - a - b - c;
    double ans = 0;
    d[a][b][c] = 1;
    for(int i = a+b+c;i <= 300; i++){
        int op = i - a - b - c + 1;
        for(int j = a; j <= 99; j++){
            for(int k = b;k <= 99; k++){
                int l = i - j - k;
                if(l < c) continue;
                if(l > 99) continue;
                d[j+1][k][l] += (d[j][k][l] * j) / (j + k + l);
                d[j][k+1][l] += (d[j][k][l] * k) / (j + k + l);
                d[j][k][l+1] += (d[j][k][l] * l) / (j + k + l);
            }
        }
        for(int j = a; j <= 99; j++){
            int k = i+1 - 100 - j;
            if(k >= b && k <= 99) ans += op * d[j][k][100];
        }
        for(int j = a; j <= 99; j++){
            int l = i+1 - 100 - j;
            if(l >= c && l <= 99) ans += op * d[j][100][l];
        }
        for(int k = b; k <= 99; k++){
            int l = i+1 - 100 - k;
            if(l >= c && l <= 99) ans += op * d[100][k][l];
        }
    }
    cout << fixed << setprecision(18) << ans << "\n";
}
