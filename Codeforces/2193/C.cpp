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
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1), b(n+1), ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        for(int i=n;i>=1;i--){
            if(i != n) a[i] = max(a[i], a[i+1]);
            a[i] = max(a[i], b[i]);
        }
        for(int i=1;i<=n;i++){
            ps[i] = a[i] + ps[i-1];
        }
        for(int i=1;i<=q;i++){
            int l, r;
            cin >> l >> r;
            cout << ps[r] - ps[l-1] << " ";
        }
        cout << "\n";
    }
}
