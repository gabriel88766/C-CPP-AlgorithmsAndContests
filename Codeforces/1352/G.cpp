#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> p[1001];

void init(){
    p[4] = {3, 1, 4, 2};
    for(int i=5;i<=1000;i++){
        for(int j=0;j<(i-1);j++) p[i].push_back(p[i-1][j]);
        p[i].push_back(i);
        if(!(i%2)){
            int sw = (i/4) * 3 + (i % 4 ? -1 : -2);
            for(int j=0;j<sw;j++){
                swap(p[i][i-1-j], p[i][i-2-j]);
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    init();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 2 || n == 3){
            cout << "-1\n";
            continue;
        }
        for(int i=0;i<n;i++){
            cout << p[n][i] << " ";
        }
        cout << "\n";
    }
}
