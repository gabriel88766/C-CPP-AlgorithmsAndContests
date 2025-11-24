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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int X = 0;
        for(int i=0;i<n;i++){
            X = X ^ a[i];
            X = X ^ b[i];
        }       
        if(X == 0) cout << "Tie\n";
        else{
            int msb = 1 << (31 - __builtin_clz(X));
            int x1 = 0;
            for(int i=0;i<n;i++) x1 ^= a[i];
            bool A = (x1 & msb ? true : false);
            for(int i=0;i<n;i++){
                int val = a[i] ^ b[i];
                if(val & msb){
                    if(i % 2 == 0) A = true;
                    else A = false;
                }
            }
            if(A) cout << "Ajisai\n";
            else cout << "Mai\n";
        }
    }
}
