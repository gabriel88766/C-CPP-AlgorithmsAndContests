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
        int x, y, z;
        cin >> x >> y >> z;
        if(z > x) cout << "0\n";
        else{
            //1,2,..,z, z+1, z+2 ... 
            cout << (x*y)/z << "\n";
            for(int i=0;i+z<=x*y;i+=z){
                for(int j=0;j<z;j++){
                    cout << ((i+j) % x) + 1 << " "; 
                }
                cout << "\n";
            }
        }
    }
}
