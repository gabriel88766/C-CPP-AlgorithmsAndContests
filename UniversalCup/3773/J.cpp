#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b;
	cin >> n >> a >> b;
	string s, t;
	cin >> s >> t;
	array<int, 4> c = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		int k = s[i] - '0' + 2 * (t[i] - '0');
		c[k]++;
	}
	double ans = c[0];
	int A = c[0] + c[2];
	int B = c[0] + c[1];
    vector<double> fx(n+1); 
    fx[0] = 1;
    for(int i=0;i<n;i++){
        fx[i+1] = fx[i];
        fx[i+1] *= (A - a - i);
        fx[i+1] /= A;
        fx[i+1] *= (B - b - i);
        fx[i+1] *= (n - i);
        fx[i+1] /= (i + 1);
    }
    



	ans *= A - a;
	ans /= A;
	ans *= B - b;
	ans /= B;
	cout << fixed << setprecision(18) << n - ans << endl;
}
