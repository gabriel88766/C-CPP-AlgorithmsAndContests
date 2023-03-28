#include <bits/stdc++.h>
// i cant believe ....
using namespace std;
int main(){
 	string s;
  cin >> s;
  bool a = (s[0] == s[s.size()-1]);
  bool b = s.size() & 1;
  if(a^b) cout << "First";
  else cout << "Second";
}