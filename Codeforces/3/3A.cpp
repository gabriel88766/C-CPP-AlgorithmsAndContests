#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7, MOD2 = 2e9+11;
const int N = 1e5+5;
//vector<vector<int>> matrix(row,vector<int>(col));
// cout << std::setprecision(10) << std::fixed << variableLD;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
  int b,d;
  char a,c;
  cin >> a >> b >> c >> d;
  int k1,k2,r;
  k1 = a-c;
  k2 = b-d;
  k1 = max(k1,-k1);
  k2 = max(k2,-k2);
  r = max(k1,k2);
  cout << r << endl;
  while(!(a==c && b==d)){
     if(a>c && b>d){
        cout << "LD" << endl;
        a--;
        b--;
     }
     if(a<c && b>d){
        cout << "RD" << endl;
        a++;
        b--;
     }
     if(a==c && b>d){
        cout << "D" << endl;
        b--;
     }
     if(a>c && b<d){
        cout << "LU" << endl;
        a--;
        b++;
     }
     if(a<c && b<d){
        cout << "RU" << endl;
        a++;
        b++;
     }
     if(a==c && b<d){
        cout << "U" << endl;
        b++;
     }
     if(a<c && b==d){
        cout << "R" << endl;
        a++;
     }
     if(a>c && b==d){
        cout << "L" << endl;
        a--;
     }
  }

  return 0;
}
