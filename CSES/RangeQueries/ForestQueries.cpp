//prefix sum 2d
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

ll ps[1001][1001];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            char c;
            cin >> c;
            if(c == '*') ps[i][j]++;
        }
    }

    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << ps[c][d] - ps[a-1][d] - ps[c][b-1] + ps[a-1][b-1] << "\n";
    }
}
