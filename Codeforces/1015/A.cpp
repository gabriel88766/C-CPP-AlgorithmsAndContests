#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool ok[105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        for(int j=l;j<=r;j++) ok[j] = true;
    }    
    vector<int> v;
    for(int i=1;i<=m;i++) if(!ok[i]) v.push_back(i);
    cout << v.size() << "\n";
    for(auto x : v) cout << x << " ";
    cout << "\n";
}
