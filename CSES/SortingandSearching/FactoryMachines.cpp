#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    ll t, cursum, hi=1e18+1, lo=1, mid;
    cin >> n >> t;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    while(lo != hi){
        mid = (lo + hi)/2;
        cursum = 0;
        for(int i=0;i<n;i++){
            cursum += mid/v[i];
            if(cursum > 1e9) break; //avoiding overflow, cursum > 1e9 >= t => cursum > t
        } 
        if(cursum < t) lo = mid+1;
        else hi = mid;
    }
    cout << lo;

}
