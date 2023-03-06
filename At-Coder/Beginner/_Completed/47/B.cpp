#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int col[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int W,H,N;
    cin >> W >> H >> N;
    for(int i=0;i<N;i++){
        int x,y,a;
        cin >> x >> y >> a;
        if(a == 1){
            for(int i=0; i<x;i++){
                for(int j=0;j<H;j++){
                    col[i][j] = 1;
                }
            }
        }else if(a == 2){
            for(int i=x; i<W;i++){
                for(int j=0;j<H;j++){
                    col[i][j] = 1;
                }
            }
        }else if(a == 3){
            for(int i=0; i<W;i++){
                for(int j=0;j<y;j++){
                    col[i][j] = 1;
                }
            }
        }else{
            for(int i=0; i<W;i++){
                for(int j=y;j<H;j++){
                    col[i][j] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(col[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
}
