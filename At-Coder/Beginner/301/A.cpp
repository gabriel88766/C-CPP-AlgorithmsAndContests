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
    string s;
    int n;
    cin >> n >> s;
    int t = 0, a = 0;
    for(auto x : s){
        if(x == 'T') t++;
        else a++;
    }
    if(t > a) cout << "T\n";
    else if(t < a) cout << "A\n";
    else{
        if(s.back() == 'T') cout << "A\n";
        else cout << "T\n";
    }
}
