#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int i, int j){
    if(i == j) return 0;
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
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
        vector<int> d1(n*n+1), df(n*n+1), d3(n*n+1);
        vector<vector<int>> ans(n+1, vector<int>(n+1));
        for(int i=1;i<=n*n;i++) d1[i] = query(1, i);
        int fth = 1;
        for(int i=1;i<=n*n;i++) if(d1[i] > d1[fth]) fth = i;
        for(int i=1;i<=n*n;i++) df[i] = query(fth, i);
        //among those which df[i] = n-1;
        int bst = 1;
        vector<int> ps;
        for(int i=1;i<=n*n;i++){
            if(df[i] == n-1){
                ps.push_back(i);
            }
        }
        if(ps.size() == 2){
            //special case:
            bst = ps[0];
        }else{
            int xx = -1;
            for(int i=1;i<=n*n;i++){
                if(df[i] == 1){
                    xx = i;
                    break;
                }
            }
            // assert(xx != -1);
            vector<int> actx(n*n, 0);
            for(auto x : ps){
                actx[x] = query(x, xx);
            }
            bst = xx;
            for(auto x : ps){
                if(actx[x] > actx[bst]) bst = x;
            }
        }


        ans[1][1] = fth;
        ans[1][n] = bst;
        for(int i=1;i<=n*n;i++) d3[i] = query(bst, i);
        for(int i=1;i<=n*n;i++){
            if(i != bst && i != fth){
                int sum = df[i] + d3[i];
                //sum = n-1 + 2*x - 2 = n + 2*x - 3 => x = (sum - n + 3)/2
                int x = (sum - n + 3)/2;
                int y = df[i] - (x - 1) + 1;
                ans[x][y] = i;
            }
        }
        cout << "!\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout.flush() << "\n";
    }
}
