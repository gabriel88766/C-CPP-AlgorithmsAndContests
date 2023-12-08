#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[105][4];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int p1 = 1, p2 = 1;
    for(int i=1;i<=m;i++){
        if(p1 <= n){
            if(v[p1][0]){
                v[p1][3] = i;
                p1++;
            }else v[p1][0] = i;
        }else{
            if(v[p2][1]){
                v[p2][2] = i;
                p2++;
            }else v[p2][1] = i;
        }
    }
    int p = 1;
    for(int i=1;i<=m;i++){
        if(v[p][1]){
            cout << v[p][1] << " ";
            v[p][1] = 0;
        }else if(v[p][0]){
            cout << v[p][0] << " ";
            v[p][0] = 0;
        }else if(v[p][2]){
            cout << v[p][2] << " ";
            v[p][2] = 0;
        }else if(v[p][3]){
            cout << v[p][3] << " ";
            v[p][3] = 0;
        }else{
            p++;
            i--;
        }
    }
}
