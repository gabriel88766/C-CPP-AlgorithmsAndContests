#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> sk[N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int r, s;
        cin >> s >> r;
        sk[s].push_back(r);
    }
    for(int i=1;i<=m;i++){
        sort(sk[i].begin(), sk[i].end(), greater<int>());
        int cs = 0;
        for(int j=1;j<=sk[i].size();j++){
            cs += sk[i][j-1];
            if(cs >= 0) ans[j] += cs;
            else break;
        }
    }
    int cans = 0;
    for(int i=1;i<=n;i++){
        cans = max(cans, ans[i]);
    }
    cout << cans << "\n";
}   
