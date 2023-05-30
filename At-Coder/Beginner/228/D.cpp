#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1048576;
ll val[N];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    set<int> s;
    for(int i=0;i<N;i++){
        s.insert(i);
        val[i] = -1;
    }
    int q;
    cin >> q;
    while(q--){
        ll t,x;
        cin >> t >> x;
        if(t == 1){
            ll hmod = x % N;
            int pos;
            auto it = s.lower_bound(hmod);
            if(it == s.end()) pos = *s.begin();
            else pos = *it;
            s.erase(pos);
            val[pos] = x;
        }else{
            cout << val[x%N] << "\n";
        }
    }

}
