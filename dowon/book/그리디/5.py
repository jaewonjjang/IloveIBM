n,m = map(int,input().split())
arr = list(map(int,input().split()))
 
d = [0] * 11 
for i in arr:
  d[i] += 1
 
result = 0
for i in range(1,m+1): # a가 선택하는 무게
  n -= d[i]
  result += d[i]*n 
 
print(result)