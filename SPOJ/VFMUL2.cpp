#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1e5;

struct Complex {
    long double x, y;
    Complex() : x(0), y(0) {}
    Complex(long double a, long double b=0) : x(a), y(b) {}

    Complex operator/=(long double k) { x/=k; y/=k; return (*this); }
    Complex operator*(Complex a) const { return Complex(x*a.x - y*a.y, x*a.y + y*a.x); }
    Complex operator+(Complex a) const { return Complex(x+a.x, y+a.y); }
    Complex operator-(Complex a) const { return Complex(x-a.x, y-a.y); }
    };

void ntt(vector<ll> &a, int n, int s) {
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }

    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Complex wn = Complex(cos(s*2*PI/M), sin(s*2*PI/M));
        for(int j = 0; j < n; j += M) {
            Complex w = Complex(1, 0);
            for(int l = j; l < K + j; ++l){
                Complex t = w*a[l + K];
                a[l + K] = a[l]-t;
                a[l] = a[l] + t;
                w = wn*w;
            }
        }
    }
}

void multiply(vector<Complex> &a, vector<Complex> &b, int n) {
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    ntt(a,n,-1);
    for (int i = 0; i < n; i++) a[i] /= n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int n = 1 << (32 - __builtin_clz(int(s.size()+t.size())));
        vector<Complex> a(n), b(n);
        for(int i=0;i<s.size();i++){
            a[s.size()-i-1].x = s[i] - '0';
        }
        for(int i=0;i<t.size();i++){
            b[t.size()-i-1].x = t[i] - '0';
        }
        multiply(a,b,n);
        long double res = 0;
        long double aux = 1;
        ll carry = 0;
        string ans;
        bool ok = false;
        for(int i=0;i<(s.size()+t.size());i++){
            if(i == (s.size()+t.size()-1) && !carry)break;
            ll cur = carry + round(a[i].x);
            if(cur) ok = true;
            ans += (char)(cur%10+'0');
            carry = cur/10;
        }
        reverse(ans.begin(), ans.end());
        if(ok) cout << ans << "\n";
        else cout << "0\n";
    }
}
