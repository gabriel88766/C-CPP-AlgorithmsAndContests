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
    int t, d, m;
    cin >> t >> d >> m;
    vector<int> v;
    v.push_back(0);
    v.push_back(d);
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    bool ok = false;
    for(int i=1;i<v.size();i++){
        if(v[i] - v[i-1] >= t) ok = true;
    }
    if(ok) cout << "Y\n";
    else cout << "N\n";
}
