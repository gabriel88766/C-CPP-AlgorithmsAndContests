#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int oc[100][100];
char imp[100];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int K, N, xc, yc;
    cin >> N >> K;
    xc = yc = K/2+1;
    for(int i=0;i<N;i++){
        int M;
        cin >> M;
        if(imp[M]){
            cout << "-1\n";
            continue;
        }
        int curfun, row, col, minfun=INF_INT;
        for(int j=1;j<=K;j++){
            for(int k=1;k<=(K-M+1);k++){
                char pos = true;
                curfun = 0;
                for(int w=0;w<M;w++){
                    if(oc[j][k+w]){
                        pos = false;
                        break;
                    }else{
                        curfun += abs(j-xc) + abs(k+w-yc);
                    }
                }
                if(pos){
                    if(curfun < minfun){
                        minfun = curfun;
                        row = j;
                        col = k;
                    }
                }
            }
        }
        if(minfun < INF_INT){
            for(int j=col; j<=(col+M-1);j++) oc[row][j] = true;
            cout << row << " " << col << " " << col+M-1 << "\n";
        }else{
            cout << "-1\n";
            imp[M] = true;
        }
    }
}
