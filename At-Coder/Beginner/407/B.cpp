#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dx[15][15], d1[15], d2[15];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    double odd = 1.0/36;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            //sum at least from 2 to i+j
            for(int s=2;s<=i+j;s++){
                //absolute diffence is at least from 0 to abs(i-j)
                for(int d=0;d<=abs(i-j);d++){
                    dx[s][d] += odd;
                    if(s == 2) d2[d] += odd;
                }
                d1[s] += odd;
            }
        }
    }
    int x, y;
    cin >> x >> y;
    cout << fixed << setprecision(15) << d1[x] + d2[y] - dx[x][y] << "\n";
}
