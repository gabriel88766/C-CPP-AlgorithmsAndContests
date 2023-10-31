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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<int>> maxv(n, vector<int>(m, 0));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
             cin >> v[i][j];
             maxv[i][j] = v[i][j];
             if(j) maxv[i][j] = max(maxv[i][j], maxv[i][j-1]);
        }
        int ind = -1, ind2 = -1;
        for(int i=m-1;i>=0;i--){
            bool ok = true;
            for(int j=0;j<n;j++){
                if(maxv[j][i] != v[j][i]){
                    ok = false;
                }
            }
            if(!ok){
                ind = i;
                break;
            }
        }
        if(ind == -1) cout << "1 1\n";
        else{
            for(int i=ind-1;i>=0;i--){
                bool ok = true;
                for(int j=0;j<n;j++){
                    if(maxv[j][ind] != v[j][i]){
                        ok = false;
                    }
                }
                if(ok){
                    ind2 = i;
                }
            }
            if(ind2 == -1) cout << "-1\n";
            else{
                for(int i=0;i<n;i++) swap(v[i][ind], v[i][ind2]);
                bool ok = true;
                for(int i=0;i<n;i++) for(int j=1;j<m;j++){
                    if(v[i][j] < v[i][j-1]) ok = false;
                }
                if(ok) cout << ind2+1 << " " << ind+1 << "\n";
                else cout << "-1\n";
            }
        }
    }
}
