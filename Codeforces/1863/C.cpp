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
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        vector<bool> in(n+1, false);
        for(int i=0;i<n;i++){
            cin >> v[i];
            in[v[i]] = true;
        }
        for(int i=0;i<=n;i++){
            if(!in[i]) v[n] = i;
        }
        int x = k % (n+1);
        for(int i=n+1-x;i<2*n+1-x;i++){
            cout << v[i%(n+1)] << " ";
        }
        cout << "\n";
    }
}
