#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<int> ps(n+1, 0);
        vector<int> c(n+1);
        for(int i=1;i<=n;i++) cin >> c[i];
        sort(c.begin()+1,c.end(),greater<int> ());
        for(int i=1;i<=n;i++) ps[i] = ps[i-1] + c[i];
        for(int i=0;i<q;i++){
            int x;
            cin >> x;
            auto it = lower_bound(ps.begin(), ps.end(), x);
            if(it == ps.end()) cout << "-1\n";
            else cout << it-ps.begin() << "\n";
        }
    }
}
