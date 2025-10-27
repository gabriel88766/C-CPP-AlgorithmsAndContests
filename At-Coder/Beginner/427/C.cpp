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
    int n, m;
    cin >> n >> m;
    int bst = 0;
    vector<pair<int, int>> edg;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edg.push_back({a, b});
    }
    for(int msk=0;msk<(1 << n);msk++){
        int cur = 0;
        for(auto [a, b] : edg){
            int x = 0;
            if(msk & (1 << a)) x ^= 1;
            if(msk & (1 << b)) x ^= 1;
            if(x == 1) cur++;
        }
        bst = max(bst, cur);
    }
    cout << m-bst << "\n";
}
