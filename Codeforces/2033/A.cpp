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
        int cur = 0;
        int s = -1;
        for(int i=0;;i++){
            s += 2;
            if(i % 2) cur += s;
            else cur -= s;
            if(abs(cur) > n){
                if(i % 2) cout << "Kosuke\n";
                else cout << "Sakurako\n";
                break;
            }
        }
    }
}
