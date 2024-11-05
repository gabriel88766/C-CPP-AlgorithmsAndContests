#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> vs = {"ABC", "ARC", "AHC", "AGC"};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for(auto x : vs){
        if(x != s1 && x != s2 && x != s3) cout << x << "\n";
    }
}
