'''전역변수 지역변수의 scope 확인 '''

rate = 20

def saleprice(price) :
    global rate
    rate += 10
    return price*(1-rate/100)

print(saleprice(30000))
print(rate)

