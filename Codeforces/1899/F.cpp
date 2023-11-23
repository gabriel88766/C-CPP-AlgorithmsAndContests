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
        int n, q;
        cin >> n >> q;
        vector<int> v(q);
        for(int i=0;i<q;i++) cin >> v[i];
        bool leaf = false;
        for(int i=1;i<=n-1;i++) cout << i << " " << i+1 << "\n";
        int g = n-1;
        for(int i=0;i<q;i++){
            if(g == v[i]) cout << "-1 -1 -1\n";
            else cout << n << " " << g << " " << v[i] << "\n";
            g = v[i];
        }
    }
}
