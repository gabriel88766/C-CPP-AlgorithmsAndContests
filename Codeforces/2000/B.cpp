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
        int l, r;
        bool ok = true;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(i == 0) l = r = x;
            else{
                if(x == l-1) --l;
                else if(x == r+1) ++r;
                else{
                    ok = false;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
