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
    int t;
    cin >> t;
    while(t--){
        int md = 0, mp = -INF_INT;
        int n, x;
        cin >> n >> x;
        for(int i=0;i<n;i++){
            int d, h;
            cin >> d >> h;
            md = max(md, d);
            mp = max(mp, d-h);
        }
        if(md >= x) cout << "1\n";
        else if(mp > 0){
            int g = (x - md + mp - 1)/mp + 1;
            cout << g << "\n";
        }else cout << "-1\n";
    }
}