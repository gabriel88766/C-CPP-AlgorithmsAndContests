#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1e5;
struct Complex {
    double x, y;
    Complex() : x(0), y(0) {}
    Complex(double a, double b=0) : x(a), y(b) {}

    Complex operator/=(double k) { x/=k; y/=k; return (*this); }
    Complex operator*(Complex a) const { return Complex(x*a.x - y*a.y, x*a.y + y*a.x); }
    Complex operator+(Complex a) const { return Complex(x+a.x, y+a.y); }
    Complex operator-(Complex a) const { return Complex(x-a.x, y-a.y); }
};

void fft(vector<Complex> &a, int n, int s) {
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
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w = wn*w;
            }
        }
    }
}

void multiply(vector<Complex> &a, vector<Complex> &b, int n) {
    fft(a,n,1);
    fft(b,n,1);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fft(a,n,-1);
    for (int i = 0; i < n; i++) a[i] /= n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    ll c0 = 0;
    ll a0 = 0;
    int p = 0;
    vector<Complex> a, b;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1'){
            a.push_back({c0 + 1, 0});
            a0 += (c0 * (c0+1))/2;
            c0 = 0;
        }else c0++;
    }
    a0 += (c0 * (c0+1))/2;
    a.push_back({c0+1, 0});
    int xs = a.size() - 1;
    b.resize(xs);
    for(int i=0;i<a.size();i++){
        b.push_back(a[i]);
    }
    reverse(a.begin(), a.end());
    int m = a.size() + b.size() + 2;
    int n = 1;
    while(n < m) n *= 2;
    a.resize(n), b.resize(n);
    multiply(a, b, n);
    vector<ll> ans;
    for(int i=xs;i<2*xs;i++) ans.push_back(round(a[i].x));
    ans.push_back(a0);
    reverse(ans.begin(), ans.end());
    assert(ans.size() <= s.size() + 1);
    while(ans.size() != s.size() + 1) ans.push_back(0);
    for(auto &x: ans) cout << x << " ";
    cout << "\n";
}
