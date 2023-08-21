#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(vector<string> &v, char s){
    for(int i=0;i<3;i++){
        if(v[i][0] == s && v[i][1] == s && v[i][2] == s) return true;
        if(v[0][i] == s && v[1][i] == s && v[2][i] == s) return true;
    }
    if(v[0][0] == s && v[1][1] == s && v[2][2] == s) return true;
    if(v[2][0] == s && v[1][1] == s && v[0][2] == s) return true;
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
        vector<string> v(3);
        for(int i=0;i<3;i++) cin >> v[i];
        if(check(v, '+')) cout << "+\n";
        else if(check(v, 'O')) cout << "O\n";
        else if(check(v, 'X')) cout << "X\n";
        else cout << "DRAW\n";
    }
}
