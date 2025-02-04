#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 10005, M = 2005;
int add[N], sub[N];
vector<int> rm[N];
int ans[M][M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<string> gr(n);
    for(int i=0;i<n;i++) cin >> gr[i];
    for(int i=0;i<n;i++){
        for(auto &x : rm[i]) add[x]--, sub[x]--;
        int cur = 0;
        for(int j=0;j<n;j++){
            if(gr[i][j] == 'O'){
                add[j] += 1;
                sub[j+2*m] += 1;
                //2m, 2m-2, 2m-4, ..., 2 : total m lines
                rm[i + m].push_back(j);
            }
            cur += add[j];
            cur -= sub[j];
            ans[i][j] = cur;
        }
        for(int j=0;j<2*m+n;j++){
            sub[j] = sub[j+2];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << ans[a-1][b-1] << "\n";
    }
}
