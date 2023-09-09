#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int x[] = {0, 0, 0};
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int aux;
            cin >> aux;
            x[j] += aux;
        }
    }
    if(x[0] || x[1] || x[2]) cout << "NO\n";
    else cout << "YES\n";
}
