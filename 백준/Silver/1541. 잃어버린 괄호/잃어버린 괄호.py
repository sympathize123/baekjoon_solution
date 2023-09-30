input_str = input()
num = []
PM = []
temp = ""
for i in input_str:
    if i.isnumeric():
        temp = temp + i
    else:
        num.append(int(temp))
        temp = ""
        PM.append(i)
num.append(int(temp))
# print(PM, num)
result = num.pop(0)
temp = 0
isplus = True
while num or PM:
    if isplus:
        if PM.pop(0) == "+":
            result += num.pop(0)
        else:
            isplus = False
            temp += num.pop(0)
    else:
        if PM.pop(0) == "+":
            temp += num.pop(0)
        else:
            result -= temp
            temp = num.pop(0)
if temp > 0:
    result -= temp
print(result)
