#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(int xs, int ys, int xd, int yd, int a, int b){
    if(abs(xd-xs) == a && abs(yd-ys) == b) return true;
    if(abs(xd-xs) == b && abs(yd-ys) == a) return true;
    return false;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int a, b;
        int x1, x2, y1, y2;
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        if(a != b){
            if(check(x1+a, y1+b, x2, y2, a, b)) ans++;
            if(check(x1-a, y1-b, x2, y2, a, b)) ans++;
            if(check(x1+a, y1-b, x2, y2, a, b)) ans++;
            if(check(x1-a, y1+b, x2, y2, a, b)) ans++;
            if(check(x1+b, y1+a, x2, y2, a, b)) ans++;
            if(check(x1-b, y1-a, x2, y2, a, b)) ans++;
            if(check(x1+b, y1-a, x2, y2, a, b)) ans++;
            if(check(x1-b, y1+a, x2, y2, a, b)) ans++;
        }else{
            if(check(x1+a, y1+a, x2, y2, a, a)) ans++;
            if(check(x1-a, y1-a, x2, y2, a, a)) ans++;
            if(check(x1+a, y1-a, x2, y2, a, a)) ans++;
            if(check(x1-a, y1+a, x2, y2, a, a)) ans++;
        }
        
        cout << ans << "\n";
        

    }
}
