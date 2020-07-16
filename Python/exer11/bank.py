'''
Lab10 은행계좌 프로그램
학번. 18185364
이름. 김도이 
'''
# Account 클래스를 이용하여 잔액조회,입금,출금
class Account :
    # 출력 초기화 : 계좌 소유자 이름을 받고 초기금액 0
    def __init__(self, name ):
        self.owner = name
        self.balance = 0;
        
    # 입금 
    def deposit(self):
        amount = int(input('\n입금할 금액을 입력해주세요 : '))
        if amount <= 0 :
            print('정확한 금액을 입력해주세요.')
            
        else :
            print('{}원이 성공적으로 입금되었습니다.'.format(amount))
            self.balance += amount
            
    # 출금  
    def withdraw(self):
        amount = int(input('\n출금할 금액을 입력해주세요 : '))
        if amount <= 0 :
            print('정확한 금액을 입력해주세요.')
        elif(amount > self.balance) :
            print('잔액 부족. 거래 거절되었습니다.')
        else :
            print('%d원이 성공적으로 인출되었습니다.' % amount )
            self.balance -= amount
        
    # 잔액조회
    def printAccount(self):
        print('')
        print('계좌 소유자 : {}'.format(self.owner))
        print('현재 잔액  : {}'.format(self.balance)) 
        


#메뉴를 출력하는 함수
def printMenu() :
    print('')
    print('*'* 42)
    print(' '*8,'Sookmyung Bank ATM')
    print('*'* 42)
    print('\t1.잔액확인')
    print('\t2.입금')
    print('\t3.출금')
    print('\t4.종료')
    print('*'* 42)
    print('')


#메인 시작

ownername = str(input('\n계좌 소유자의 이름을 입력해주세요 : '))
myaccount = Account(ownername)

while(True) :
    printMenu()
    choice = int(input('메뉴를 선택해주세요 >>> '))

    if(choice == 1) :
        myaccount.printAccount()
    elif(choice == 2) :
        myaccount.deposit()
    elif(choice == 3) :
        myaccount.withdraw()
    elif(choice == 4) :
        break
    else :
        print('메뉴를 다시 선택해주세요')

print('\n이용해주셔서 감사합니다.')
