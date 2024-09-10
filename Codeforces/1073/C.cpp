#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
int psx[N], psy[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x, y;
    string s;
    cin >> n >> s;
    cin >> x >> y;
    int dx = 0, dy = 0;
    for(auto c : s){
        if(c == 'L') dx--;
        if(c == 'R') dx++;
        if(c == 'U') dy++;
        if(c == 'D') dy--;
    }
    if(dx == x && dy == y){
        cout << "0\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        psx[i] = psx[i-1];
        psy[i] = psy[i-1];
        if(s[i-1] == 'L') psx[i]--;
        if(s[i-1] == 'R') psx[i]++;
        if(s[i-1] == 'D') psy[i]--;
        if(s[i-1] == 'U') psy[i]++;
    }
    //check if possible at all.
    int dif = n - abs(x) - abs(y);
    if(dif < 0 || dif % 2 == 1){
        cout << "-1\n";
        return 0;
    }
    //bin search
    int lo = 1, hi = n;
    while(lo != hi){
        int mid = lo + (hi - lo)/2;
        bool ok = false;
        for(int i=1;i<=n-mid+1;i++){
            //seg [i, i+mid-1]
            int dx = psx[n] - psx[i+mid-1] + psx[i-1];
            int dy = psy[n] - psy[i+mid-1] + psy[i-1];
            int ddx = x - dx;
            int ddy = y - dy;
            int cd = mid - abs(ddx) - abs(ddy);
            if(cd >= 0 && (cd % 2) == 0){
                ok = true;
            }
        }
        if(ok) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
