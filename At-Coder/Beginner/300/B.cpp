#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int h,w;
void shiftR(vector<vector<char>> &v){
    auto x = v;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            x[i][(j+1)%w] = v[i][j];
        }
    }
    v = x;
}

void shiftD(vector<vector<char>> &v){
    auto x = v;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            x[(i+1)%h][j] = v[i][j];
        }
    }
    v = x;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> b[i][j];
        }
    }
    bool ok = false;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a == b) ok = true;
            shiftR(a);
        }
        shiftD(a);
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
