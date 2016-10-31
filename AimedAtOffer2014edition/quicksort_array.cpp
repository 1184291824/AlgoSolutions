#include<iostream>
#include<cstdio>
using namespace std;

class Solution{
public:
void quickSort(int arr[], int forward, int backward)
{
	int part_pos;                   // ��¼ÿ�ε��ÿ��� quickSort()����Ԫe��λ�� 
	if(forward>=backward) return;
 
 	// int split(int[], int, int);  // �������C�����У��˴���Ҫ����һ�£����������class���棬���ܽ������� 
 	part_pos=split(arr, forward, backward);
 	
	cout<<"The postion of the partition elemen is: "<<part_pos<<endl; 
 	for(int idx=0;idx<9;idx++)
	{
	printf("%d ",arr[idx]);		
	}
	printf("\n");	
	
	quickSort(arr, forward, part_pos-1);   // �ݹ�ظ���Ԫe���Ԫ������ 
	quickSort(arr, part_pos+1, backward);  // �ݹ�ظ���Ԫe�Ҳ�Ԫ������ 
}

int split(int arr[], int forward, int backward)  // �ָ���طָ���Ԫ��λ�� 
{
	int part_val=arr[forward]; // �������ָ��Ԫ��(Ҳ��Ϊpartition��Ԫ)��ֵ���Ե�һ����Ϊ�ָ��׼ 
	
	while(true)
	{
		while(forward<backward && arr[backward]>part_val) backward--;
		if(forward>=backward) break;
		arr[forward++]=arr[backward];
		
		while(forward<backward && arr[forward]<=part_val) forward++;
		if(forward>=backward) break;
		arr[backward--]=arr[forward];		
	}	
	arr[backward]=part_val;
	return backward;		
}
};

int main()
{
	Solution sol;
	int arr[]={12,3,6,18,7,15,10,56,4};
	sol.quickSort(arr,0,8);
	printf("The final result is:\n");	
	for(int idx=0;idx<9;idx++)
	{
	printf("%d ",arr[idx]);		
	}
	printf("\n");
	return 0;
}