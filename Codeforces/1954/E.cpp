#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> md[N];
ll dif[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+2);
    ll s = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] > v[i-1]) s += v[i] - v[i-1];
    }
    for(int i=1;i<=n;i++){
        int j = 1;
        while(j <= v[i]){
            int d = (v[i] + j - 1) / j;
            if(d == 1) break;
            int x = v[i] / (d-1);
            int nd = (v[i] + x - 1) / x;
            if(nd == d) x++;
            //magic
            int ovi = (v[i] + x - 2)/(x-1);
            int vl = (v[i-1] + x - 1)/x;
            int vr = (v[i+1] + x - 2)/(x-1);
            int nvi = (v[i] + x - 1)/x;
            int ov = 0, nv = 0;
            if(ovi > vl) ov += ovi - vl;
            if(nvi > vl) nv += nvi - vl;
            if(vr > ovi) ov += vr - ovi;
            if(vr > nvi) nv += vr - nvi;
            dif[x] -= ov - nv;
            j = x;
        }
    }
    int mx = *max_element(v.begin(), v.end());
    cout << s << " ";
    for(int i=2;i<=mx;i++){
        s += dif[i];
        cout << s << " ";
    }
    cout << "\n";

    
}