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
    int n;
    cin >> n;
    int sd = n % 16;
    int fd = n / 16;
    char c1, c2;
    if(fd <= 9) c1 = '0' + fd;
    else c1 = 'A' + fd - 10;
    if(sd <= 9) c2 = '0' + sd;
    else c2 = 'A' + sd - 10;
    cout << c1 << c2 << "\n";
}
