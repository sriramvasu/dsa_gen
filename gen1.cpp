#include "iostream"
#include "vector"
#include "list"

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
		if(nnodes==0)cout<<"empty\n";
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
			nnodes++;
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
        if(index==1 && nnodes==1)
        {
        	delete head;
        	head=NULL;
        	tail=NULL;
        }
        else if(index==1)
        {
            head=p->next;
            head->prev=NULL;
            delete p;
        }
        else if(index==nnodes)
        {
            tail=q->prev;
            tail->next=NULL;
            delete q;
        }
        else
        {
            for(int i=1;i<index;i++)p=p->next;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
        }  
        nnodes--;
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
                queue.add_node(q->data);
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

template <class T> class Graph1
{
public:
	vector<list<int>> nods;
	int nnodes;
	Graph1(int n)
	{
		nnodes=n;
		nods.resize(n);

	}
	void add_edge(int u, int v)
	{
		nods[u].push_back(v);
		nods[v].push_back(u);
	}
	vector<int> shortest_reach(int startid)
    {
        vector<int> shortest_path(nnodes,-1);
        vector<int> status(nnodes,-1);

        list<int> queue;
        queue.push_back(startid);
        status[startid]=0;
        shortest_path[startid]=0;
        while(!queue.empty())
        {
        	int id=queue.front();
        	queue.pop_front();
        	list<int>::iterator q=nods[id].begin();
            while(q!=nods[id].end())
            {
                if(status[*q]==-1)
                {
                	queue.push_back(*q);
                	status[*q]=0;
                	shortest_path[*q]=shortest_path[id]+6;
                }
                q++;

                
            }
            status[id]=1;
        }
        shortest_path.erase(shortest_path.begin()+startid);
		return shortest_path;
    }


};
void print_list(list<int> l)
{
	list<int>::iterator a=l.begin();
	while(a!=l.end())
	{
		cout<<*a<<"\n";
		a++;
	}
}
int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph<int> graph(n);
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
            
                cout << distances[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


