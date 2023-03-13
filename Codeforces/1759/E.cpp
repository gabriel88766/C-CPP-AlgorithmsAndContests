#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> opt = {{2,2,3}, {2,3,2}, {3,2,2}};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int maxv = 0;
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        //brute force 3 2 2, 2 3 2, 2 2 3
        for(int i=0;i<3;i++){
            int bp = 0, cs = 0;
            ll power = h;
            while(bp < n){
                if(power > a[bp]) power += a[bp++]/2;
                else{
                    if(cs < 3) power *= opt[i][cs++];
                    else break;
                }
            }
            maxv = max(maxv, bp);
        }
        cout << maxv << "\n";
    }
}
 