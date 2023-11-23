#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int,int> cels[] = {{0, 0}, {3, 1}, {6, 2}, {1, 3}, {4, 4}, {7, 5}, {2, 6}, {5, 7}, {8, 8}};
char gr[9][9];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin >> gr[i][j];
            }
        }
        for(auto [a, b] : cels){
            if(gr[a][b] != '9') gr[a][b]++;
            else gr[a][b]--;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << gr[i][j];
            }
            cout << "\n";
        }
    }
}
