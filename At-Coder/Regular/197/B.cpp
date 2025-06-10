#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll v[N], ps[N];
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
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        sort(v, v + n + 1);
        for(int i=1;i<=n;i++) ps[i] = ps[i-1] + v[i];
        int lo = 0, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            bool ok = false;
            for(int i=1;i<=n;i++){
                if(i + mid - 1 > n) break;
                if(ps[i+mid-1] < v[i] * (i + mid - 1)) ok = true;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
