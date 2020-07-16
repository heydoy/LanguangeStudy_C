'''
Lab 05, Doy Kim, Wed 22 Apr, 2020
은행업무 프로그램 (bank.py)
'''

status = 0
name = None
balance = 100000

#ATM 기능별 함수 정의

def deposit():
    while(True):
        money = int(input('입금할 금액을 입력해주세요 : '))
        if(money <= 0):
            print('\n정확한 금액을 입력해주세요')
        else :
            break
        
    global balance
    balance = balance + money
    print('\n{}원이 정상적으로 입금되었습니다.\n'.format(money))



def withdrawal():
    while(True):
        money = int(input('출금할 금액을 입력해주세요 : '))
        if(money <= 0):
            print('\n정확한 금액을 입력해주세요\n')
        else :
            break

    global balance
    
    if(balance < money) :
        print('\n잔액부족. 거래가 거절되었습니다.\n')
    else :
        balance = balance - money
        print('\n{}원이 정상적으로 출금되었습니다.\n'.format(money))
    

def checkBalance():
    print('{}님의 현재 잔액은 {}원입니다.\n'.format(name, balance))


#ATM 시작
    
while(status !=4):

    print('='*45)
    print('\t\t은행 ATM')
    print('='*45)

    if name is None :
        name = str(input('계좌 소유주의 이름을 입력해주세요 : '))

    print('1. 입금\n2. 출금\n3. 잔액확인\n4. 종료')
    print('='*45)

    status = int(input('메뉴선택 : '))

    if(status==1) :
        deposit()
        
    elif(status==2) :
        withdrawal()
        
    elif(status==3) :
        checkBalance()

print('\n저희 은행을 이용해주셔서 감사합니다.\n') 
