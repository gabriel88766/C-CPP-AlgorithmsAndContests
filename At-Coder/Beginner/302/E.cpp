#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
set<int> v[N];
set<int> ss;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int a, b;
            cin >> a >> b;
            v[a].insert(b);
            v[b].insert(a);
            ss.insert(a);
            ss.insert(b);
        }else{
            int a;
            cin >> a;
            for(auto x : v[a]){
                v[x].erase(a);
                if(v[x].size() == 0) ss.erase(x);
            }
            v[a].clear();
            ss.erase(a);
        }
        cout << n - ss.size() << "\n";
    }
}
