#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int tr[1000002];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        tr[l]++;
        tr[r+1]--;
    }
    for(int i=2;i<=n;i++){
        tr[i] += tr[i-1];
    }
    cout << *min_element(tr+1,tr+n+1) << "\n";
}
