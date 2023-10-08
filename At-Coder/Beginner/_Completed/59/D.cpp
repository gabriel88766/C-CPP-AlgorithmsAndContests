#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int a, b;
  cin >> a >> b;
  if(abs(a-b) <= 1) cout << "Brown\n";
  else cout << "Alice\n";
}