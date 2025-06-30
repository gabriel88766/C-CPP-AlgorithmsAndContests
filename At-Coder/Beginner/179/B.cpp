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
    int n;
    cin >> n;
    bool ok = false;
    vector<pair<int, int>> vp(n);
    for(int j=0;j<n;j++){
        cin >> vp[j].first >> vp[j].second;
        if(j >= 2){
            bool cok = true;
            for(int k=0;k<=2;k++) if(vp[j-k].first != vp[j-k].second) cok = false;
            if(cok) ok = true;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
