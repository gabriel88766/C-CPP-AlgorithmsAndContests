#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double p[25][25];
double pp[25][25];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> p[i][j];
        }
    }
    cout << fixed << setprecision(15);
    if(n == 1) cout << 1.0 << "\n";
    else{
        //Trying greedy
        vector<int> ord;
        ord.push_back(0);
        vector<bool> used(n, false);
        used[0] = true;
        while(ord.size() != n){
            int i = ord.back(), ind;
            double b = 0;
            for(int j=0;j<n;j++){
                if(p[i][j] > b && !used[j]){
                    b = p[i][j];
                    ind = j;
                }
            }
            used[ind] = true;
            ord.push_back(ind);
        }
        reverse(ord.begin(), ord.end());
        //finished, WA sol
        pp[0][ord[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j != ord[i]) pp[i][j] = pp[i-1][j] * p[j][ord[i]];
                else{
                    for(int k=0;k<n;k++){
                        pp[i][j] += pp[i-1][k] * p[j][k];
                    }
                }
            }
        }
        cout << pp[n-1][0] << "\n";
    }

}
