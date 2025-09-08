#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int dir = 0;
    int x = 0, y = 0;
    int n;
    string s;
    cin >> n >> s;
    for(auto c : s){
        if(c == 'R') dir = (dir + 1) % 4;
        else{
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout << x << " " << y << "\n";
}
