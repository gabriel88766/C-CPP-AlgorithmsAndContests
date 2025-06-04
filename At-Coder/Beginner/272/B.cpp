
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
bool adj[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        vector<int> v(k);
        for(int j=0;j<k;j++) cin >> v[j];
        for(int j=0;j<k;j++){
            for(int l=j+1;l<k;l++){
                adj[v[j]][v[l]] = true;
            }
        }
    }
    bool ok = true;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(!adj[i][j]){
                ok = false;
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
