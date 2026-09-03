#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bool expand_diam(int &u, int &v, int &d){
    cout << "? " << u << " " << v << " " << d+1 << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    if(ans){
        d++;
        return true;
    }else return false;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int u = 1, v = 2, d = 1;
        while(expand_diam(u, v, d));
        for(int k = 3; k <= n; k++){
            int nd = d, nv = v;
            while(expand_diam(u, k, nd));
            if(nd != d) {nv = k, d = nd;}
            while(expand_diam(k, v, nd));
            if(nd != d){
                u = k;
                d = nd;
            }else if(nv != v){
                v = k;
            }
        }
        cout << "! " << u << " " << v << " " << d << "\n";
        cout.flush();
    }
}
