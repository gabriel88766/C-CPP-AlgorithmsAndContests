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
        int n, a, b, d;
        cin >> n >> a >> b;
        d = n - a - b;
        if(d < 0) cout << "NO\n";
        else if(min(a, b) == 0 && max(a, b) != 0) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i=1;i<=a;i++){
                cout << b + i << " ";
            }
            for(int i=1;i<=b;i++){
                cout << i << " ";
            }  
            for(int i=1;i<=d;i++){
                cout << a + b + i << " ";
            }
            cout << "\n";
            for(int i=1;i<=a;i++){
                cout << i << " ";
            }
            for(int i=1;i<=b;i++){
                cout << a + i << " ";
            }  
            for(int i=1;i<=d;i++){
                cout << a + b + i << " ";
            }
            cout << "\n";
        }
    }
}
