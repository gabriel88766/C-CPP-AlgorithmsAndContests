#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool adj2[9][9];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj2[a][b] = adj2[b][a] = 1;
    }
    vector<int> perm = {1, 2, 3, 4, 5, 6, 7, 8};
    bool ok = false;
    do{
        bool cok = true;
        for(auto [a, b] : vp){
            int ca = perm[a-1];
            int cb = perm[b-1];
            if(!adj2[ca][cb]) cok = false;
        }
        if(cok) ok = true;
    }while(next_permutation(perm.begin(), perm.end()));
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
 