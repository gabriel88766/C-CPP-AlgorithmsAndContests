#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1009; //1e9+7
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


vector<Complex> calc(vector<int> v, int sum){
    assert(sum != 0);
    int n = 1 << (32-__builtin_clz(sum));
    if(v.size() == 1){
        vector<Complex> ans(n);
        for(int i=0;i<=v[0];i++) ans[i].x = 1;
        return ans; 
    }else if(v.size() == 2){
        vector<Complex> a(n), b(n);
        for(int i=0;i<=v[0];i++) a[i].x = 1;
        for(int i=0;i<=v[1];i++) b[i].x = 1;
        multiply(a, b, n);
        for(int i=0;i<n;i++){
            a[i].x = ((ll)round(a[i].x)) % MOD;
        }
        return a;
    }else{
        vector<int> v1, v2;
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<v.size();i++){
            if(sum1 <= sum2){
                sum1 += v[i];
                v1.push_back(v[i]);
            }else{
                sum2 += v[i];
                v2.push_back(v[i]);
            }
        }
        auto x1 = calc(v1, sum1);
        auto x2 = calc(v2, sum2);
        vector<Complex> a(n), b(n);
        for(int i=0;i<x1.size();i++) a[i].x = x1[i].x;
        for(int i=0;i<x2.size();i++) b[i].x = x2[i].x;
        multiply(a, b, n);
        for(int i=0;i<n;i++){
            a[i].x = ((ll)round(a[i].x)) % MOD;
        }
        return a;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m+1, 0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> v;
    for(int i=1;i<=m;i++){
        if(cnt[i]) v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    auto ans = calc(v, n);
    cout << (ll)(round(ans[k].x)) << "\n";

}
