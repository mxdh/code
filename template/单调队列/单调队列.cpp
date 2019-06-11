const int N_NODE=300000;
class Monotone_Queue
{
public:
	Monotone_Queue()
	{
		n_node=l=r=0;
	}
	inline void add(const int num)
	{
		this->num[n_node]=num;
		push(n_node++);
	}
	inline int pop(const int min_l)
	{
		maint(min_l);
		return num[queue[l]];
	}
private:
	int queue[N_NODE],num[N_NODE],n_node,l,r;
	inline void push(const int k)
	{
		while (r-l&&num[queue[r-1]]>=num[k]) r--;
		queue[r++]=k;
	}
	inline void maint(const int min_l)
	{
		while (queue[l]<min_l) l++;
	}
} monotone_queue;