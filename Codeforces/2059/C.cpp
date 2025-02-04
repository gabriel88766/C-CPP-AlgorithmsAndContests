#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[305][305];
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
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> gr[j][i];
            }
        }
        vector<int> v;
        for(int j=1;j<=n;j++){
            int c = 0;
            for(int i=n;i>=1;i--){
                if(gr[i][j] == 1) c++;
                else break;
            }
            v.push_back(c);
        }
        int ans = 0;
        sort(v.begin(), v.end(), greater<int>());
        while(v.size()){
            int u = v.back();
            v.pop_back();
            if(u >= ans) ans++;
        }
        cout << ans << "\n";
    }
}
