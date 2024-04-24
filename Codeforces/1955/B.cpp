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
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> v(n*n);
        for(int i=0;i<n*n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> v2;
        int beg = v[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v2.push_back(beg + c*j);
            }
            beg += d;
        }
        sort(v2.begin(), v2.end());
        if(v == v2) cout << "YES\n";
        else cout << "NO\n";
    }
}
