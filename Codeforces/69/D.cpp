#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool fw[500][500];
int mid = 250;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //IF reflection is the only winning move, then it's not a winning move...
    int x, y, n, d;
    cin >> x >> y >> n >> d;
    vector<pair<int, int>> dir(n);
    for(int i=0;i<n;i++){
        cin >> dir[i].first >> dir[i].second;
    }
    for(int i=201;i>=-201;i--){
        for(int j=201;j>=-201;j--){
            int dist = i*i + j*j;
            if(dist > d*d) continue;
            bool isw = false;
            for(auto [a, b] : dir){
                int lx = i + a;
                int ly = j + b;
                int dist = lx * lx + ly * ly;
                if(dist > d*d) continue; //can't go there
                else if(!fw[mid + lx][mid + ly]) isw = true;
            }
            fw[mid + i][mid + j] = isw;
        }
    }
    if(fw[x + mid][y + mid]) cout << "Anton\n";
    else cout << "Dasha\n";
}
