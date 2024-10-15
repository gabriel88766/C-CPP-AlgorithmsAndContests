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
        int n, m, x;
        cin >> n >> x >> m;
        int l = x, r = x;
        for(int i=0;i<m;i++){
            int ll, rr;
            cin >> ll >> rr;
            if(max(ll, l) <= min(rr, r)){
                l = min(ll, l);
                r = max(rr, r);
            }
        }
        cout << r-l+1 << "\n";
    }
}
