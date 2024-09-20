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
    if(n == 3 || n == 4 || n % 3 == 2) cout << "No\n";
    else{
        int s = n * (n-1);
        s /= 2;
        int x = s / 3;
        int y = x, z = x;
        vector<vector<char>> ans(n+1,vector<char>(n+1));
        for(int i=1;i<=n;i++){
            if(n-i <= x){
                for(int j=i+1;j<=n;j++) ans[i][j] = 'R';
                x -= (n - i);
            }else{
                if(x){
                    vector<int> g1, g2;
                    for(int j=i+1;j<=i+x;j++){
                        ans[i][j] = 'R';
                        g1.push_back(j);
                    }
                    g1.push_back(i);
                    for(int j=i+x+1;j<=n;j++){
                        g2.push_back(j);
                    }
                    for(auto p1 : g2){
                        char c;
                        if(y >= x+1){
                            y -= x + 1;
                            c = 'B';
                        }else{
                            assert(z >= x + 1);
                            z -= x + 1;
                            c = 'W';
                        }
                        for(auto p2 : g1){
                            ans[p2][p1] = c;
                        }
                    }
                    break;
                }else break;
            }
        }
        cout << "Yes\n";
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!ans[i][j]){
                    if(y){
                        y--;
                        ans[i][j] = 'B';
                    }else{
                        ans[i][j] = 'W';
                    }
                }
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}
