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
    int q;
    cin >> q;
    deque<ll> dq;
    ll ofs = 0;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            dq.push_front(-ofs);
        }else if(t == 2){
            int x;
            cin >> x;
            ofs += x;
        }else{
            int x;
            cin >> x;
            int ans = 0;
            while(dq.size() && dq.back() + ofs >= x){
                dq.pop_back();
                ans++;
            }
            cout << ans << "\n";
        }
    }
}
