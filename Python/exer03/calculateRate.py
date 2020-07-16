#Lab 03, Doy Kim, Wed 8 Apr, 2020

basic_rate = 12100
call_rate = 1.98
data_rate = 55

name = input("사용자 이름을 입력하세요: ")
call = int(input("통화량(초)을 입력하세요: "))
data = int(input("데이터 사용량(MB)를 입력하세요: "))

total_rate = basic_rate+call*call_rate+data*data_rate

print("{} 님의 이번달 요금 : {}".format(name, total_rate))

