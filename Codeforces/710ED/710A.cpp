#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int freedom=0;
char a;
int b;

cin >> a >> b;

if(a>'a') freedom++;
if(a<'h') freedom++;
if(b>1) freedom++;
if(b<8) freedom++;

if(freedom==2) cout << 3;
if(freedom==3) cout << 5;
if(freedom==4) cout << 8;


}
