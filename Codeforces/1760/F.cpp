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
        ll n, c, d, sum = 0;
        cin >> n >> c >> d;
        vector<ll> v(n), ps(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<ll>());
        ps[0] = v[0];
        for(int i=1;i<n;i++) ps[i] = ps[i-1] + v[i];
        //check infinity, sum of max d elements.
        for(int i=0;i<min(d,n);i++){
            sum += v[i];
            if(sum >= c) break;
        }
        if(sum >= c){
            cout << "Infinity\n";
            continue;
        }
        //check impossible
        sum = v[0] * d;
        if(sum < c){
            cout << "Impossible\n";
            continue;
        }
        //bin search ??
        ll lo = 0, hi = 2e5+1, mid;
        while(lo != hi){
            sum = 0;
            mid = (lo+hi)/2;
            if(n > mid) sum += ps[mid];
            else sum += ps[n-1];
            sum *= (d / (mid+1));
            int aux = d % (mid+1);
            if(aux){
                if(n >= aux) sum += ps[aux-1];
                else sum += ps[n-1];
            }
            if(sum >= c) lo = mid+1;
            else hi = mid;
        }
        cout << lo-1 << "\n";
    }
}
