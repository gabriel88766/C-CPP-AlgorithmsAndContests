#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
     cin >> n >> m;
     vector<string> v1, v2;
     for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v1.push_back(s);
     }
     for(int i=0;i<m;i++){
        string s;
        cin >> s;
        v2.push_back(s);
     }
    int qnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v1[i][5] != v2[j][2]) continue;
            else if(v1[i][4] != v2[j][1]) continue;
            else if(v1[i][3] != v2[j][0]) continue;
            else{
                qnt++;
                break;
            }
        }
    }
    cout << qnt;

}
