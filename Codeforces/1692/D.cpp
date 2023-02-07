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
    int t;
    cin >> t;
    while(t--){
        int h, m, x, ch, cm;
        char c;
        cin >> h >> c >> m >> x;
        ch = h, cm = m;
        int ans = 0;
        do{
            int revh = ch/10 + (ch%10)*10;
            if(revh == cm) ans++;
            cm += x;
            ch += cm/60;
            cm %= 60;
            ch %= 24;
        }while(!(ch == h) || !(cm == m));
        cout << ans << "\n";
    }
}
