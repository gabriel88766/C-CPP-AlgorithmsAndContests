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
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n;
    vector<ll> a(n+1);
    ll suma = 0, sumb = 0;
    for(int i=0;i<n;i++){
         cin >> a[i];
         suma += a[i];
    }
    cin >> m;
    vector<ll> b(m+1);
    for(int i=0;i<m;i++){
         cin >> b[i];
         sumb += b[i];
    }
    a[n] = b[m] = 0;
    if(suma != sumb) cout << "-1\n";
    else{
        int p1 = 1, p2 = 0;
        ll cursuma = a[0], cursumb = 0;
        int cnt = 0;
        while(p1 < n || p2 < m){
            if(cursuma > cursumb){
                cursumb += b[p2++];
            }else if(cursuma < cursumb){
                cursuma += a[p1++];
            }else{
                cnt++;
                cursuma += a[p1++];
            }
        }
        cnt++;
        cout << cnt << "\n";
    }

}
