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
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    if(ab == '<'){
        //then a < b.
        //check if a < b < c or a < c < b or c < a < b
        if(bc == '<') cout << "B\n";
        else if(ac == '<') cout << "C\n"; //b > c and b > a
        else cout << "A\n";
    }else{
        //then a > b
        if(ac == '<') cout << "A\n"; // c > a > b
        else if(bc == '<') cout << "C\n";       //a > c and a > b
        else cout << "B\n";
    }
}
