#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    //LIS
    vector<int> aux = {0};
    for(int i=0;i<n;i++){
        int ind = upper_bound(aux.begin(), aux.end(), a[i]-1) - aux.begin();
        if(ind < aux.size()){
            aux[ind] = min(aux[ind], a[i]);
        }else{
            aux.push_back(a[i]);
        }
    }
    cout << aux.size()-1;

}
