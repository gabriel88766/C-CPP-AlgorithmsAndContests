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
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = i;
        vector<vector<char>> gr(n, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> gr[i][j];
                gr[i][j] -= '0';
            }
        }
        vector<int> ans(n+1);
        for(int i=0;i<n;i++){
            int ct = 0;
            for(int j=i+1;j<n;j++){
                if(!gr[i][j]) ct++;
            }
            for(int j=1;j<=n;j++){
                if(ans[j] == 0){
                    if(ct == 0){
                        ans[j] = i+1;
                        break;
                    }else ct--;
                }
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
