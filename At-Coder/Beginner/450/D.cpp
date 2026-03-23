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
    int n, k;
    cin >> n >> k;
    vector<int> cg;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cg.push_back(x % k);
    }
    sort(cg.begin(), cg.end());
    cg.resize(unique(cg.begin(), cg.end()) - cg.begin());
    int mx = 0;
    for(int i=1;i<cg.size();i++) mx = max(mx, cg[i] - cg[i-1]);
    mx = max(mx, k + cg[0] - cg.back());
    cout << k-mx << "\n";
}
