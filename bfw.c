#include <stdio.h>
#define C case
#define B break
#define F fgetc
#define S 30000
#define U(x) while(!(x))
int main(int c,char**v){unsigned char t[S]={0};FILE*f=fopen(v[1],"rb");
for(int i=0,p=0,d=0;(i=F(f))!=EOF;)switch(i){C'+':t[p]++;B;C'-':t[p]--;B; C'.':putchar(t[p]);B;
C'[':if(t[p]==0){U((i==']')&&(--d==0)){d=(i=='[')?d+1:d;i=F(f);}}B; C',':t[p]=getchar();B;
C']':if(t[p]!=0){U((i=='[')&&(--d==0)){d=(i==']')?d+1:d;fseek(f,-2,SEEK_CUR);i=F(f);}}B;
C'>':p=(p==S-1)?0:p+1;B;C'<':p=(p==0)?S-1:p-1;B;}}