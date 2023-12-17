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
        vector<ll> b(n);
        ll sum = 0;
        for(int i=0;i<n;i++) {cin >> b[i]; sum += b[i];}
        ll tt = (n * (n+1))/2;
        if(sum % tt) cout << "NO\n";
        else{
            sum /= tt;
            vector<ll> a(n);
            bool ok = true;
            for(int i=0;i<n;i++){
                int p = (i+1) % n;
                ll dif = b[p] - b[i];
                a[p] = sum - dif;
                if(a[p] % n || a[p] <= 0) ok = false;
                else a[p] /= n;
            }
            if(ok){
                cout << "YES\n";
                for(auto x : a) cout << x << " ";
                cout << "\n";
            }else cout << "NO\n";
        }

    }
}
