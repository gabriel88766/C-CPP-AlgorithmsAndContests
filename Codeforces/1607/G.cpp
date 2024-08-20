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
        int n, x;
        cin >> n >> x;
        vector<int> a(n+1), b(n+1), l(n+1), h(n+1);
        ll minv = 0, maxv = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i] >> b[i];
            int d11 = min(a[i], x);
            int d12 = x - d11;
            int d22 = min(b[i], x);
            int d21 = x - d22;
            l[i] = a[i] - b[i] - d11 + d12;
            h[i] = a[i] - b[i] - d21 + d22;
            minv += l[i];
            maxv += h[i];
        }
        if(maxv <= 0){
            cout << abs(maxv) << "\n";
            for(int i=1;i<=n;i++){
                int d22 = min(b[i], x);
                int d21 = x - d22;
                cout << d21 << " " << d22 << "\n";
            }
        }else if(minv >= 0){
            cout << abs(minv) << "\n";
            for(int i=1;i<=n;i++){
                int d11 = min(a[i], x);
                int d12 = x - d11;
                cout << d11 << " " << d12 << "\n";
            }
        }else{
            ll qt = abs(minv)/2;
            cout << abs(minv + 2*qt) << "\n";
            for(int i=1;i<=n;i++){
                int d11 = min(a[i], x);
                int d12 = x - d11;
                int diff = min((ll)(h[i]-l[i])/2, qt);
                qt -= diff;
                d11 -= diff;
                d12 += diff;
                cout << d11 << " " << d12 << "\n";
            }
        }
        cout << "\n";

    }
}
