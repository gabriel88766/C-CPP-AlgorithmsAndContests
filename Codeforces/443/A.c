#include <stdio.h>
 
int main(){
    char c;
    int i;
    int has[26];
    for(i=0;i<26;i++) has[i] = 0;
    do{
        scanf("%c", &c);
        if(c >= 'a' && c <= 'z'){
            has[c-'a'] = 1;
        }
    }while(c != '}');
    int ans = 0;
    for(i = 0; i < 26; i++) if(has[i]) ans++;
    printf("%d\n", ans);
    
}