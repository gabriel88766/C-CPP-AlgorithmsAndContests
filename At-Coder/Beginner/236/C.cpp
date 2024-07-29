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
    //freopen("in", "r", stdin); //test input
    vector<string> v1, v2;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0;i<m;i++){
        string x;
        cin >> x;
        v2.push_back(x);
    }
    int p1 = 0;
    for(int i=0;i<n;i++){
        if(p1 < m && v2[p1] == v1[i]){
            cout << "Yes\n";
            p1++;
        }else cout << "No\n";
    }
}
