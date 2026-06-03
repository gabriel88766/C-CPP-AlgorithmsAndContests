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
        int x, y;
        cin >> x >> y;
        if(y >= x){
            if((x + y) % 2){
                cout << "YES\n";
                for(int i=1;i<=x;i++){ //from 2 to 2*x+1
                    cout << 1 << " " << 2*i << "\n";
                    cout << 2*i << " " << 2*i+1 << "\n";
                }
                for(int i=2*x+2;i<=x+y;i++){
                    cout << 1 << " " << i << "\n";
                }
            }else{
                if(x == 0) cout << "NO\n";
                else{
                    cout << "YES\n";
                    --x;
                    for(int i=1;i<=x;i++){ //from 2 to 2*x+1
                        cout << 1 << " " << 2*i << "\n";
                        cout << 2*i << " " << 2*i+1 << "\n";
                    }
                    for(int i=2*x+2;i<=x+y+1;i++){
                        cout << 1 << " " << i << "\n";
                    }
                }
            }
        }else cout << "NO\n";
    }
}
