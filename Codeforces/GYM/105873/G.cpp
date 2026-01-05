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
        int n, A;
        cin >> n >> A;
        int Smin = (n-1)/2;
        if(A >= Smin){
            cout << "Yes\n";
            vector<pair<int, int>> ans;
            if(n == 3){
                cout << "0 0\n";
                cout << "0 2\n";
                cout << A << " " << 0 << "\n";
            }else if(n == 4){
                cout << "0 0\n";
                cout << "0 1\n";
                cout << A << " " << 1 << "\n";
                cout << A << " " << 0 << "\n";
            }else{
                int nd = 2*A - (n - 3);
                vector<pair<int, int>> ans;
                if(n % 2){
                    ans.push_back({0, 1});
                    n -= 3;
                }else{
                    ans.push_back({1, 1});
                    ans.push_back({0, 1});
                    n -= 4;
                }
                ans.push_back({0, 0});
                ans.push_back({1, 0});
                int nx = 2;
                for(int i=0;i<n;i+=2){
                    if(i + 2 == n) ans.push_back({nx, -nd});
                    else ans.push_back({nx, -1});
                    ans.push_back({nx, 0});
                    nx++;
                }
                for(auto [a, b] : ans){
                    cout << a << " " << b << "\n";
                }
            }
        }else cout << "No\n";
    }
}       
