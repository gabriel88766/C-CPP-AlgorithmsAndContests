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
        vector<int> a(n+1), b(n+1);
        for(int i=2;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        // m == 1;
        a[1] = 1;
        sort(a.begin()+1, a.end());
        sort(b.begin()+1, b.end());
        ll ans1 = 0;
        int p1 = 1, p2 = 1;
        while(p2 <= n){
            while(p2 <= n && a[p1] >= b[p2]){
                ans1++;
                p2++;
            }
            p1++; p2++;
        }
        ll lo = 1, hi = m, mid;
        while(lo != hi){
            mid = lo + (hi - lo + 1)/2;
            auto v = a;
            v[1] = mid;
            sort(v.begin(), v.end());
            ll ans = 0;
            int p1 = 1, p2 = 1;
            while(p2 <= n){
                while(p2 <= n && v[p1] >= b[p2]){
                    ans++;
                    p2++;
                }
                p1++; p2++;
            }
            if(ans == ans1) lo = mid;
            else hi = mid - 1;
        }
        cout << m*ans1 + (m-lo) << "\n";
    }
}
