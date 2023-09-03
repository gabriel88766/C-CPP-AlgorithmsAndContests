#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll l[12], r[12], sz[12], sum[12];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    ll aux1 = 1, aux2 = 10;
    for(ll i=0;i<9;i++){
        l[i] = i+1;
        if(i != 0) l[i] += r[i-1];
        aux2--;
        sz[i] = aux2 - aux1 + 1;
        r[i] = l[i] + (i+1) * (sz[i] - 1);
        sum[i] = ((r[i]+l[i])*sz[i])/2;
        if(i) sum[i] += sum[i-1];
        aux2++;
        aux1*=10;
        aux2*=10;
    }
    while(q--){
        ll k;
        cin >> k;
        //first bin search + complete search, find order
        ll ind;
        for(int i=0;i<9;i++){
            if(k <= sum[i]){
                ind = i;
                break;
            }
        }
        ll cur = pow(10, ind) - 1;;
        if(ind != 0){
            k -= sum[ind-1];
        }
        // now i'm 9999..9 ind nines
        ll lo = 0, hi = sz[ind];
        while(lo != hi){ // TTT FF
            ll mid = lo + (hi-lo+1)/2;
            ll S;
            if(mid == 0) S = 0;
            else S = ((2*l[ind] + (mid-1) * (ind+1))*mid)/2;
            if(S < k) lo = mid;
            else hi = mid - 1;
        }
        if(lo != 0){
            cur += lo;
            k -= ((2*l[ind] + (lo-1) * (ind+1))*lo)/2;
        }
        //modify cur and ind
        for(int i=0;i<9;i++){
            if(k <= r[i]){
                ind = i;
                break;
            }
        }
        
        cur = pow(10, ind) - 1;
        if(ind) k -= r[ind-1];
        lo = 0, hi = sz[ind];
        while(lo != hi){ //TTTFF
            ll mid = lo + (hi-lo+1)/2;
            if(mid*(ind+1) < k) lo = mid;
            else hi = mid - 1;
        }
        cur += lo;
        cur++;
        k -= (lo*(ind+1));
        string s = to_string(cur);
        cout << s[k-1] << "\n";
    }
}
