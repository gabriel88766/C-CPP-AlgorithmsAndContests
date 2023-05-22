#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int h,w;
vector<string> v(105);

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
char eq[] = {'s', 'n', 'u', 'k', 'e'};

bool check(int x, int y, int t){
    int gx = x + dx[t]*4;
    int gy = y + dy[t]*4;
    if(gx < 0 || gx >= h || gy < 0 || gy >= w) return false;
    for(int i=0;i<=4;i++){
        if(v[x+dx[t]*i][y+dy[t]*i] != eq[i]) return false;
    }
    return true;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> h >> w;
    for(int i=0;i<h;i++) cin >> v[i];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int t=0;t<8;t++){
                if(check(i, j, t)){
                    int x = i+1, y = j+1;
                    for(int k=0;k<=4;k++){
                        cout << x + dx[t]*k << " " << y+dy[t]*k << "\n";
                    }
                    return 0;
                }
            }
        }
    }
}
 