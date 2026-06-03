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
	int n;
	cin >> n;
	string ans;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int x = s[0] - 'a';
		if(x <= 2) ans += '2';
		else if(x <= 5) ans += '3';
		else if(x <= 8) ans += '4';
		else if(x <= 11) ans += '5';
		else if(x <= 14) ans += '6';
		else if(x <= 18) ans += '7';
		else if(x <= 21) ans += '8';
		else ans += '9';
	}
	cout << ans << "\n";
}

