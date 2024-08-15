#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[100005][3][3][3];
tuple<int, int, int> p[100005][3][3][3];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(a+b+c == 2){
        dp[0][a][b][c] = true;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int u=0;u<=2;u++){
                for(int v=0;v<=2;v++){
                    for(int x=0;x<=2;x++){
                        if(!dp[i-1][u][v][x]) continue;
                        if(s == "AB"){
                            if(v > 0){// u can't be 2 and v > 0 and this above true
                                dp[i][u+1][v-1][x] = true;
                                p[i][u+1][v-1][x] = {-1, 1, 0};
                            }
                            if(u > 0){
                                dp[i][u-1][v+1][x] = true;
                                p[i][u-1][v+1][x] = {1, -1, 0};
                            }
                        }else if(s == "AC"){
                            if(x > 0){
                                dp[i][u+1][v][x-1] = true;
                                p[i][u+1][v][x-1] = {-1, 0, 1};
                            }
                            if(u > 0){
                                dp[i][u-1][v][x+1] = true;
                                p[i][u-1][v][x+1] = {1, 0, -1};
                            }
                        }else{
                            if(x > 0){
                                dp[i][u][v+1][x-1] = true;
                                p[i][u][v+1][x-1] = {0, -1, 1};
                            }
                            if(v > 0){
                                dp[i][u][v-1][x+1] = true;
                                p[i][u][v-1][x+1] = {0, 1, -1};
                            }
                        }
                    }
                }
            }
        }
        int ax = -1, bx = -1, cx = -1;
        for(int u=0;u<=2;u++){
            for(int v=0;v<=2;v++){
                for(int x=0;x<=2;x++){
                    if(dp[n][u][v][x]){
                        ax = u, bx = v, cx = x;
                    }
                }
            }
        }
        if(ax == -1) cout << "No\n";
        else{
            cout << "Yes\n";
            vector<char> ans;
            for(int i=n;i>=1;i--){
                auto [da, db, dc] = p[i][ax][bx][cx];
                if(da == -1) ans.push_back('A');
                if(db == -1) ans.push_back('B');
                if(dc == -1) ans.push_back('C');
                ax += da;
                bx += db;
                cx += dc;
            }
            assert(ax == a && bx == b && cx == c);
            reverse(ans.begin(), ans.end());
            for(auto x : ans) cout << x << "\n";
        }
    }else{
        vector<char> ans;
        bool ok = true;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            if(s == "AB"){
                if(a < b){
                    ans.push_back('A');
                    a++, b--;
                }else{
                    ans.push_back('B');
                    a--, b++;
                } 
                if(a < 0 || b < 0) ok = false;
            }else if(s == "AC"){
                if(a < c){
                    ans.push_back('A');
                    a++, c--;
                }else{
                    ans.push_back('C');
                    a--, c++;
                } 
                if(a < 0 || c < 0) ok = false;
            }else{
                if(b < c){
                    ans.push_back('B');
                    b++, c--;
                }else{
                    ans.push_back('C');
                    b--, c++;
                } 
                if(b < 0 || c < 0) ok = false;
            }
        }
        if(ok){
            cout << "Yes\n";
            for(int i=0;i<ans.size();i++) cout << ans[i] << "\n";
        }else cout << "No\n";
    }
}
