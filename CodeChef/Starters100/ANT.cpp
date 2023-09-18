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
    if(n % 2) cout << "-1\n";
    else{
        vector<vector<int>> ans(n, vector<int> (n, 0));
        string anss;
        for(int i=0;i<n-1;i++) anss += 'D';
        for(int i=0;i<n-1;i++) anss += 'R';
        for(int i=0;i<n-1;i++){
            anss += 'U';
            for(int j=0;j<n-2;j++){
                if(i % 2) anss += 'R';
                else anss += 'L';
            }
        }
        anss += 'L';
        int x = 0, y = 0;
        
        for(int i=0;i<anss.size();i++){
            ans[y][x] = i % n;
            if(anss[i] == 'L') x--;
            else if(anss[i] == 'R') x++;
            else if(anss[i] == 'U') y--;
            else y++;
        }
        
        for(auto x : ans){
            for(auto y : x){
                cout << y << " ";
            }
            cout << "\n";
        }
        cout << anss << "\n";
    }
}
