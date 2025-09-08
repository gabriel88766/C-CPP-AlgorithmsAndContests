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
    int n, a, b;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a;j++){
            for(int k=1;k<=n;k++){
                for(int l=0;l<b;l++){
                    if((i + k) % 2 == 0) cout << ".";
                    else cout << "#";
                }
            }
            cout << "\n";
        }
    }
}   
