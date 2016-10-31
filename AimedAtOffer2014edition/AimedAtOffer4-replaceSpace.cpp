#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

class Solution{
public:
void replaceSpace(char *str, int length)  // ��������ָ��:lengthΪ�ַ�����str��������
{
	if(str==NULL || length<=0) return;
	
	int newlen=0;
    int spaceCount = 0;
    int idx;
    for(idx = 0; str[idx] != '\0'; idx++)
	{
        if (str[idx] == ' ')
		{
            spaceCount++;
        }
    }
    newlen = idx + 2*spaceCount;
    if(newlen > length) return;
    str[newlen]='\0';  //���кܹؼ� 
    int frontCur = idx - 1, backCur = newlen-1;
    for(; frontCur >= 0 && backCur > frontCur; frontCur--)
	{
        if (str[frontCur] == ' ')
			{
            str[backCur--] = '0';
            str[backCur--] = '2';
            str[backCur--] = '%';
        	}
		else str[backCur--] = str[frontCur];
    }
}
};

// ����Ϊ���Բ���

int main()
{
	Solution sol;
	char str[]="Hello World, haha";
	sol.replaceSpace(str, 20);
	// printf("%s\n",str);
	cout<<str<<endl;	
	return 0;
}
