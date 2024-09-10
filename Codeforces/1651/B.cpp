#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll mi = 1e9;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll pp[60];
    pp[1] = 1;
    int mv;
    for(int i=2;;i++){
        pp[i] = pp[i-1] * 3;
        if(pp[i] <= mi){
            mv = i;
        }else break;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n > mv) cout << "NO\n";
        else{
            cout << "YES\n";
            ll c = 1;
            for(int i=0;i<n;i++){
                cout << c << " ";
                c *= 3;
            }
            cout << "\n";
        }
    }
}   
