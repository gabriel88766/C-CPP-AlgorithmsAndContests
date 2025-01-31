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
        vector<int> v(n);
        int p1, p2, pn;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x == 1) p1 = i;
            else if(x == 2) p2 = i;
            else if(x == n) pn = i;
        }
        int mx = max({p1, p2, pn});
        int mn = min({p1, p2, pn});
        if(pn > mn && pn < mx){
            //then done
            cout << "1 1\n";
        }else if(pn == mn){
            if(p1 == mx) cout << p2 << " " << pn << "\n";
            else cout << p1 << " " << pn << "\n";
        }else{
            if(p1 == mn) cout << p2 << " " << pn << "\n";
            else cout << p1 << " " << pn << "\n";
        }
    }
}
