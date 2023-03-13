#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct StrangeQueue{ //O(nlogn)
    ll inc = 0;
    multiset<ll> diff; //insert current diff to inc
    void insert(ll val){
        diff.insert(val-inc);
    }
    ll pop_minv(){
        ll val = *diff.begin()+inc;
        diff.erase(diff.begin());
        return val;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int Q;
    cin >> Q;
    StrangeQueue sq;
    for(int i=0;i<Q;i++){
        int a, b;
        cin >> a;
        if(a == 3) cout << sq.pop_minv() << "\n";
        else{
            cin >> b;
            if(a == 1) sq.insert(b);
            else sq.inc += b;
        }
    }
}
