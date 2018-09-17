//选择C语言是因为在选择python时发现没有switch语句不方便，但是其实只是我自己陷入了思维误区，其实并不需要真正按照序号一一操作，由于只要每个操作的次数一样先后顺序并不影响
//由于我之前并没有怎么接触算法，所以这里选择了暴力枚举，在今后的学习中肯定会有更优秀的算法
#include <stdio.h>

int main()
{
    int dials[9] = {0}, ends[9] = {0}, steps[9] = {0};
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &dials[i]);
    }
    for (steps[0] = 0; steps[0] <= 3; steps[0]++)           //选择出最简便的操作方法
        for (steps[1] = 0; steps[1] <= 3; steps[1]++)
            for (steps[2] = 0; steps[2] <= 3; steps[2]++)
                for (steps[3] = 0; steps[3] <= 3; steps[3]++)
                    for (steps[4] = 0; steps[4] <= 3; steps[4]++)
                        for (steps[5] = 0; steps[5] <= 3; steps[5]++)
                            for (steps[6] = 0; steps[6] <= 3; steps[6]++)
                                for (steps[7] = 0; steps[7] <= 3; steps[7]++)
                                    for (steps[8] = 0; steps[8] <= 3; steps[8]++)
                                    {
                                        ends[0] = dials[0] + steps[0] + steps[1] + steps[3];            //当指针指向12点时序号必定是4的倍数
                                        ends[1] = dials[1] + steps[0] + steps[1] + steps[2] + steps[4];
                                        ends[2] = dials[2] + steps[1] + steps[2] + steps[5];
                                        ends[3] = dials[3] + steps[0] + steps[3] + steps[4] + steps[6];
                                        ends[4] = dials[4] + steps[0] + steps[2] + steps[4] + steps[6] + steps[8];
                                        ends[5] = dials[5] + steps[2] + steps[4] + steps[5] + steps[8];
                                        ends[6] = dials[6] + steps[3] + steps[6] + steps[7];
                                        ends[7] = dials[7] + steps[4] + steps[6] + steps[7] + steps[8];
                                        ends[8] = dials[8] + steps[5] + steps[7] + steps[8];
                                        if(ends[0]%4 + ends[1]%4 + ends[2]%4 + ends[3]%4 + ends[4]%4 + ends[5]%4 + ends[6]%4 + ends[7]%4 + ends[8]%4 == 0)
                                        {
                                            for(int i = 0, k = 1; i < 9; i++, k++)
                                                for(int j = 0; j < steps[i]; j++)
                                                    printf("%d", k);
                                            return 0;
                                        }
                                    }
}