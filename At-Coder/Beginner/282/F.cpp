#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int nc[4005][4005];
vector<pair<int, int>> qrs;
int cnt = 0;
void init(int l, int r){
    if(l == r){
        if(!nc[l][l]){
            nc[l][l] = ++cnt;
            qrs.push_back({l, l});
        }
        return;
    }
    int m = (l + r)/2;
    for(int i=l;i<=m;i++){
        if(!nc[i][m]){
            qrs.push_back({i, m});
            nc[i][m] = ++cnt;
        }
    }
    for(int i=m+1;i<=r;i++){
        if(!nc[m+1][i]){
            qrs.push_back({m+1, i});
            nc[m+1][i] = ++cnt;
        }
    }
    init(l, m);
    init(m+1, r);
}

void solve(int i, int j, int l, int r){
    if(i == j){
        cout << nc[i][i] << " " << nc[i][i] << "\n";
        cout.flush();
        return;
    }
    int m = (l+r)/2;
    if(m >= j) solve(i, j, l, m);
    else if(i >= m+1) solve(i, j, m+1, r);
    else{
        cout << nc[i][m] << " " << nc[m+1][j] << "\n";
        cout.flush();
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    int n;
    cin >> n;
    init(1, n);
    cout << qrs.size() << "\n";
    cout.flush();
    for(auto [a, b] : qrs){
        cout << a << " " << b << "\n";
        cout.flush();
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        solve(a, b, 1, n);
    }
}
