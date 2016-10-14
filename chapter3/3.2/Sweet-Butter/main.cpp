/*
 ID: miyunlu1
 PROG: butter
 LANG: C++11
 */
//    弗洛伊德会超时，堆加dijkstra优化  最小化堆里用一个数组纪录每条边的位置
#include <iostream>
#include <cstring>
using namespace std;
bool know[801];
int dis[801];
bool cunzai[801];
int inf = 99999999;

int N,P,C;// 500 800 1450
int road[801][801];
int cowIn[501];
int step[801];

typedef pair<int, int> Pair;

struct node{
    int end;
    int weight;
    node* next;
    node(){end = weight = 0;next = NULL;}
    node(int e,int w){end = e;weight = w;next = NULL;}
};
node* linjie[801];

class priorityQueue{
private:
    int currentSize;
    Pair *arr;
    int maxSize;
    
    void doubleSpace();
    void percolateDown(int hole);
public:
    int location[801]; //
    
    priorityQueue(int cap = 1000)
    {arr = new Pair[cap];maxSize = cap;currentSize = 0;}
    ~priorityQueue(){delete []arr;}
    
    bool isEmpty()const {return currentSize == 0;}
    void enQueue(const Pair &x);
    Pair deQueue();
    Pair getHead() const{return arr[1];}
    void decrease(int k, int v);  //将第k个节点的优先级值减少dao v
};
void priorityQueue::enQueue(const Pair &x)
{
    if(currentSize == maxSize-1) doubleSpace();
    //向上过滤
    int hole = ++currentSize;
    for(;hole>1 && x.first < arr[hole/2].first; hole /=2)
    {
        location[arr[hole/2].second] = hole;
        arr[hole] = arr[hole/2];
    }
    
    arr[hole] = x;
    location[x.second] = hole;
}

void priorityQueue::percolateDown(int hole)
{
    int child;
    Pair tmp = arr[hole];
    for(;hole*2<= currentSize;hole = child)
    {
        child = hole * 2;
        if(child != currentSize && arr[child+1].first < arr[child].first) child++;
        if(arr[child].first < tmp.first)
        {
            arr[hole] = arr[child];
            location[arr[child].second] = hole;
        }
        else break;
    }
    arr[hole] = tmp;
    location[tmp.second] = hole;
}

Pair priorityQueue::deQueue()
{
    Pair minItme;
    minItme = arr[1];
    if(currentSize>1){
        arr[1] = arr[currentSize--];
        percolateDown(1);
    }
    else currentSize = 0;
    return minItme;
}

void priorityQueue::doubleSpace()
{
    Pair*tmp = arr;
    maxSize *=2;
    arr = new Pair[maxSize];
    for(int i=0;i<currentSize;++i) arr[i] = tmp[i];
    delete []tmp;
}
void priorityQueue::decrease(int k, int v)
{
    Pair tmp = arr[k];
    tmp.first = v;
    //向上过滤
    int hole = k;
    for(;hole>1 && tmp.first < arr[hole/2].first; hole /=2)
    {
        location[arr[hole/2].second] = hole;
        arr[hole] = arr[hole/2];
    }
    
    arr[hole] = tmp;
    location[tmp.second] = hole;
}

void Dij(int start)
{
    for(int i = 1;i<=P;++i){know[i] = false;cunzai[i] = false;dis[i] = inf;}
    dis[start] = 0;
    priorityQueue que;
    que.enQueue(make_pair(dis[start], start));
    while(! que.isEmpty())
    {
        Pair top = que.deQueue();
        cunzai[top.second] = false;
        
        int now = top.second;
        if(know[now]) continue;
        
        know[now] = true;
        node * pp = linjie[now]->next;
        for(;pp!= NULL; pp = pp->next)
        {
            if(!know[pp->end] && pp->weight + dis[now] < dis[pp->end])
            {
                dis[pp->end] = pp->weight + dis[now];
                if(!cunzai[pp->end]) {que.enQueue(make_pair(dis[pp->end], pp->end));cunzai[pp->end] = true;}
                else que.decrease(que.location[pp->end], dis[pp->end]);
            }
        }
    }
    /*
    cout << "start: "<<start <<endl;
    for(int i = 1;i<=P;++i) cout << dis[i] <<' ';
    cout << endl;
    */
    int num = 0;
    for(int i = 1;i<=N;++i)
    {
        num += dis[cowIn[i]];
    }
    step[start] = num;
}
int main()
{
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    cin >> N >> P >> C;
    for(int i = 1;i <= N;++i) cin >> cowIn[i];
    
    memset(road, -1, sizeof(road));
    for(int i = 1;i<=P;++i) road[i][i] = 0;
    
    for(int i = 0;i<C;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a!=b)
        {
            if(road[a][b] == -1) road[a][b] = road[b][a] = c;
            else {
                int m = min(c,road[a][b]);
                road[a][b] = road[b][a] = m;
            }
        }
    }
    /*
    for(int i = 1;i<=P;++i){
        for(int j = 1;j<=P;++j)cout << road[i][j] <<' ';
        cout << endl;
    }*/
    
    for(int i =1;i<=P;++i){
        linjie[i] = new node();
        node* p = linjie[i];
        for(int j = 1;j<=P;++j)
        {
            if(i == j) continue;
            if(road[i][j] != -1)
            {p->next = new node(j,road[i][j]);p = p->next;}
        }
    }
    /*
    for(int i = 1;i<=P;++i){
        cout <<"i: "<<i <<endl;
        node* p = linjie[i]->next;
        for(;p!=NULL;p=p->next)cout << p->end<<':'<<p->weight<<' ';
        cout << endl;
    }*/
    for(int i = 1;i<=P;++i) Dij(i);
    //for(int i = 1;i<=P;++i) cout << step[i] <<' ';
    //cout << endl;
    int ans = inf;
    for(int i = 1;i<=P;++i) ans = min(ans,step[i]);
    cout << ans <<endl;
    return 0;
}
/*
 20 50 200
 45
 33
 38
 30
 11
 49
 7
 42
 40
 34
 44
 46
 21
 48
 34
 15
 41
 13
 8
 16
 8 28 123
 45 22 19
 34 5 198
 42 18 104
 41 34 33
 27 22 39
 47 43 185
 39 7 178
 16 8 46
 29 8 55
 */
