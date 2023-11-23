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
    int cg = 0;
    bool isl = false, isl2;
    if((!(n % 4) && n % 100) || !(n%400)) isl = true;
    int curn = n;
    do{
        if((!(curn % 4) && curn % 100) || !(curn%400)) cg += 2;
        else cg += 1;
        cg %= 7;
        curn++;
        isl2 = false;
        if((!(curn % 4) && curn % 100) || !(curn%400)) isl2 = true;
    }while(cg != 0 || (isl2 ^ isl));
    cout << curn << "\n";
}
