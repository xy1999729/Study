//�������֪��12ö������ֻ�ܳ������� ��ÿ���������ٳ���һ�Σ���һ�����ٷ�12*2/6=4������,����һ�߷�6ö
//�����ƽƽ�����������ұ�Ϊ��� 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;	
	cin >> n;
	while(n--)
	{
		bool coin[12]= {0};	//����һ���������������ڴ����Ϊ������ң���ʼ����Ϊ�ٱ� 
		int probability[12] = {0}, maxN = 0;	//���ڼ�¼����Ϊ�ٱҵĿ����ԺͿ��������ֵ������ţ������б����ƽ�г�������ͬ��Ӳ�ң�����ִ���Խ��Ϊ�ٱҵĿ�����Խ�� 
		char leftBa[3][7] = {"", "", ""}, rightBa[3][7] = {"", "", ""}, situation[3][4] = {"", "", ""}; //�����СӦ��Ϊ7����Ϊ��Ȼֻ��Ҫ�����������ң�������Ҫһ���ռ䴢��'\0'����Ϊ������֮������� 
		for(int i = 0; i < 3; i++)
		{
			cin>>leftBa[i]>>rightBa[i]>>situation[i];
		}	//ͬʱ�������ص�һ��ʱ����Ϊ�ٿ�����++�����һ��ʱ����--�����ȽϿ����Եľ���ֵ���˴������ػ����++�Կɣ����������֪���н� 
		for(int i = 0; i < 3; i++)
		{
			if(situation[i][0] == 'e')
			{
				for(int j = 0; leftBa[i][j] != '\0'; j++)
				{
					coin[leftBa[i][j] - 'A'] = true;
					coin[rightBa[i][j] - 'A'] = true;
				}
			}
			else if(situation[i][0] == 'u')
			{
				for(int j = 0; leftBa[i][j] != '\0'; j++)
				{
					probability[leftBa[i][j] - 'A']++;
					probability[rightBa[i][j] - 'A']--;
				}
			}
			else if(situation[i][0] == 'd')
			{
				for(int j = 0; leftBa[i][j] != '\0'; j++)
				{
				probability[leftBa[i][j] - 'A']--;
				probability[rightBa[i][j] - 'A']++;
				}
			}
		} 
		for(int i = 0; i < 12; i++)
		{
			if(coin[i])
			{
				probability[i] = 0;
			}
		}
		for(int i = 0; i < 11; i++)
		{
			if(abs(probability[maxN]) < abs(probability[i + 1])) 
				maxN = i + 1; 
		}
		if(probability[maxN] > 0)
		{
			cout<<char('A' + maxN)<<' '<<"heavy"<<endl;
		}
		else
		{
			cout<<char('A' + maxN)<<' '<<"light"<<endl;
		}
	}
}