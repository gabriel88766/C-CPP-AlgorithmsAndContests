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
    multiset<pair<int,int>> sf, ss;
    int q;
    cin >> q;
    while(q--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == '-'){
            sf.erase(sf.lower_bound({a,b}));
            ss.erase(ss.lower_bound({b,a}));
        }else{
            sf.insert({a,b});
            ss.insert({b,a});
        }
        int p = ss.begin()->first;
        auto it = sf.lower_bound({p+1, 0});
        if(it != sf.end()) cout << "YES\n";
        else cout << "NO\n";
    }
}
