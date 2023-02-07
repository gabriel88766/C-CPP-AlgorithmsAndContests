#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int t,curx=0,cury=0,cont;
pair<int,int> lastpos,curpos;
char pos;
string allpos;
cin >> t;
 
while(t--){
    map<pair<pair<int,int>,pair<int,int>>,int> mp;
    lastpos = make_pair(0,0);
    cin >> allpos;
    cont=0;
    curx=0,cury=0;
    for(int i=0;i<allpos.size();i++){
        if(i!=0) lastpos=curpos;
        pos = allpos[i];
        if(pos=='N'){
            cury++;
        }else if(pos=='S'){
            cury--;
        }else if(pos=='W'){
            curx--;
        }else{
            curx++;
        }
        curpos = make_pair(curx,cury);
        if(mp[make_pair(lastpos,curpos)]||mp[make_pair(curpos,lastpos)]) cont++;
        else{
            mp[make_pair(lastpos,curpos)]++;
            mp[make_pair(curpos,lastpos)]++;
            cont+=5;
        } 
    }
    cout << cont << endl;
    
}
 
    
    
}