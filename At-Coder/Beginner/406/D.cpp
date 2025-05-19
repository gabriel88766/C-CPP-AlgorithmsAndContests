#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
set<int> rs[N], cs[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, n;
    cin >> h >> w >> n;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        rs[x].insert(y);
        cs[y].insert(x);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t, p;
        cin >> t >> p;
        if(t == 1){
            cout << rs[p].size() << "\n";
            for(auto &y : rs[p]) cs[y].erase(p);
            rs[p].clear();
        }else{
            cout << cs[p].size() << "\n";
            for(auto &x : cs[p]) rs[x].erase(p);
            cs[p].clear();
        }
    }
}
