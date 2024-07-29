#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //thest input
    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    vector<string> v(h+1);
    string x;
    for(int i=1;i<=h;i++){
        cin >> v[i];
        v[i] = " " + v[i];
    }
    cin >> x;
    for(int i=0;i<x.size();i++){
        if(x[i] == 'L'){
            if(sj > 1 && v[si][sj-1] == '.') sj--;
        }else if(x[i] == 'R'){
            if(sj < w && v[si][sj+1] == '.') sj++;
        }else if(x[i] == 'U'){
            if(si > 1 && v[si-1][sj] == '.') si--;
        }else{
            if(si < h && v[si+1][sj] == '.') si++;
        }
    }
    cout << si << " " << sj << "\n";
}
