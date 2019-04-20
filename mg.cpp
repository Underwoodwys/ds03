#include<stdio.h>
#include<stdlib.h>
#define W 10
int MG[W][W]={  {0},
                {0,1,1,0,1,1,1,0,1,0},
                {0,1,1,0,1,1,1,0,1,0},
                {0,1,1,1,1,0,0,1,1,0},
                {0,1,0,0,0,1,1,1,1,0},
                {0,1,1,1,0,1,1,1,1,0},
                {0,1,0,1,1,1,0,1,1,0},
                {0,1,0,0,0,1,0,0,1,0},
                {0,0,1,1,1,1,1,1,1,0},
                {0}
};//此处用数组表示迷宫
typedef struct SNode{
    int h,l;
    struct SNode *next;//定义栈 用来记录过程 h l 代表横纵坐标
}SNode,*LinkStack;
int Pop(LinkStack &s){//删除函数 吧栈顶元素删除的同时 在迷宫上记录为8
    LinkStack p,q;
    if(!s) return 0;
    MG[s->h][s->l]=8;
    q=s;
    p=s->next;
    s=p;
    free(q);
    return 1;
}
int Push(LinkStack &s,int h,int l){//插入函数 插入一个新的坐标 并且将其对应元素改为9
    LinkStack a;
    a=(LinkStack)malloc(sizeof(SNode));
    a->h=h;a->l=l;a->next=s;
    s=a;
    MG[s->h][s->l]=9;
    return 1;
}
/*int read(LinkStack s){
    if(!s) return 0;
    return MG[s->h][s->l];
}*/

int Panduan(LinkStack &s){//判断栈顶元素是否可通
    if(MG[s->h][s->l+1]==1) {Push(s,s->h,s->l+1);return 1;}
    else if(MG[s->h][s->l-1]==1) {Push(s,s->h,s->l-1);return 1;}
    else if(MG[s->h+1][s->l]==1) {Push(s,s->h+1,s->l);return 1;}
    else if(MG[s->h-1][s->l]==1) {Push(s,s->h-1,s->l);return 1;}
    else {Pop(s);return 0;}
}
int main(void){
    LinkStack s=NULL;
    Push(s,1,1);
/*Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);
Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);
Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);
Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);Panduan(s);*/
while(!(s->h==8&&s->l==8)) {Panduan(s);}
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j)
            printf("%3d",MG[i][j]);
        printf("\n");
    }
printf("\n\n");
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(MG[i][j]==9||MG[i][j]==10) printf("[*]");
            if(MG[i][j]==0) printf("[@]");
            if(MG[i][j]==1||MG[i][j]==8) printf("[ ]");
        }
        printf("\n");
    }

return 0;



}
