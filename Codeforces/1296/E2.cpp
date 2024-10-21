#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 26;
int adj[N][N];
int mp[256];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int sz = 0;
    vector<int> ans(n+1, 0);
    vector<int> cur(26, 0);
    for(int i=n;i>=1;i--){
        int cl = s[i] - 'a';
        int ml = 0;
        for(int j=0;j<cl;j++) ml = max(ml, cur[j]);
        cur[cl] = ans[i] = ml + 1;
        sz = max(sz, ans[i]);
    }
    cout << sz << "\n";
    for(int i=1;i<=n;i++){
        cout << ans[i] << " "; 
    }
    cout << "\n";
   
}
