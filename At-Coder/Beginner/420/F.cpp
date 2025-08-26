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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> gr(n+3, vector<char>(m+3, 0));
    vector<vector<int>> aux(n+3, vector<int>(m+3, 0));
    auto ans = aux;
    auto lgs = aux;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(gr[i][j] == '.') lgs[i][j] = lgs[i][j+1] + 1;
        }
    }
    for(int j=1;j<=m;j++){
        //Goodbye monotonic queue weird ideas...
        //Hello straightforward sort with sets...
        vector<pair<int, int>> v;
        set<int> s;
        s.insert(0);
        s.insert(n+1);
        for(int i=1;i<=n;i++){
            // if(lgs[i][j] == 1) cout << i << " " << j << "\n";
            v.push_back({lgs[i][j], i});
        }
        sort(v.begin(), v.end());
        for(auto &[val, j] : v){
            auto it = s.lower_bound(j);
            int l = *prev(it), r = *it;
            //anyway, weird logic
            //summing all rect such that include j.
            int mx = min(j-l, r-j);
            // cout << r-l+1 << " " << r-l-mx+1 << " " << val << endl;
            //1, 2, 3, .., mx, mx, mx, ..., mx-1, mx-2, ... , 1
            ans[1][val] += 1;
            ans[mx+1][val] -= 1;
            ans[r-l-mx+1][val] -= 1;
            ans[r-l+1][val] += 1;
            s.insert(j);
        }
 
    }
    // cout << "here" << endl;
    //WEIRD MAGIC x3
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i][j] += ans[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i][j] += ans[i-1][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            ans[i][j] += ans[i][j+1];
        }
    }
    //JUST PRINT NOW
    ll rans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i * j <= k) rans += ans[i][j];
            // cout << ans[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << rans << "\n";
}
