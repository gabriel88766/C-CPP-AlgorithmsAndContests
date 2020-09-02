#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
long long int n,m,q,x,y;
cin >> n >> m >> q;
x = n/q;
if(n%q) x++;
y = m/q;
if(m%q) y++;
cout << x*y;


}
