#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool ok = false;
    for(int k=0;k<8;k++){
        int di = x1 + dx[k];
        int dj = y1 + dy[k];
        int d1 = abs(di - x2);
        int d2 = abs(dj - y2);
        if(d1 < d2) swap(d1, d2);
        if(d1 == 2 && d2 == 1) ok = true;
    }

    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
