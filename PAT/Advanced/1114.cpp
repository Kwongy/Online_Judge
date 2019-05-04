#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fa[10010],mem[10010]={0},area[10010]={0},estate[10010]={0};
bool exist[10010];
int findfather(int x){
    int a=x;
    while(fa[x]!=x)
        x=fa[x];
    while(a!=fa[a]){
        int z=a;
        a=fa[a];
        fa[z]=x;
    }
    return x;
}
void Union(int a,int b){
    int faa=findfather(a);
    int fab=findfather(b);
    if(faa<fab){
		area[faa]+=area[fab];
        estate[faa]+=estate[fab];
		estate[fab]=0;
		area[fab]=0;
        fa[fab]=faa;
	}
    else if(faa>fab){
		area[fab]+=area[faa];
        estate[fab]+=estate[faa];
		estate[faa]=0;
		area[faa]=0;
        fa[faa]=fab;
    }
}
typedef struct 
{
    int id,num;
    double avg_set,avg_area;
}family;
int cmp(family a,family b){
    if(a.avg_area!=b.avg_area)
        return a.avg_area>b.avg_area;
    return a.id<b.id;
}
int main(){
	vector<family>v;
    for(int i=0;i<10010;i++)
        fa[i]=i;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int id,id_f,id_m;
        scanf("%d %d %d",&id,&id_f,&id_m);
        exist[id]=true;
        if(id_m!=-1){
            Union(id,id_m);
            exist[id_m]=true;
        }
        if(id_f!=-1){
            Union(id,id_f);
            exist[id_f]=true;
        }
        int num_c;
        scanf("%d",&num_c);
        for(int j=0;j<num_c;j++){
            int id_c;
            scanf("%d",&id_c);
            if(id_c!=-1){
                Union(id,id_c);
                exist[id_c]=true;
            }
        }
        int estatetemp,areatemp;
        scanf("%d %d",&estatetemp,&areatemp);
        int idfa=findfather(id);
        estate[idfa]+=estatetemp;
        area[idfa]+=areatemp;
    }
    for(int i=0;i<10010;i++){
        if(exist[i]==true)
            mem[findfather(i)]++;
    }
    int numfamily=0;
    for(int i=0;i<10010;i++){
        if(exist[i]==true&&mem[i]!=0){
            numfamily++;
            family temp;
            temp.id=i;temp.num=mem[i];
            temp.avg_set=1.0*estate[i]/temp.num;
            temp.avg_area=1.0*area[i]/temp.num;
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(),cmp);
    printf("%d",numfamily);
    for(int i=0;i<numfamily;i++){
        printf("\n%04d %d %.3f %.3f",v[i].id,v[i].num,v[i].avg_set,v[i].avg_area);
    }
	system("pause");
}
