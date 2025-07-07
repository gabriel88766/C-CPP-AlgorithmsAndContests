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
    deque<pair<ll, ll>> dq;
    for(int i=0;i<q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int c, x;
            cin >> c >> x;
            dq.push_back({c, x});
        }else{
            int k;
            cin >> k;
            ll ans = 0;
            while(k){
                if(dq.front().first <= k){
                    k -= dq.front().first;
                    ans += dq.front().first * dq.front().second;
                    dq.pop_front();
                }else{
                    ans += k * dq.front().second;
                    dq.front().first -= k;
                    k = 0;
                }
            }
            cout << ans << "\n";
        }
    }
}
