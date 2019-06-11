class BIT
{
public:
	BIT(int n):tr(new int[n+1])
	{
		this->n=n;
		memset(tr,0,(n+1)*sizeof *tr);
	}
	void change(int k,int num)
	{
		for (;k<=n;k+=low_bit(k)) tr[k]+=num;
	}
	int get_sum(int k)
	{
		int sum=0;
		for (;k;k-=low_bit(k)) sum+=tr[k];
		return sum;
	}
private:
	int low_bit(int num)
	{
		return num&(num^(num-1)); //num&(-num)
	}
	int n,*tr;
};