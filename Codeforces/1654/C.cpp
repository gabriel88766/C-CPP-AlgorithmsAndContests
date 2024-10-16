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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<ll> q1, q2;
        ll S = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            q1.push(x);
            S += x;
        }
        q2.push(S);
        bool ok = true;
        while(q1.size()){
            assert(q2.size());
            auto u = q2.top();
            q2.pop();
            auto v = q1.top();
            if(u > v){
                ll x = (u / 2 ) + u % 2;
                ll y = u / 2;
                q2.push(x);
                q2.push(y);
            }else if(u == v){
                q1.pop();
            }else{
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
