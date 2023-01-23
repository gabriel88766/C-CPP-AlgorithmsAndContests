#include <bits/stdc++.h>
 
using namespace std;
 
int len[1000005];
 
int main(){
string s;
 
int max_ans=-1,cont;
stack<int> openB;
cin >> s;
vector<char> visited(s.size(),false);
 
for(int i=0;i<s.size();i++){
    len[i]=-1;
    if(s[i]=='('){
        openB.push(i);
    }else{
        if(!openB.empty()){
            len[i] = i-openB.top()+1;
            openB.pop();
        }
    }
}
for(int i=(s.size()-1);i>=0;i--){
    if(len[i]>0){
        if(!visited[i]){
            visited[i] = true;
            int j=i;
            int oldlen = len[j];
            while(true){
                int k = j;
                j-=oldlen;
                if(j<0) break;
                if(len[j]<0) break;
                else{
                    visited[j] = true;
                    oldlen = len[j];
                    len[j] += len[k];
                }
            }
        }
    }
}
for(int i=0;i<s.size();i++){
    if(len[i]>max_ans){
        max_ans=len[i];
        cont = 1;
    }else
    if(len[i]==max_ans){
        cont++;
    }
}
if(max_ans!=-1) cout << max_ans << " " << cont;
else cout << "0 1";
 
}