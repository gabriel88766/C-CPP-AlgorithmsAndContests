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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        sort(b.begin(), b.end());
        int ln = -INF_INT;
        bool ok = true;
        for(int i=0;i<n;i++){
            //b - a[i] >= ln, b >= ln + a[i];
            auto it = lower_bound(b.begin(), b.end(), ln + a[i]);
            if(it != b.end()){
                int vx = *it - a[i];
                assert(vx >= ln);
                if(vx < a[i]) a[i] = vx;
                else if(a[i] < ln) a[i] = vx;
            }
            if(a[i] >= ln){
                ln = a[i];
            }else{
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
