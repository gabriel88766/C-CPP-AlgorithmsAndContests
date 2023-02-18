#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    //freopen("in", "r", stdin); test input
    int h1, m1, h2, m2, h3, m3;
    char aux;
    cin >> h1 >> aux >> m1 >> h2 >> aux >> m2;
    h3 = (h1 + h2)/2;
    if((h1 + h2) % 2) m3 = 30;
    else m3 = 0;
    m3 += (m1 + m2) / 2;
    if(m3 >= 60){
        m3 -= 60;
        h3++;
    }
    printf("%02d:%02d",h3,m3 );
}
