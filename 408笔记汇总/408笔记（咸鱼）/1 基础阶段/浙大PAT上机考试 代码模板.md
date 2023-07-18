- - - [贪心](#贪心)
        - [二分](#二分)
        - [双指针](#双指针)
        - [最大公约数](#最大公约数)
        - [分数四则运算](#分数四则运算)
        - [素数](#素数)
        - [质因子分解](#质因子分解)
        - [大整数运算](#大整数运算)
        - [优先队列](#优先队列)
        - [静态链表](#静态链表)
        - [DFS](#dfs)
        - [BFS](#bfs)
        - [二叉树](#二叉树)
        - [二叉树静态实现](#二叉树静态实现)
        - [树的静态写法](#树的静态写法)
        - [二叉查找树](#二叉查找树)
        - [并查集](#并查集)
        - [堆](#堆)
        - [图遍历](#图遍历)
        - [最短路径](#最短路径)
        - [拓扑排序](#拓扑排序)
- [莫忘看二维码](#莫忘看二维码)



### 贪心

```
//区间选点贪心问题
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Interval{
    int x,int y;
}I[maxn];
int main()
{
    int n;
    while(scanf("%d",&n),n!=0){
        for(int i=0;i<n;i++){
            scanf("%d%d",&I[i].x,&I[i].y]);
        }
        sort(I,I+n,cmp);
        int ans=1,lastx=I[0].x;
        for(int i=1;i<n;i++){
            if(I[i].y<=lastx){
                lastx=I[i].x;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

### 二分

```
//二分查找
#include<stdio.h>
int binarySearch(int A[],int left,int right,int x){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(A[mid]=x)return mid;
        else if(A[mid]>x){
            right=mid-1;
        }else {
            left==mid+1;
        }
    }
    return -1;//查找失败
}
//寻找有序序列第一个满足某条件的元素的位置模板
int solve(int left,int right){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(条件成立){
            right=mid;
        }else {
            left=mid+1;
        }
    }
    return left;
}
```

### 双指针

```
//双指针合并两序列
int merge(int A[],int B[],int C[],int n,int m){
    int i=0,j=0,index=0;
    while(i<n&&j<m){
        if(A[i]<=B[i]){
            C[index++]=A[i++];
        }else{
            C[index++]=B[j++];
        }
    }
    while(i<n)C[index++]=A[i++];
    while(j<m)C[index++]=B[j++];
    return index;
}
```

### 最大公约数

```
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
```

### 分数四则运算

```
//分数表示
struct Fraction(){
    int up,down;
};
//分数的化简
Fraction reduction(Fraction result){
    if(result.down<0){
        result.up=-result.up;
        result.down=-result.down;
    }
    if(result.up==0){
        result.down=1;
    }else{
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}
//加法
Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down+f2.up*f1.down;
    result.down=f1.down*f2.down;
   	return reduction(result);
}
//减法
Fraction minu(Fraction f1,Fraction f2){
    Fraction result;
    recult.up=f1.up*f2.down-f2.up*f1.down;
    result.down=f1.down*f2.down;
    return reduction(result);
}
//乘法
Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down;
    result.down=f1.down*f2.up;
    return reduction(result);
}
//输出
void showresult(Fraction r){
    r=reduction(r);
    if(r.down==1)printf("%lld",r.up);
    else if(abs(r.up)>abs(r.down)){
      	printf("%d %d/%d",r.up/r.down,abs(r.up)%r.down,r.down);
    }else{
        printf("%d/%d",r.up,r.down);
    }
}
```

### 素数

```
int isprime(int a){
	if(n<=1)return 0;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return 0;
	}
	return 1;
}//如果a很大，接近n，会溢出，应采用开根号的办法  int sqr=(int)sqrt(1.0*n);
用此方法打印素数表 n最多为10的5次方
//素数筛法打表
int prime[maxn],pnum=0;
int p[maxn]={0};
void find_prime(){
for(int i=2;i<maxn;i++){
		if(p[i]==0){
			prime[pnum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				p[j]=1;
			}
		}
	}
}
```

### 质因子分解

```
struct factor{
    int c,cnt;
}fac[10];
int sqr=(int)sqrt(1.0*n);
for(int i=0;i<pNum&&prime[i]<=sqr;i++){    //pNum为素数表的容量
    if(n%prime[i]==0){
        fac[num].x=prime[i];
        fac[num].cnt=0;
        while(n%prime[i]==0){
            fac[num].cnt++;
            n/=prime[i];
        }
        num++;
    }
    if(n==1)break;
}
if(n!=1){
    fac[num].x=n;
    fac[num++].cnt=1;
}
```

### 大整数运算

```
struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
//需要初始化
//字符串读入
bign change(char str[]){
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-i-1]-'0';
    }
    return a;
}
//比较大小
int compare(bign a,bign b){
    if(a.len>b.len)return 1;//a大
    else if(a.len<b.len)return -1;
    else{
        for(int i=a.len-1;i>=0;i--){
            if(a.d[i]>b.d[i])return 1;
            else if(a.d[i]<b.d[i])return -1;
        }
        return 0;//相等
    }
}
//高精度加法
bign add(bign a,bign b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len||i<b.len;i++){
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0){
        c.d[c.len++]=carry;
    }
    return c;
}
//高精度减法
bign sub(bign a,bign b){
    bign c;
    for(int i=0;i<a.len||i<b.len;i++){
        if(a.d[i]<b.d[i]){
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.len++]=a.d[i]-b.d[i];
    }
    while(c.len-1>=1&&c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}//调用之前需要先判断两个数的大小，交换两个变量
//高精度与低精度的乘法
bign muti(bign a,bign b){
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++){
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0){
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    return c;
}
//高精度与低精度的除法
bign divide(bign a,int b,int& r){
    bign c;
    c.len=a.len;
    for(int i=a.len-1;i>=0;i--){
        r=r*10+a.d[i];
        if(r<b)c.d[i]=0;
        else{
            c.d[i]=r/b;
            r=r%b;
        }
    }
    while(c.len-1>=1&&c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}
```

邻接表存储图外层索引与邻接矩阵一样，指向对应的点，内层索引则只表示个数，要找一个路径的第二点要进入图结构体里面找

对一些数据量大的题目可能不是用常规思路解决的，先打一下表找找规律。

### 优先队列

```
//大元素优先
priority_queue<int,vector<int>,less<int>>q;等价于priority_queue<int>q;
//小元素优先
priority_queue<int,vector<int>,greater<int>>q;
//结构体排序设置
struct fruit{
    string name;
    int price;
    friend bool operator < (fruit f1,fruit f2){
        return f1.price<f2.price;                //价高优先级高 跟sort的cmp相反
    }
}
priority_queue<fruit>q;
```

### 静态链表

```
//定义静态链表
struct Node{
    int add;
   	typename data;
   	int next;
    XXX;      //节点的某个性质  一般给出的节点会有无效节点，需要遍历一遍再根据这个性质进行排序
}node[100010];
//初始化
for(int i=0;i<maxn;i++){
    node[i].XXX=0;
}
int p=begin,count=0;   //比如计数
while(p!=-1){
    XXX=1;
    count++;
    p=node[p].next;
}
```

### DFS

```
vector<int>temp,ans;
void DFS(int index,int nowK,int sum,int sumSqu){
    if(nowK==k&&sum==x){
        if(sumSqu>maxSumSqu){
            maxSumSqu=sumSqu;
            ans=temp;
        }
        return;
    }
    if(index==n||nowK>k||sum>x)return;
    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+S[index],sumSqu+A[index]*index);
    temp.pop_back();
    DFS(index+1,nowK,sum,sumSqu);
}
```

### BFS

```
void BFS(int s){
    queue<int>q;
    q.push(s);
    设置已入队;
    while(!q.empty()){
       取出队首元素top;
       访问队首元素top;
       将队首元素出队;
       将top的下一层结点中未曾入队的结点全部入队，并设置为已入队;
    }
}
```

### 二叉树

```
strcut node{
    typename data;
    node* lchild;
    node* rchild;
};
node* root=NULL;
//新建节点
node* newnode(int v){
    node* Node=new node;
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node;
}
//查找
void search(node* root,int x,int newdata){
    if(root==NULL){
        return;
    }
    if(root->data==x){
        root->data=newdata;
    }
    search(root->lchild,x,newdata);
    search(root->rchild,x,newdata);
}
//插入
void insert(node* &root,int x){
    if(root==NULL){
        root=newnode(x);
        return;
    }
    if(......){
        insert(root->lchild,x);
    }else{
      	insert(root->rchild,x);
    }
}
//建立
node* Create(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
//先序遍历
void preorder(node* root){
    if(root==NULL){
        return;
    }
    printf("%d\n",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
//层序遍历
void layerorder(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* now=q.front();
        q.pop();
        printf("%d\n",now->data);
        if(now->lchild!=NULL)q.push(now->lchild);
        if(now->rchild!=NULL)q.push(now->rchild);
    }
}
//记录层次层序遍历
struct node{
    int data;
    int layer;
    node* lchild;
    node* rchild;
};
void layerorder(node* root){
    queue<node*>q;
    root->layer=1;
    q.push(root);
    while(!q.empty()){
     	node* now=q.front();
        q.pop();
        printf("%d ",now->data);
        if(now->lchild!=NULL){
            now->lchild->layer=now->layer+1;
            q.push(now->lchild);
        }
        if(now->rchild!=NULL){
            now->rchild->layer=now->layer+1;
            q.push(now->rchild);
        }
    }
}
//前中序构建二叉树
node* create(int prel,int prer,int inl,int inr){
    if(prel>prer){
        return NULL;
    }
    node* root=new node;
    root->data=pre[prel];
    int k=0;
    while(in[k]!=pre[prel])k++;
    int numleft=k-inl;
    root->lchild=create(prel+1,prel+numleft,inl,k-1);
    root->rchild=create(prel+numleft+1,prer,k+1,inr);
    return root;
}
```

### 二叉树静态实现

```
//定义
strcut node{
   	typename data;
    int lchild,rchild;
}Node[maxn];
// 建立新节点
int index=0;
int newNode(int v){
    Node[index].data=v;
    Node[index].lchild=-1;
    Node[index].rchild=-1;
    return index++;//指针返回的是节点指针
}
//查找
void search(int root,int x,int newdata){
    if(root==-1){
        return;
    }
    if(Node[root].data==x){
        Node[root].data=newdata;
        return;
    }
    search(Node[root].lchild,x,newdata);
    search(Node[root].rchild,x,newdata);
}
//插入
void insert(int &root,int x){
   	if(root==-1){
        root=newnode(x);
        return;
    }
    if(-------){
        insert(Node[root].lchild,x);
    }
    else{
        insert(Node[root].rchild,x);
    }
}
//建立
int Create(int data[],int n){
    int root=-1;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
//先序遍历
void preorder(int root){
    if(root==-1){
        return;
    }
    printf("%d\n",Node[root].data);
    preorder(Node[root].lchild);
    preorder(Node[root].rchild);
}
//层序遍历
void layerorder(int root){
    queue<int>q;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        printf("%d\n",Node[now].data);
        if(Node[now].lchild!=-1)q.push(Node[now].lchild);
        if(Node[now].rchild!=-1)q.push(Node[now].rchild);
    }
}
```

### 树的静态写法

```
//定义节点
struct node{
    typename data;
    vector child;
}Node[maxn];
//新建节点
int index=0;
int newNode(int v){
    Node[index].data=v;
    Node[index].child.clear();
    return index++;
}
//层序遍历
void Layerorder(int root){
    queue<int>q;
    q.push(root);
    Node[root].layer=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        printf("%d\n",Node[now].data);
        for(int i=0;i<Node[now].child.size();i++){
            Node[Node[now].child[i]].layer=Node[now].layer+1;
            q.push(Node[now].child[i]);
        }
    }
}
```

**对所有合法的DFS求解过程，都可以把它画成树的形式**

### 二叉查找树

```
//查找
void search(node* root,int x){
    if(root==NULL){
        return;
    }
    if(x==root->data){
        printf("%d\n",root->data);
    }
   	else if(x<root->data){
        search(root->lchild,x);
    }
    else if(x>root->data){
        search(root->rchild,x);
    }
}
//插入
省略;
//建立
node* Create(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
//寻找最大权值节点
node* findmin(node* root){
    while(root->lchild!=NULL){
      	root=root->lchild;
    }
    return root;
}
//删除节点
void deletenode(node* &root,int x){
    if(root==NULL)return;
    if(root->data==x){
        if(root->lchild==NULL&&root->rchild==NULL){
            root=NULL;
        }else if(root->lchild!=NULL){
            node* pre=findmax(root->lchild);
            root->data=pre->data;
            deletenode(root->lchild,pre->data);
        }else if(root->rchild!=NULLL){
            node* next=finmin(root->rchild);
            root->data=next->data;
            deletenode(root->rchild,next->data);
        }
    }else if(root->data>x)deletenode(root->lchild,x);
    else if(root->data<x)deletenode(root->rchild,x);
}
```

### 并查集

```
int father[N];
for(int i=1;i<=N;i++){
	father[i]=i;
}
//查找
int findfather(int x){
	if(x==father[x])return x;
	else return findfather(father[x]);
}
//查找加路径压缩
int findfather(int v){
	if(v==father[v])return v;
	else{
		int F=findfather(father[v]);
		father[v]=F;
		return F;
	}
}
//合并
void Union(int a,int b){
	int fA=findfather(a);
	int fB=findfather(b);
	if(fA!=fB){
		father[fA]=fB;                   //可以通过比较让小的值作为父亲，则最后的并查集的父节点为整个并查集的最小值
	}
}
```

### 堆

```
const int maxn=100;
int heap[maxn];
//向下调整
void downAdjust(int low,int high){
    int i=low,j=i*2;
    while(j<=high){
        if(j+1<=high&&heap[j+1]>heap[j]){
            j=j+1;
        }
        if(heap[j]>heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
}
//建堆
void createheap(){
    for(int i=n/2;i>=1;i--){
        downAdjust(i,n);
    }
}
//删除堆顶元素
void deletetop(){
    heap[1]=heap[n--];
    downAdjust(1,n);
}
//向上调整
void upAdjust(int low,int high){
    int i=high,j=i/2;
    while(j>=low){
        if(heap[j]<heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i/2;
        }else{
            break;
        }
    }
}
//添加元素
void insert(int x){
    heap[++n]=x;
    upAdjust(1,n);
}
//堆排序
void heapSort(){
    createheap();
    for(int i=n;i>1;i--){
        swap(heap[i],heap[1]);
        downAdjust(1,i-1);
    }
}
```

### 图遍历

```
//遍历图伪代码
DFS(u){
    vis[u]=true;
    for(从u出发能到达的所有顶点v){
        if(vis[v]==0){
            DFS(v);
        }
    }
}
DFSTrave(G){
    for(G的所有顶点){
        if(vis[u]==0){
            DFS(u);
        }
    }
}
//邻接矩阵版
int n;
int G[maxn][maxn];
int vis[maxn]={0};
void DFS(int u,int depth){
    vis[u]=1;
    for(int v=0;v<n;v++){
        if(vis[v]==0&&G[u][v]!=INF){
            DFS(v,depth+1);
        }
    }
}
void DFSTrave(){
    for(int u=0;u<n;u++){
        if(vis[u]==0){
          	DFS(u,1);
        }
    }
}
//BFS邻接矩阵版
void BFS(int u){
    queue<int>q;
    q.push(u);
    vis[u]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(vis[v]==0&&G[u][v]!=INF){
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
......
```

### 最短路径

```
//邻接矩阵Dijkstra 最短距离
int n;
int G[maxn][maxn],d[maxn];
int vis[maxn];
void Dijkstra(int s){
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
    	int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==0&&d[j]<min){
                u=j;
                min=d[j];
            }
        }
        if(u==-1)return;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(vis[v]==0&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
                d[v]=d[u]+G[u][v];
            }
        }
    }
}
//最短路径 Dijkstra+DFS
const int maxn=1010;
const int INF=1000000000;
vector<int>pre[maxn];
int n;
int G[maxn][maxn],d[maxn];
int vis[maxn];
void Dijkstra(int s){
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==0&&d[j]<min)[
                u=j;
                min=d[j];
            ]
        }
        if(u==-1)return;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(vis[v]==0&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optvalue=0;
vector<int>path,temppath;
void DFS(int v){
    if(v==s){
        temppath.push_back(v);
//需要自己写的地方
//         点权
        int value=0;
        for(int i=temppath.size()-1;i>=0;i--){
            int id=temppath[i];
            value+=w[id];
        }
//         边权
        int value=0;
        for(int i=temppath.size()-1;i>0;i--){
            int id1=temppath[i],id2=temppath[i-1];
            value+=G[id1][id2];
        }
//         
        if(value>optvalue){
            optvalue=value;
            path=temppath;
        }
        temppath.pop_back;
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    temppath.pop_back();
}
//输出路径时要逆序输出
```

### 拓扑排序

```
//拓扑排序
vector<int>G[maxn];
int n,m,indegree[maxn];
bool topologicalsort(){
    int num=0;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        //访问
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        G[u].clear();     //可不写，看情况
        num++;
    }
    if(num==n)return ture;
    else return false;
}
```

