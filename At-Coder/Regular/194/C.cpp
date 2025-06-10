#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], b[N], c[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    vector<ll> m11, m10, m01;
    for(int i=1;i<=n;i++){
        if(a[i] == 1 && b[i] == 1){
            m11.push_back(c[i]); //if any of these need to be done, they need to be first! (prove)
        }else if(a[i] == 1 && b[i] == 0){
            m10.push_back(c[i]);
        }else if(a[i] == 0 && b[i] == 1){
            m01.push_back(c[i]); //these need to be the last to be made, increasing order
        }//else don't care
    }
    sort(m11.begin(), m11.end(), greater<ll>());
    sort(m10.begin(), m10.end(), greater<ll>());
    sort(m01.begin(), m01.end());
    //calc now;
    ll sum11 = 0;
    for(auto &x : m11) sum11 += x;
    ll cur = sum11 * (m10.size() + m01.size());
    for(int i=0;i<m10.size();i++){
        cur += i * m10[i];
    }
    for(int i=0;i<m01.size();i++){
        cur += (i+1) * m01[m01.size() - i - 1];
    }
    vector<ll> ps0(m10.size());
    vector<ll> ps1(m01.size());
    for(int i=0;i<ps0.size();i++){
        ps0[i] = m10[i];
        if(i != 0) ps0[i] += ps0[i-1];
    }
    for(int i=0;i<ps1.size();i++){
        ps1[i] = m01[i];
        if(i != 0) ps1[i] += ps1[i-1];
    }
    int p0 = 0, p1 = m01.size() - 1;
    ll ans = cur;
    for(int i=0;i<m11.size();i++){
        while(p0 < m10.size() && m10[p0] >= m11[i]) p0++;
        while(p1 >= 0 && m01[p1] >= m11[i]) p1--;
        ll dif = 0;
        if(ps0.size()){
            dif += ps0.back();
            if(p0 > 0) dif -= ps0[p0-1];
        }
        if(ps1.size()){
            if(p1 >= 0) dif += ps1[p1];
        }
        dif -= (m10.size() - p0 + p1) * m11[i];
        cur += dif;
        sum11 -= m11[i];
        cur += sum11 * 2;
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
