template <typename T>
void make_next(const T arr[],const int len,int next[]) {
	next[0]=0;
	for (int i=1,k=0;i<len;i++) {
		while (arr[i]!=arr[k]&&k) k=next[k-1];
		if (arr[i]==arr[k]) k++;
		next[i]=k;
	}
}

template <typename T>
int kmp(const T a[],const int len_a,const T b[],const int len_b) {
	int *next=new int[len_b];
	make_next<T>(b,len_b,next);
	for (int i=0,k=0;i<len_a;i++) {
		while (a[i]!=b[k]&&k) k=next[k-1];
		if (a[i]==b[k]) k++;
		if (k==len_b) {
			delete[] next;
			return i-k+1;
		}
	}
	delete[] next;
	return -1;
}