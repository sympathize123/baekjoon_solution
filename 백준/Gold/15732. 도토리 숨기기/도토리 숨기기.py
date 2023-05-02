N, K, D = map(int, input().split())
rules = []
for i in range(K):
    rules.append(tuple(map(int, input().split())))
start = 1
end = N
answer = end
while start <= end:
    sum = 0
    mid = (start + end) // 2
    for box1, box2, interval in rules:
        if mid == box1:
            sum += 1
        elif box1 > mid:
            continue
        elif mid <= box2:
            sum += (mid - box1) // interval + 1
        else:
            sum += (box2 - box1) // interval + 1
        if sum >= D:
            end = mid - 1
            answer = mid
            break
    if sum < D:
        start = mid + 1
print(answer)
