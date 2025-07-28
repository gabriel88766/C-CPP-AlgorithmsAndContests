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
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        if((m+1) * k <= n){
            int dv = n / (m + 1);
            int p = 0;
            for(int i=1;i<=n;i++){
                cout << p << " ";
                p++;
                if(p == (dv)) p = 0;
            }
            cout << "\n";
        }else{
            int p = 0;
            for(int i=1;i<=n;i++){
                cout << p << " ";
                p++;
                if(p == (k)) p = 0;
            }
            cout << "\n";
        }
    }
}
