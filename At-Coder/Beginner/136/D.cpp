#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int  N = 1e5, M = 21;
int mv[N][M];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<s.size();i++){
        if(s[i] == 'L') mv[i+1][0] = i;
        else mv[i+1][0] = i+2;
    }
    for(int i=1;i<M;i++){
        for(int j=1;j<=n;j++){
            mv[j][i] = mv[mv[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=n;i++){
        ans[mv[i][20]]++;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
