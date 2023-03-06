#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    set<ll> s;
    ll q, a, b;
    cin >> q >> a >> b;
    s.insert(a-b);
    s.insert(a+b);
    for(int i=0;i<q;i++){
        ll t;
        cin >> t >> a >> b;
        if(t == 1){
            s.insert(a-b);
            s.insert(a+b);
        }else{
            auto it1 = s.lower_bound(a);
            auto it2 = s.lower_bound(b);
            if(it1 != it2 || (it1 != s.end() && *it1 == a) || (it2 != s.end() && *it2 == b)) cout << "0\n";
            else{
                ll diff1 = INF_INT, diff2 = INF_INT;
                if(it1 != s.end())  diff1 = *it1 - b;
                if(it2 != s.begin()){
                    --it2;
                    diff2 = a-*it2;
                }
                cout << min(diff1, diff2) << "\n";
            }
        }
    }
}
