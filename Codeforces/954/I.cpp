#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Complex {
    long double x, y;
    Complex() : x(0), y(0) {}
    Complex(long double a, long double b=0) : x(a), y(b) {}

    Complex operator/=(long double k) { x/=k; y/=k; return (*this); }
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
    //freopen("in", "r", stdin); //test input
    int n = 1 << 18;
    vector<Complex> a(n), b(n);
    vector<int> ans(n);
    string s, t;
    cin >> s >> t;
    int fi = t.size() - 1;
    int li = s.size() - 1;
    for(int i=0;i<26;i++){
        char c = 'a' + i;
        for(int j=0;j<n;j++) a[j].x = a[j].y = b[j].x = b[j].y = 0;
        for(int j=0;j<s.size();j++){
            if(c == s[j]){
                a[j].x = 1;
            }
        }
        for(int j=0;j<t.size();j++){
            int ind = t.size() - j - 1;
            if(c == t[j]){
                b[ind].x = 1;
            }
        }
        multiply(a, b, n);
        cout << c << " ";
        for(int j=fi;j<=li;j++){
            cout << a[j].x << " ";
            ans[j] += (ll)round(a[j].x);
        }
        cout << "\n";
    }
    for(int j=fi;j<=li;j++) cout << t.size() - ans[j] << " ";
}
