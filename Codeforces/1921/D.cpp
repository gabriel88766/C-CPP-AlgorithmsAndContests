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
        vector<ll> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        ll ans = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int p0 = 0, p1 = n-1, p2 = 0, p3 = m-1;
        while(p1 >= p0){
            if(abs(a[p0] - b[p3]) > abs(a[p1] - b[p2])){
                ans += abs(a[p0] - b[p3]);
                p0++;
                p3--;
            }else{
                ans += abs(a[p1] - b[p2]);
                p1--;
                p2++;
            }
        }
        cout << ans << "\n";
    }
}
