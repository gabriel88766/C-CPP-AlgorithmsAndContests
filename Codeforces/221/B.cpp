#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    for(auto c : sa){
        for(auto d : sb){
            if(c == d) return true;
        }
    }
    return false;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int ans = 0, x;
    cin >> x;
    for(int i=1;i*i<=x;i++){
        if(x % i == 0){
            if(check(x, i)) ans++;
            if(i*i != x && check(x, x/i)) ans++;
        } 
        
    }
    cout << ans << "\n";
}
