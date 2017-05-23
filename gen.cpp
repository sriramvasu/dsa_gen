#include "iostream"
#include "vector"
using namespace std;

template <class T> struct node
{
    node* next;
    node* prev;
    T data;
};
template <class T>class ll
{
public:
    int nnodes;
    node<T>* head;
    node<T>* tail;
    ll()
    {
        nnodes=0;
        tail=head;
    }
    void print_list()
    {
        node<T>* p=head;
        while(p!=NULL)
        {
            cout<<p->data;
            p=p->next;
        }
    }
    void add_node(T dat)
    {
        node<T>* n=new node<int>;
        if(nnodes==0)
        {
            nnodes++;
            head=n;
            tail=n;
            n->next=NULL;
            n->prev=NULL;
            n->data=dat;
        }
        else
        {
            n->data=dat;
            tail->next=n;
            n->next=NULL;
            n->prev=tail;
            tail=n;
        }
    }
    void delete_node(int index)
    {
        node<T>* p=head;
        node<T>* q=tail;
        if(index==1)
        {
            head=p->next;
            delete p;
        }
        else if(index==nnodes)
        {
            tail=q->prev;
            delete q;
        }
        else
        {
            for(int i=1;i<index;i++)p=p->next;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
        }  
        
    }
    
};
template <class T> class Graph
{
public:
    ll<int>* nods;
    int nnodes;
    Graph(int n)
    {
        nnodes=n;
        nods=new ll<int>[n];

    }
    void add_edge(int u, int v)
    {
        nods[u].add_node(v);
        nods[v].add_node(u);
    }
    vector<int> shortest_reach(int startid)
    {
        vector<int> shortest_path(nnodes,-1);
        ll<int> queue;
        queue.add_node(startid);
        vector<int> status(nnodes,-1);
        while(queue.head!=NULL)
        {
            node<int>* p=queue.head;
            node<int>* q=nods[p->data].head;
            while(q!=NULL)
            {
                queue.add_node(q->next);
                status[q->data]=0;
                shortest_path[q->data]=shortest_path[p->data]+1;
                q=q->next;
            }
            status[p->data]=1;
            queue.delete_node(p->data);
        }


        return shortest_path;
    }

};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
