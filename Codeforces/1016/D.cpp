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
    int n, m;
    cin >> n >> m;
    vector<int> xi(n), xj(m);
    for(int i=0;i<n;i++) cin >> xi[i];
    for(int i=0;i<m;i++) cin >> xj[i];
    vector<vector<int>> ans(n, vector<int>(m, 0));
    bool ok = true;
    for(int b=0;b<=29;b++){
        int x = 1 << b;
        vector<vector<int>> cur(n, vector<int>(m, 0));
        vector<int> r, c;
        for(int i=0;i<n;i++){
            if(xi[i] & x) r.push_back(i);
        }
        for(int i=0;i<m;i++){
            if(xj[i] & x) c.push_back(i);
        }
        if((c.size() + r.size()) % 2){
            ok = false;
            break;
        }
        while(c.size() || r.size()){
            if(c.size() && r.size()){
                cur[r.back()][c.back()] ^= 1;
                r.pop_back();
                c.pop_back();
            }else if(c.size()){
                cur[0][c.back()] ^= 1;
                c.pop_back();
                r.push_back(0);
            }else{
                cur[r.back()][0] ^= 1;
                r.pop_back();
                c.push_back(0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] += cur[i][j] * x;
            }
        }
    }
    if(ok){
        cout << "YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }else cout << "NO\n";
}
