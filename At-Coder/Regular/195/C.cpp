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
        int r, b;
        cin >> r >> b;
        if(r % 2) cout << "No\n";
        else if(r != 0){
            cout << "Yes\n";
            int x = 1000000;
            vector<tuple<char, int, int>> ans;
            for(int j = 1; j <= r/2; j++){
                ans.emplace_back('R', 1, j);
            }
            for(int j = r/2; j>= 1; j--){
                ans.emplace_back('R', 2, j);
            }
            if(b > 0){
                if(b % 2 == 1){
                    b -= 1;
                    ans.emplace_back('B', 2, 0);
                }else{
                    b -= 2;
                    ans.emplace_back('B', 3, 1);
                    ans.emplace_back('B', 2, 0);
                }
                for(int j=1;j<=b/2;j++){
                    ans.emplace_back('B', 2-j, -j);
                }
                for(int j=b/2;j>=1;j--){
                    ans.emplace_back('B', 1-j, 1-j);
                }
            }
            for(auto [a, b, c] : ans) cout << a << " " << x+b << " " << x+c << "\n";
        }else{
            if(b % 2) cout << "No\n";
            else{
                cout << "Yes\n";
                int x = 1000000;
                vector<tuple<char, int, int>> ans;
                for(int j=1;j<=b/2;j++){
                    ans.emplace_back('B', 2-j, -j);
                }
                for(int j=b/2;j>=1;j--){
                    ans.emplace_back('B', 1-j, 1-j);
                }
                for(auto [a, b, c] : ans) cout << a << " " << x+b << " " << x+c << "\n";
            }
        }
    }
}
