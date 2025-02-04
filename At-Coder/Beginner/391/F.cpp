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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    ll lo = 1, hi = 3e18;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        bool ok = false;
        int pi = n-1;
        int tt = 0;
        for(int i=0;i<n;i++){
            //(Bj + Ai) * (Ck + Ai) - Ai^2
            int p1 = pi;
            while(p1 >= 0 && a[i]*b[0] + b[0]*c[p1] + c[p1]*a[i] < mid) p1--;
            pi = p1;
            if(pi < 0) break;
            for(int j=0;j<n;j++){
                while(p1 >= 0 && a[i]*b[j] + b[j]*c[p1] + c[p1]*a[i] < mid) p1--;
                if(p1 < 0) break;
                tt += p1 + 1;
                if(tt >= k) break;
            }
            if(tt >= k) break;
        }


        if(tt >= k) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
