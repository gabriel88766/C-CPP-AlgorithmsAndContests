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
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a == 0){
            cout << "1\n";
            continue;
        }
        if(b < c) swap(b,c);
        if((b - c) > a){
            cout << 2*a + 2*c + 1<< "\n";
        }else{
            int mood = a - b + c;
            if(mood < d) cout << a+b+c+mood+1 << "\n";
            else cout << a+b+c+d << "\n";
        }
    }
}
