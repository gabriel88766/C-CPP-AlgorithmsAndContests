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
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1 || b == 1){
        //even here maybe it's no!
        if(n == 1){
            cout << "YES\n";
            cout << "0\n";
        }else if(n == 2){
            if(a == 1 && b == 1) cout << "NO\n";
            else{
                if(a == 2){
                    cout << "YES\n";
                    cout << "00\n";
                    cout << "00\n";
                }else{
                    cout << "YES\n";
                    cout << "01\n";
                    cout << "10\n";
                }
            }
        }else if(n == 3 && a == 1 && b == 1) cout << "NO\n";
        else{
            if(b == 1 && a != 1){
                // easy
                //example n=5 a = 5, all 0. a = 4, (1,2) all 0, a = 3, (1, 2, 3) .. a = 1 (1, 2, 3, 4, 5)
                vector<vector<char>> ans(n, vector<char>(n, '0'));
                for(int i=0;i<=n-a;i++){
                    for(int j=i+1;j<=n-a;j++){
                        ans[i][j] = ans[j][i] = '1';
                    }
                }
                cout << "YES\n";
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout << ans[i][j];
                    }
                    cout << "\n";
                }
            }else if(b != 1 && a == 1){
                vector<vector<char>> ans(n, vector<char>(n, '0'));
                for(int i=0;i<=n-b;i++){
                    for(int j=i+1;j<=n-b;j++){
                        ans[i][j] = ans[j][i] = '1';
                    }
                }
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        if(ans[i][j] == '1') ans[i][j] = ans[j][i] = '0';
                        else ans[i][j] = ans[j][i] = '1';
                    }
                }
                cout << "YES\n";
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout << ans[i][j];
                    }
                    cout << "\n";
                }
            }else{
                cout << "YES\n";
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(abs(i-j) == 1) cout << "1";
                        else cout << "0";
                    }
                    cout << "\n";
                }
            }
        }
    }else cout << "NO\n";
}
