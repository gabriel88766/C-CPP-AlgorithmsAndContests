#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cout << 10 << " " << 10 << "\n";
    cout.flush();
    int a, b;
    cin >> a >> b;
    if(a != 10){
        //line 10 is free
        cout << 10 << " " << 11 << "\n";
        cout.flush();
        cin >> a >> b;
        if(b != 12) cout << 10 << " " << 12 << "\n";
        else cout << 10 << " " << 9 << "\n";
        cout.flush();
    }else if(b != 10){
        //line 10 isn't free, but is collumn 10
        cout << 11 << " " << 10 << "\n";
        cout.flush();
        cin >> a >> b;
        if(a != 12) cout << 12 << " " << 10 << "\n";
        else cout << 9 << " " << 10 << "\n";
        cout.flush();
    }else assert(false); //what happened?
    cin >> a >> b;
}
