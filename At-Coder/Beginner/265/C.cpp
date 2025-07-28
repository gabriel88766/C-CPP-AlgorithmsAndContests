#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
char gr[N][N];
bool vis[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    int ci = 1, cj = 1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    bool fin = false;
    while(!vis[ci][cj]){
        vis[ci][cj] = true;
        if(gr[ci][cj] == 'U'){
            if(ci == 1){
                cout << ci << " " << cj << "\n";
                fin = true; 
                break;
            }else ci--;
        }else if(gr[ci][cj] == 'D'){
            if(ci == h){
                cout << ci << " " << cj << "\n";
                fin = true;
                break;
            }else ci++;
        }else if(gr[ci][cj] == 'L'){
            if(cj == 1){
                cout << ci << " " << cj << "\n";
                fin = true;
                break;
            }else cj--;
        }else{
            if(cj == w){
                cout << ci << " " << cj << "\n";
                fin = true;
                break;
            }else cj++;
        }
    }
    if(!fin) cout << "-1\n";
}
