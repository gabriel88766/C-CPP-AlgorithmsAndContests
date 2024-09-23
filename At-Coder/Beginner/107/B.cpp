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
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for(int i=0;i<h;i++) cin >> v[i];
    vector<bool> r(h, false), c(w, false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(v[i][j] == '#') r[i] = c[j] = true;
        }
    }
    vector<int> vr, vc;
    for(int i=0;i<h;i++) if(r[i]) vr.push_back(i);
    for(int i=0;i<w;i++) if(c[i]) vc.push_back(i);
    for(auto x : vr){
        for(auto y : vc){
            cout << v[x][y];
        }
        cout << "\n";
    }
}
