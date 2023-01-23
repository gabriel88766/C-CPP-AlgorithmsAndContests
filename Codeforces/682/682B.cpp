#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int curmex = 1;
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        if(v[i] >= curmex) curmex++;
    }
    cout << curmex;

}
