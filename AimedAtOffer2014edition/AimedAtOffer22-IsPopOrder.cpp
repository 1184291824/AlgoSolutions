#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	if(pushV.size() == 0 || popV.size() == 0)
        return false;  // �������һ�����г���Ϊ0���򲻺����⣬����false
    stack<int> s; 

	int k=0;
	for(int i=0;i<pushV.size();i++)
	{
		if(pushV[i] != popV[k])
		{
			s.push(pushV[i]);    // ѹջ��ֱ��ջ��Ԫ�ص����������
		}
		else {
		k++;
		while (!s.empty() && s.top()==popV[k])
		{
			s.pop();   // ������к�ջ��һ�£�����
			k++;
		}
	  }
    }
		if(k==popV.size()) return true;  // ѹ�������������ȣ��жϽ��Ϊ���ǳ�ջ����
		return false; // �Բ��ȣ����жϽ��Ϊ�����ǳ�ջ����
}
};

// ����Ϊ���Բ���
int main()
{
	Solution sol;
	int in[] = {1,2,3,4,5};
	int a[] = {4,5,3,2,1};
    int b[] = {4,3,5,1,2};
	vector<int> invec(in,in+5);
	vector<int> vec1(a,a+5);
	vector<int> vec2(b,b+5);

	//vector<int> invec(0);
	//vector<int> vec1(0);
	//vector<int> vec2(0);

	cout<<"Is the sequence possible pop order ?: "<<sol.IsPopOrder(invec,vec1)<<endl;
	cout<<"Is the sequence possible pop order ?: "<<sol.IsPopOrder(invec,vec2)<<endl;
	return 0;
}
