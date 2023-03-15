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
    int A;
    cin >> A;
    int sum = 0;
    for(int i=2;i<A;i++){
        int curs = 0;
        int aux = A;
        while(aux){
            curs += aux % i;
            aux /= i;
        }
        sum += curs;
    }
    int num = A-2;
    int g = __gcd(sum, num);
    sum /= g;
    num /= g;
    cout << sum << "/" << num;
}
