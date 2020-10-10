#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

void sum(string &s,int ep){
    int auxp = ep;
    s[auxp]='0';
    auxp--;
    while(s[auxp]!='0'){
        s[auxp]='0';
        auxp--;
    }
    s[auxp]='1';
}


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s,z;
z = "0";
cin >> s;
z+=s;
int cont=0,ep;
ep  = z.size()-1;
while(!((ep==0)||(ep==1 && z[0]=='0'))){
    if(z[ep]=='0'){
        ep--;
        cont++;
    }else{
        sum(z,ep);
        cont++;
    }
}
cout << cont;
}

