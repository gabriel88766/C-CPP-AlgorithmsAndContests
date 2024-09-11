#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+2;
int lo[N], hi[N], v[N];
int hgt[N], lwt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x;
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(!lo[v[i]]) lo[v[i]] = i;
        hi[v[i]] = i;
    }
    int mh, ml;
    for(int i=1;i<=x;i++){
        hgt[i] = hgt[i-1];
        if(lo[i]){
            if(lo[i] < hgt[i]){
                break;
            }
            hgt[i] = hi[i];
        }
        mh = i;
    }
    lwt[x+1] = n+1;
    for(int i=x;i>=1;i--){
        lwt[i] = lwt[i+1];
        if(lo[i]){
            if(hi[i] > lwt[i]){
                break;
            }
            lwt[i] = lo[i];
        }
        ml = i;
    }
    if(mh == x){
        ll ans = x;
        ans *= (x+1);
        ans /= 2;
        cout << ans << "\n";
    }else{
        ll ans = x - ml + 2;
        for(int i=1;i<=mh;i++){
            while(lwt[ml] < hgt[i]) ml++;
            ans += x - ml + 2;
        }
        cout << ans << "\n";
    }
}
