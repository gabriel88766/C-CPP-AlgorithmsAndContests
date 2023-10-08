#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool adj[9][9];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<int> aux;
    for(int i=1;i<=n;i++) aux.emplace_back(i);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }
    int cnt = 0;
    do{
        bool ok = true;
        if(aux[0] != 1) break;
        for(int i = 1; i<n;i++){
            if(!adj[aux[i-1]][aux[i]]){
                ok = false; 
                break;
            }
        }
        if(ok) cnt++;
    }while(next_permutation(aux.begin(), aux.end()));
    cout << cnt << "\n";
}
