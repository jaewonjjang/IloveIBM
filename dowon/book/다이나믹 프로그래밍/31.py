# 모르겠음

for i in range(int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))

    list = []
    index = 0

    for j in range(n) :
        list.append(arr[index: index + m])
        index += m

    for k in range(1,m):
        for f in range(n):
        # 왼쪽 위에서 오는 경우
            if f == 0:
                left_up = 0
            else:
                left_up = list[f-1][k-1]
        # 왼쪽 아래에서 오는 경우
            if f == n - 1:
                left_down = 0
        # 왼쪽에서 오는 경우
            else:
                left_down = list[f+1][k-1]
            left = list[f][k-1]
            list[f][k] = list[f][k] + max(left_up, left_down, left)

    result = 0
    for t in range(n):
        result = max(result,list[t][m-1])
    print(result)