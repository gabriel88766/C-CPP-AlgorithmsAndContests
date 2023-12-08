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
    int n;
    cin >> n;
    vector<vector<bool>> ans(n, vector<bool>(n, false));
    int cur;
    for(int i=0;i<n;i++) ans[n/2][i] = ans[i][n/2] = true;
    cur = 2*n-1;
    vector<int> ps;
    int ind = -2;
    while(cur != (n*n+1)/2){
        if(ps.size() >= 2){
            int b1 = ps.back();
            ps.pop_back();
            int b2 = ps.back();
            ps.pop_back();
            ans[ind][b1] = ans[ind][b2] = ans[ind+1][b1] = ans[ind+1][b2] = true;
            cur += 4;
        }else{
            assert(ind+1 < n);
            ps.clear();
            ind += 2;
            for(int j=0;j<n;j++) if(!ans[ind][j] && !ans[ind+1][j]) ps.push_back(j);
        }
    }
    int p1 = 1, p2 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j] % 2){
                cout << 2*p1-1 << " ";
                p1++;
            }else{
                cout << 2*p2 << " ";
                p2++;
            }
        }
        cout << "\n";
    }
}
