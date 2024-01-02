//It's working, but not the best way
//15 FFT instead of 3 for each convolution
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
        Complex wn = Complex(cosl(s*2*PI/M), sinl(s*2*PI/M));
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

void multMod(vector<ll> &a, vector<ll> &b, int n){
    //split 2^20 * x3 + 2^10 * x2 + x1
    const int MID1 = 1 << 10, MID2 = 1 << 20;
    vector<Complex> a3(n), a2(n), a1(n), b3(n), b2(n), b1(n);
    for(int i=0;i<n;i++){
        a3[i].x = a[i] / MID2;
        a2[i].x = (a[i] / MID1) % MID1;
        a1[i].x = a[i] % MID1;
        b3[i].x = b[i] / MID2;
        b2[i].x = (b[i] / MID1) % MID1;
        b1[i].x = b[i] % MID1;
    }
    fft(a1, n, 1);
    fft(a2, n, 1);
    fft(a3, n, 1);
    fft(b1, n, 1);
    fft(b2, n, 1);
    fft(b3, n, 1);
    auto a11 = a1;
    auto a12 = a1;
    auto a13 = a1;
    auto a21 = a2;
    auto a22 = a2;
    auto a23 = a2;
    auto a31 = a3;
    auto a32 = a3;
    auto a33 = a3;
    for(int i=0;i<n;i++){
        a11[i] = a11[i] * b1[i];
        a12[i] = a12[i] * b2[i];
        a13[i] = a13[i] * b3[i];
        a21[i] = a21[i] * b1[i];
        a22[i] = a22[i] * b2[i];
        a23[i] = a23[i] * b3[i];
        a31[i] = a31[i] * b1[i];
        a32[i] = a32[i] * b2[i];
        a33[i] = a33[i] * b3[i];
    }
    fft(a11, n, -1);
    fft(a12, n, -1);
    fft(a13, n, -1);
    fft(a21, n, -1);
    fft(a22, n, -1);
    fft(a23, n, -1);
    fft(a31, n, -1);
    fft(a32, n, -1);
    fft(a33, n, -1);
    for (int i = 0; i < n; i++){
        a11[i] /= n;
        a12[i] /= n;
        a13[i] /= n;
        a21[i] /= n;
        a22[i] /= n;
        a23[i] /= n;
        a31[i] /= n;
        a32[i] /= n;
        a33[i] /= n;
    }
    ll aux = (1LL << 40) % MOD;
    for(int i=0;i<n;i++){
        ll r11 = (ll)round(a11[i].x) % MOD;
        ll r12 = (ll)round(a12[i].x) % MOD;
        ll r13 = (ll)round(a13[i].x) % MOD;
        ll r21 = (ll)round(a21[i].x) % MOD;
        ll r22 = (ll)round(a22[i].x) % MOD;
        ll r23 = (ll)round(a23[i].x) % MOD;
        ll r31 = (ll)round(a31[i].x) % MOD;
        ll r32 = (ll)round(a32[i].x) % MOD;
        ll r33 = (ll)round(a33[i].x) % MOD;
        a[i] = r11 + (r12 + r21) * (1 << 10) + (r13 + r22 + r31) * (1 << 20) + (r32 + r23) * (1 << 30) + aux*r33;
        a[i] %= MOD; 
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a1, a2;
    cin >> a1 >> a2;
    int n = 1;
    while(n < a1+a2) n*= 2;
    assert(n <= (1 << 20));
    vector<ll> a(n), b(n);
    for(int i=0;i<a1;i++) cin >> a[i];
    for(int i=0;i<a2;i++) cin >> b[i];
    
    multMod(a, b, n);
    for(int i=0;i<a1+a2-1;i++) cout << a[i] << " ";
    cout << "\n";
}
