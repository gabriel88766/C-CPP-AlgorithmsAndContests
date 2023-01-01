#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, cursum=0, ans=1;
    vector<ll> v;
    cin >> n;
    for(int i=0;i<n;i++){
        ll aux;
        cin >> aux;
        v.push_back(aux);
    }    
    sort(v.begin(), v.end());   
    for(int i=0;i<n;i++){
        if((cursum+1) < v[i]){
            break;
        }else{
            cursum += v[i];
        }
        ans = cursum+1;
    }    
    cout << ans;
}
