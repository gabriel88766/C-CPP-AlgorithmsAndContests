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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        int lo = x + y - 2; //lo can be x - 1
        for(int j = n; j>=1; j>>=1){
            while(true){
                int g = lo + j; //at least x
                int tt = g - x + 1 - (upper_bound(v.begin(), v.end(), g) - lower_bound(v.begin(), v.end(), x));
                if(tt < y) lo = g;
                else break;
            }
        }
        lo++;
        cout << lo << "\n";
    }
}
