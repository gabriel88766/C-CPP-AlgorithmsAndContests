#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000005;
int has[N];
int mat[1005][1005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
            if(mat[i][j] < N) has[mat[i][j]] = 1;
        }
    }
    bool ok = true;
    for(int i=1;i<=n*n;i++) if(!has[i]) ok = false;
    ll sum = 0;
    ll sdiag = 0;
    for(int i=0;i<n;i++){
        ll scol = 0, srow = 0;
        sdiag += mat[i][i];
        for(int j=0;j<n;j++){
            scol += mat[j][i];
            srow += mat[i][j];
        }
        if(sum == 0) sum = srow;
        if(sum != srow || sum != scol) ok = false;
    }   
    if(sdiag != sum) ok = false;
    if(ok) cout << sum << "\n";
    else cout << "0\n";
}
