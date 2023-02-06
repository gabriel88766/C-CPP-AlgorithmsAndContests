#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool weird_sort(ll a, ll b){
    int cnta = 0, cntb = 0;
    ll auxa = a, auxb = b;
    while(!(auxa % 3)){
        auxa /= 3;
        cnta++;
    }
    while(!(auxb % 3)){
        auxb /= 3;
        cntb++;
    }
    if(cnta > cntb) return true;
    else if(cnta < cntb) return false;
    else{
        return a < b;
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    //each vertex is a node
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), weird_sort);
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}
