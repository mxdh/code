inline int pow(const int base,const int exp)
{
	int ret=1,tmp1=base,tmp2=exp;
	for (; tmp2; tmp1=(ll)tmp1*tmp1%D)
		if (tmp2&1) ret=(ll)ret*tmp1%D;
	return ret;
}