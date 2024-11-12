#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> vn[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vn[x].push_back(i);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r, x;
        cin >> l >> r >> x;
        cout << lower_bound(vn[x].begin(), vn[x].end(), r+1) - lower_bound(vn[x].begin(), vn[x].end(), l) << "\n";
    }
}
