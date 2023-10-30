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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v(m);
    int sum = 0;
    for(int i=0;i<m;i++){
         cin >> v[i];
         sum += v[i];
    }
    sum += (d-1)*(m+1);
    if(sum >= n){
        cout << "YES\n";
        vector<int> sp(m+1, d-1);
        //i dont care hahaha
        int p = 0;
        while(sum > n){
            sum--;
            if(sp[p] > 0) sp[p]--;
            else sp[++p]--;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<sp[i];j++) cout << "0 ";
            for(int j=0;j<v[i];j++) cout << i+1 << " ";
        }
        for(int j=0;j<sp[m];j++) cout << "0 ";
        cout << "\n";
    }else cout << "NO\n";

}
