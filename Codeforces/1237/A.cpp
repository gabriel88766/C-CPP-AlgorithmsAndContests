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
    int m = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x % 2){
            if(m){
                if(x < 0) cout << x/2 << "\n";
                else cout << x/2 + 1 << "\n";
            }else{
                if(x < 0)  cout << x/2-1 << "\n";
                else cout << x/2 << "\n";
            }
            m^=1;
        }else cout << x/2 << "\n";
    }
}
