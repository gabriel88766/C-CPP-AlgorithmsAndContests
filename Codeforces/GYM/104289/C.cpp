#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull aux[20];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    aux[1] = 1;
    for(int i=2;i<=19;i++){
        aux[i] = aux[i-1]*10+1;
    }
    ull n;
    cin >> n;
    for(int i=1;i<=19;i++){
        for(int j=1;j<=9;j++){
            ll cur = aux[i]*j;
            if(cur >= n){
                cout << cur;
                return 0;
            }
        }
    }
}
