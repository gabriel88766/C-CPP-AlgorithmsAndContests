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
    ll lo = 1, hi = 1e18, mid;
    int k, n;
    cin >> n >> k;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll aux;
        cin >> aux;
        v.push_back(aux);
    }
    while(lo != hi){
        mid = (hi+lo)/2;
        ll cursum = 0;
        int cnt = 1;
        for(int i=0;i<n;i++){
            if(v[i] > mid){
                cnt = INF_INT;
                break;
            }
            if(mid >= (cursum+v[i])){
                cursum += v[i];
            }else{
                cursum = v[i];
                cnt++;
            } 
        }
        if(cnt > k) lo = mid + 1;
        else hi = mid;
    }
    cout << lo;
}
