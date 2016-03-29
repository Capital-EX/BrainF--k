#include<stdio.h>#include<stdlib.h> 
#define B break
#define N int
#define I i++
#define T (*t)
#define Q I;B
#define C(x)case(x+43):if(x!=50&&x!=48&&s){Q;}
#define F(x,y,z)if(x){y;}else{z;}
#define W(x)while(x)
#define R return 0;
N main(N a,char*v[]){FILE*f;F(a<2,R,f=fopen(v[1],"r");if(!f)R)N n=65536,*t=calloc(n,sizeof(N)),J[n],j=-1,s=0,i=0,l;char p[n];W((l=fgetc(f))!=EOF)p[i++]=l;i=p[i]=0;W(i<n&&p[i]!=0)switch(p[i]){C(19)t++;Q;C(17)t--;Q;C(0)T++;Q;C(2)T--;Q;C(3)printf("%c",T);Q;C(1)T=getchar();Q;C(48)F(T==0,s++;I,J[++j]=i;I)B;C(50)F(T!=0&&!s,i=J[j];j--,F(s!=0,s--,j--);I)B;default:I;}R}