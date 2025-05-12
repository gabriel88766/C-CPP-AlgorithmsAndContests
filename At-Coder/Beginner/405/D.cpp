#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[2005][2005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char ans[] = {'<', '^', '>', 'v'};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;//h<=1000 w<=1000
    queue<pair<int, int>> qp;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'E') qp.push({i, j});
        }
    }
    while(qp.size()){
        auto [x, y] = qp.front();
        qp.pop();
        for(int i=0;i<4;i++){
            int xd = x + dx[i];
            int yd = y + dy[i];
            if(xd > 0 && xd <= h && yd > 0 && yd <= w){
                if(gr[xd][yd] == '.'){
                    gr[xd][yd] = ans[i];
                    qp.push({xd, yd});
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout << gr[i][j];
        }
        cout << "\n";
    }
}
