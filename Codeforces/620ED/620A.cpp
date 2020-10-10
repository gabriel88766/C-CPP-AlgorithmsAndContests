#include <bits/stdc++.h>

using namespace std;

int main(){
int a,b,c,d,m,n;
cin >> a >> b >> c >> d;
m = abs(a-c);
n = abs(b-d);
cout << max(m,n);
}
