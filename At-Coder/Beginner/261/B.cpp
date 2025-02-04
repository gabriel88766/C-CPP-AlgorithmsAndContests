#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
char gr[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> gr[i][j];
        }
    }
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(gr[i][j] == 'L' && gr[j][i] != 'W') ok = false;
            if(gr[i][j] == 'W' && gr[j][i] != 'L') ok = false;
            if(gr[i][j] == 'D' && gr[j][i] != 'D') ok = false;
        }
    }
    if(ok) cout << "correct\n";
    else cout << "incorrect\n";
}
