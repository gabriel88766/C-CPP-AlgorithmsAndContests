#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
ll v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    ll avg = 0;
    for(int i=1;i<=n;i++) avg += v[i];
    avg /= n;
    ll rsum = 0;
    for(int i=1;i<=n;i++) rsum += v[i];
    ll avg2;
    if(rsum == avg * n) avg2 = avg;
    else avg2 = avg + 1;
    ll sum1 = 0, sum2 = 0;
    for(int i=1;i<=n;i++) sum1 += max(0LL, avg - v[i]);
    for(int i=1;i<=n;i++) sum2 += max(0LL, v[i] - avg2);
    if(sum1 <= k && sum2 <= k){
        cout << avg2 - avg << "\n";
    }else{
        ll lo = 0, hi = 1e9;
        for(int jmp = 1e9;jmp >= 1; jmp >>= 1){
            while(true){
                ll nv = lo + jmp;
                ll sum = 0;
                for(int i=1;i<=n;i++){
                    sum += max(0LL, nv - v[i]);
                }
                if(sum <= k) lo = nv;
                else break;
            }
            while(true){
                ll nv = hi - jmp;
                ll sum = 0;
                for(int i=1;i<=n;i++){
                    sum += max(0LL, v[i] - nv);
                }
                if(sum <= k) hi = nv;
                else break;
            }
        }
        cout << hi - lo << "\n";
    }
}
