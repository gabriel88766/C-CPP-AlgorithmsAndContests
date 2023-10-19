#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
    // some hints, n = 32-__builtin_clz(sizeof a + size of b)
// be a = new Complex[n]; b = new Complex[n]; (free in the end)
// for(int i=0;i<(n+m-1);i++) cout << (ll)round(a[i].x) << " ";
    int k, c, d;
    cin >> k >> c >> d;
    int n = 1 << (32-__builtin_clz(2*k));
    vector<Complex> a(n), b(n);
    for(int i=0;i<c;i++){
        int aux;
        cin >> aux;
        a[aux].x++;
    }
    for(int i=0;i<d;i++){
        int aux;
        cin >> aux;
        b[aux].x++;
    }
    multiply(a, b, n);
    for(int i=2;i<=2*k;i++){
        cout << (ll)round(a[i].x) << " ";
    }
}
