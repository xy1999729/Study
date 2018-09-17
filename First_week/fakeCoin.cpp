//由题意可知有12枚银币且只能称重三次 ，每个银币至少出现一次，则一次至少放12*2/6=4个银币,至多一边放6枚
//如果天平平衡则两边银币必为真币 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;	
	cin >> n;
	while(n--)
	{
		bool coin[12]= {0};	//设置一个布尔型数组用于储存必为真的银币，初始化都为假币 
		int probability[12] = {0}, maxN = 0;	//用于记录银币为假币的可能性和可能性最大值银币序号，如果倾斜的天平中出现了相同的硬币，则出现次数越多为假币的可能性越大 
		char leftBa[3][7] = {"", "", ""}, rightBa[3][7] = {"", "", ""}, situation[3][4] = {"", "", ""}; //数组大小应该为7，因为虽然只需要输入六个银币，但是需要一个空间储存'\0'来作为行与行之间的区分 
		for(int i = 0; i < 3; i++)
		{
			cin>>leftBa[i]>>rightBa[i]>>situation[i];
		}	//同时出现在重的一边时银币为假可能性++，轻的一边时银币--，最后比较可能性的绝对值（此处定义重或轻的++皆可），且由题可知必有解 
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