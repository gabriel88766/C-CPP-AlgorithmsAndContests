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
    int a, b;
    cin >> a >> b;
    a--; b--;
    vector<vector<char>> ans(98, vector<char>(98, '.'));
    for(int i=0;i<98;i++) for(int j=0;j<49;j++) ans[i][j] = '#';
    
    int p1 = 1, p2 = 1;
    for(int i=0;i<a;i++){
        ans[p1][p2] = '.';
        p2 += 2;
        if(p2 >= 49){
            p2 = 1;
            p1+=2;
        }
    }
    p1 = 1, p2 = 50;
    for(int i=0;i<b;i++){
        ans[p1][p2] = '#';
        p2 += 2;
        if(p2 >= 98){
            p2 = 50;
            p1+=2;
        }
    }
    cout << 98 << " " << 98 << "\n";
    for(int i=0;i<98;i++){
        for(int j=0;j<98;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
