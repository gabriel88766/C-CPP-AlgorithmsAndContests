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
    ll sumr = 0;
    deque<pair<ll, ll>> dq;
    for(int i=1;i<=q;i++){
        int qt;
        cin >> qt;
        if(qt == 1){
            ll l;
            cin >> l;
            ll sz = dq.size() ?  dq.back().first + dq.back().second : sumr;
            dq.push_back({sz, l});
        }else if(qt == 2){
            sumr += dq.front().second;
            dq.pop_front();
        }else{
            ll k;
            cin >> k;
            cout << dq[k-1].first - sumr << "\n";
        }
    }
}
