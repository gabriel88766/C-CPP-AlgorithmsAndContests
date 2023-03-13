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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int ca = 0, cb = 0;
        bool t1 = false, t2 = false;
        for(int i=0;i<n;i++){
            if(a[i] == 1) ca++;
            if(b[i] == 1) cb++;
            if(a[i] == 1 && b[i] == 0) t1 = true;
            if(a[i] == 0 && b[i] == 1) t2 = true;
        }
        int ans = abs(ca-cb);
        if(ca > cb && t2) ans++;
        else if(ca < cb && t1) ans++;
        else if(ca == cb && (t1 || t2)) ans++;
        cout << ans << "\n";
    }
}
