#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
char gr[N][N];
bool vis[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    string ans;
    ans += gr[1][1];
    vector<pair<int, int>> st;
    st.push_back({1, 1});
    vis[1][1] = true;
    while(st[0] != make_pair(n, n)){
        vector<pair<int, int>> pst, nst;
        char bst = 'Z';
        for(auto &[a, b] : st){
            if(a < n && vis[a+1][b] == false){
                vis[a+1][b] = true;
                pst.push_back({a+1, b});
                bst = min(bst, gr[a+1][b]);
            }
            if(b < n && vis[a][b+1] == false){
                vis[a][b+1] = true;
                pst.push_back({a, b+1});
                bst = min(bst, gr[a][b+1]);
            }
        }
        ans += bst;
        for(auto &[a, b] : pst){
            if(gr[a][b] == bst) nst.push_back({a, b});
        }
        st = nst;
    }
    cout << ans << "\n";
}   
