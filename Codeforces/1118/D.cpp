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
    //init;
    vector<ll> dd(200005, 0);
    for(int i=2;i<=200000;i++){
        dd[i] = dd[i-1] + i-1;
    }
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    ll sum = 0;
    for(int i=0;i<n;i++) sum += v[i];
    if(sum < m) cout << "-1\n";
    else{
        //solve;
        int lo = 1, hi = n;
        while(lo != hi){
            int mid = lo + (hi-lo)/2;
            ll cs = 0, bs = 0;
            for(int i=0;i<mid;i++) cs += v[i];
            bs = cs;
            for(int i=mid;i<n;i++){
                cs += v[i];
                int d1 = (i+1)/mid;
                int d2 = d1 + 1;
                ll td2 = (i+1) % mid;
                ll td1 = mid - td2;
                ll ds = cs - dd[d1]*td1 - dd[d2]*td2;
                bs = max(ds, bs);
            }
            if(bs >= m) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
