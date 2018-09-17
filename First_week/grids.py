#选择python是因为python字符串处理更方便（其实C++也挺方便）
matrix = [[0] * 101 for i in range(0, 101)]         #使用101*101数组便于坐标管理
n = int(input())                                    #0代表白色，1代表黑色
for i in range(0, n):
    command, x, y, l = input().split()
    x = int(x)
    y = int(y)
    l = int(l)
    flag = 0
    if command == 'BLACK':
        for j in range(x, x+l):                     #因为数组大小为101*101即选择下标与坐标相等，所以此处不是x+l-1，以下同理
            for k in range(y, y+l):
                matrix[j][k] = 1
    elif command == 'WHITE':
        for j in range(x, x+l):
            for k in range(y, y+l):
                matrix[j][k] = 0
    elif command == 'TEST':
        for j in range(x, x+l):
            for k in range(y, y+l):
                if matrix[j][k] == 1:
                    flag += 1
        print(flag)