n = int(input())
fear = list(map(int,input().split()))


result = 0
count = 0
fear.sort()

for i in fear:
    count += 1
    if count >= i:
        result += 1
        count =0
    
print(count)
