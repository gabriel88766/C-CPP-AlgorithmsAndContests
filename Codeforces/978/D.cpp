#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(n <= 2) cout << "0";
    else{
        //solve.
        //possibilities, r = a[1] - a[0] or a[1]+1 - a[0] or a[1]-1 -a[0] or ...
        int d1[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
        int d0[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
        int aux[] = {0, 1, 1, 1, 2, 2, 1, 2, 2};
        int mincnt = INF_INT, cnt;
        for(int j=0;j<9;j++){
            cnt = 0;
            bool ok = true;
            int r = a[1] + d1[j] - (a[0] + d0[j]);
            int last = d1[j];
            for(int i=2; i< n; i++){
                last = (a[i-1] + last) + r - a[i];
                if(last > 1 || last < -1){
                    ok = false;
                    break;
                }
                if(last) cnt++;
            }
            if(ok) mincnt = min(mincnt, cnt + aux[j]);
        }
        if(mincnt == INF_INT) cout << "-1";
        else cout << mincnt;


    }
}
