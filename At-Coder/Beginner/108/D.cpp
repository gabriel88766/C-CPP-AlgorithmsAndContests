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
    int l;
    cin >> l;
    vector<tuple<int,int,int>> edg;
    int n = 31 - __builtin_clz(l);
    int cur = 1;
    cout << n+1 << " ";
    for(int i=n;i>=1;i--){
        edg.push_back({i, i+1, 0});
        edg.push_back({i, i+1, cur});
        if(l & (1 << (i-1))){
            edg.push_back({i, n+1, 2*cur});
            cur = 2*cur+1;
        }else{
            cur = 2*cur;
        }
    }
    assert(cur == l);
    cout << edg.size() << "\n";
    for(auto [a, b, c] : edg) cout << a << " " << b << " " << c << "\n";
}
