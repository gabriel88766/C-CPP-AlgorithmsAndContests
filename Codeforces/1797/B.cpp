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
        vector<vector<int>> v(n, vector<int> (n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] != v[n-i-1][n-j-1]) cnt++;
            }
        }
        cnt /= 2;
        if(cnt <= k && (((k-cnt)%2 == 0) || n%2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
