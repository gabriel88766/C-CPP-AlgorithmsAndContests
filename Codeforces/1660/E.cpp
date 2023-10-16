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
        int n;
        cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
                if(v[i][j] == '1') c++;
            }
        }
        int maxv = 0;
        for(int i=0;i<n;i++){
            //diagonal begins in v[0][i]
            int cur = 0;
            for(int j=0;j<n;j++){
                if(v[j][(i+j)%n] == '1') cur++;
            }
            maxv = max(cur, maxv);
        }
        cout << n+c-2*maxv << "\n";
    }
}
