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
    deque<pair<ll, ll>> cl;
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int tq, x, c;
        cin >> tq;
        if(tq == 1){
            cin >> x >> c;
            cl.push_back({c, x}); //qnt, val
        }else{
            cin >> c;
            int tt = 0;
            ll ans = 0;
            while(tt < c){
                if(c - tt >= cl.front().first){
                    ans += cl.front().first * cl.front().second;
                    tt += cl.front().first;
                    cl.pop_front();
                }else{
                    ans += (c - tt) * cl.front().second;
                    cl.front().first -= (c - tt);
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
}
