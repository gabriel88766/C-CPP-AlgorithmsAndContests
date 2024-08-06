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
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    bool ok = false;
    int p = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=1;i<n;i++){
        while(p < m && b[p] < a[i-1]) p++;
        //fact a[i-1] < b[p]; or a[i-1] > b[p] for all p
        if(p == m || b[p] > a[i]) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
