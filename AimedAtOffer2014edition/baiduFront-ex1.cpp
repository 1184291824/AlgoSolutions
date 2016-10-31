#include <iostream>
using namespace std;
typedef long long int64;  // int64(LL): 64λ������, ��long long�ı��

int64 m,n,k;
int64 cal(int64 x)  // �����xС�����ĸ��� 
{
	int64 sum=0;
	for(int i=1;i<=n;i++)
	{
		sum += min(m,x/i);
	}
	return sum;
}

int64 binarySearch(int64 leftVal, int64 rightVal, int64 kth) 
{
    int64 midVal;

    while(leftVal <= rightVal)
    {
	    midVal=(leftVal+rightVal)/2;
		if(cal(midVal) < kth) leftVal=midVal+1; // Ҫ�ҵ����ں��棬�������޼�������
		else rightVal=midVal-1;                 // Ҫ�ҵ�����ǰ�棬�������޼�����С
	}		
    return leftVal;
}

int main()
{
    while(cin>>m>>n>>k && m>=1 && n>=1 && k>=1 && k<=m*n)
	{
		cout<<binarySearch(1,n*m,k);
		cout<<endl;
	}
    return 0;
}