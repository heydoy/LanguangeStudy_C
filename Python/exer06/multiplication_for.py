'''
이름 : 김도이
학번 : 1815364
과제명 : Lab06, multiplication_for.py
내용 : 2와 3의 배수 제외 출력 프로그램 (for문) 

'''

num = int(input('숫자를 입력해주세요 : '))

for i in range(1, num+1) :
    if(i%2 == 0 and i%3 == 0):
        continue
    print(i)
