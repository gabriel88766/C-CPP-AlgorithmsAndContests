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
        bool ok = true;
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i] == '2'){
                v.push_back(i);
            }
        }
        if(v.size() == 0 || v.size() >=3 ){
            for(int i=0;i<v.size();i++){
                int p1 = v[i];
                int p2 = v[(i+1)%v.size()];
                ans[p1][p2] = 1;
                ans[p2][p1] = -1;
            }
            cout << "YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) cout << "X";
                    else if(ans[i][j] == 1) cout << "+";
                    else if(ans[i][j] == 0) cout << "=";
                    else cout << "-";
                }
                cout << "\n";
            }
        }else cout << "NO\n";
    }
}
