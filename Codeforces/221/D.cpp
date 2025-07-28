#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
int ctv[450][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //1+2+3+...+450 > 100k so there are at most 450 suitable numbers
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), cnt(n+1);
    vector<int> pn;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] <= n){
            cnt[a[i]]++;
            if(cnt[a[i]] == a[i]){
                pn.push_back(a[i]);
            }
        }
    }
    assert(pn.size() <= 450);
    for(int j=0;j<pn.size();j++){
        for(int i=1;i<=n;i++){
            if(a[i] == pn[j]) ctv[j][i] = 1;
            ctv[j][i] += ctv[j][i-1];
        }
    }
    for(int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int j=0;j<pn.size();j++){
            if(ctv[j][r] - ctv[j][l-1] == pn[j]) ans++;
        }
        cout << ans << "\n";
    }
}