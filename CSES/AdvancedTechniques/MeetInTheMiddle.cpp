#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
map<ll,int> mp2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, x, m;
    cin >> n >> x;
    m = n/2;
    vector<ll> v(n), sum1, sum2;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0; i < (1 << m); i++){
        ll cs = 0;
        for(int j=0;j<m;j++){
            if(i & (1 << j)){
                cs += v[j];
            }
        }
        if(cs <= x) sum1.push_back(cs);  
    }
    for(int i=0; i < (1 << (n-m)); i++){
        ll cs = 0;
        for(int j=0;j<(n-m);j++){
            if(i & (1 << j)){
                cs += v[j+m];
            }
        }
        if(cs <= x) sum2.push_back(cs);
    }
    ll cnt = 0;
    int p1 = 0, p2 = 0;
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end(), greater<ll>());

    while(p1 < sum1.size() && p2 < sum2.size()){
        if((sum1[p1] + sum2[p2]) < x) p1++;
        else if((sum1[p1] + sum2[p2]) > x) p2++;
        else{
            ll cont1 = 1, cont2 = 1;
            while((p1+1) < sum1.size() && sum1[p1+1] == sum1[p1]) p1++, cont1++;
            while((p2+1) < sum2.size() && sum2[p2+1] == sum2[p2]) p2++, cont2++;
            cnt += cont1*cont2;
            p1++;
        }
    }
    //cnt += mp2[x];
    cout << cnt;

}
