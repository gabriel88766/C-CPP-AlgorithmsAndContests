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
        int l, r;
        cin >> l >> r;
        if(l != r && r >= 4){
            if(r % 2){
                cout << 2 << " " << r-3 << "\n";
            }else{
                cout << 2 << " " << r-2 << "\n";
            }
        }else if(r <= 3) cout << "-1\n";
        else{
            bool ok = false;
            for(int i=2;i*i<= l; i++){
                if(l % i == 0){
                    ok = true;
                    cout << l/i << " " << l - l/i << "\n";
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }
    }
}
