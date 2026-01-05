#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2030;
bool vis[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    while(!vis[n]){
        vis[n] = true;
        string s = to_string(n);
        int nn = 0;
        for(auto c : s){
            int cn = c - '0';
            nn += cn*cn;
        }
        n = nn;
    }
    if(vis[1]) cout << "Yes\n";
    else cout << "No\n";
}
