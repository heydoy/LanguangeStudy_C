'''
이름 : 김도이
학번 : 1815364
과제명 : Lab06, multiplication_while.py
내용 : 2와 3의 배수 제외 출력 프로그램 (while문) 

'''
i = 0
num = int(input('숫자를 입력해주세요 : '))

while i < num :
    i = i+1
    if(i%2 == 0 and i%3 == 0):
        continue
    print(i)
    
