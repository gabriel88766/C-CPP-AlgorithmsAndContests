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
        int n, k;
        cin >> n >> k;
        if(n == 1) cout << k << "\n";
        else{
            int b = 32 - __builtin_clz(k);
            int x = (1 << b) - 1;
            if(x == k){
                cout << k << " ";
                for(int i=2;i<=n;i++) cout << "0 ";
                cout << "\n";
            }else{
                int y = (1 << (b-1)) - 1;
                cout << y << " " << k-y << " ";
                for(int i=3;i<=n;i++) cout << "0 ";
                cout << "\n";
            }
        }
    }
}
