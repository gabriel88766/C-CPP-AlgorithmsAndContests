#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

char reflect(char c){
    if(c=='b') return 'd';
    if(c=='o') return 'o';
    if(c=='A') return 'A';
    if(c=='d') return 'b';
    if(c=='H') return 'H';
    if(c=='I') return 'I';
    if(c=='M') return 'M';
    /* if(c=='m') return 'm'; idk*/
    if(c=='O') return 'O';
    if(c=='o') return 'o';
    if(c=='p') return 'q';
    if(c=='q') return 'p';
    if(c=='T') return 'T';
    if(c=='U') return 'U';
    if(c=='V') return 'V';
    if(c=='w') return 'w';
    if(c=='W') return 'W';
    if(c=='v') return 'v';
    if(c=='X') return 'X';
    if(c=='x') return 'x';
    if(c=='Y') return 'Y';

    return '*';
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s;
cin >> s;
bool ispalin=true;
int k = s.size()/2;
for(int i=0;i<=k;i++){
    if(s[s.size()-i-1]!=reflect(s[i]))
        ispalin = false;
}
if(ispalin) cout << "TAK";
else cout << "NIE";
}


