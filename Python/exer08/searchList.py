'''
김도이 1815364
Lab08 : 과제 1 리스트의 최대,최소,중간값 찾기
'''

number = []

while True :
    print("Enter numbers. (To finish press 'Enter' key)")
    n = input()
    # 리스트에 아무것도 없는데 사용자가 엔터를 눌렀을 경우 
    if len(n) == 0 and len(number) == 0 :
        continue
    if len(n) == 0 and len(number) != 0 :
        break
    number.append(float(n))


number.sort()
length = len(number)
median_index = int(length/2)

if length % 2 :
    median = number[median_index]
    
else :
    median = (number[median_index] + number[median_index-1])/2
    
print('You entered')
print(number)

print('')
print('max : %.1f'%number[-1])
print('min : %.1f'%number[0])
print('median : %.2f'%median)
