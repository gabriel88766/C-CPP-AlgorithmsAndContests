#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double pr[60];
double fx[60][60];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in",  "r", stdin); //test input
    pr[1] = 0;
    fx[1][0] = 1;
    for(int i=2;i<=52;i++){
        //calc
        for(int u=0;u<=i-2;u++){
            if(u != 0) fx[i][u-1] += fx[i-1][u] * u;
            fx[i][u+1] += fx[i-1][u];
            fx[i][u] += fx[i-1][u] * (i - u - 1);
        }
        pr[i] = 1;
        for(int u=0;u<=i-1;u++){
            fx[i][u] /= i;
            if(u != 0){
                pr[i] += pr[i-u] * fx[i][u];
            }
        }
        pr[i] /= (1 - fx[i][0]);

        cout << i << " " << fixed << setprecision(8) << pr[i]-1 << "\n";
    }
}
