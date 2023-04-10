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
    int n, h, w;
    cin >> n >> h >> w;
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c == 'Y' || w == 0){
            w++;
            h--;
            cout << "Y ";
        }else{
            cout << "N ";
        }
        cin >> c;
        if(c == 'Y' || h == 0){
            h++;
            w--;
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
}
