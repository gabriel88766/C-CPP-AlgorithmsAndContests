#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i=0;i<n;i++) cin >> d[i];
    sort(d.begin(), d.end());
    int fn = d[n-1];
    vector<int> dfn, dsn;
    int bp = 0;
    for(int i=1;i<=fn;i++){
        if(!(fn % i)){
            dfn.push_back(i);
        }
    }
    int sz1 = dfn.size();
    for(int i=0;i<d.size();i++){
        if(bp < sz1 && dfn[bp] == d[i]) bp++;
        else{
            dsn.push_back(d[i]);
        }
    }
    int sn = dsn[dsn.size()-1];
    cout << fn << " " << sn << "\n";
}
