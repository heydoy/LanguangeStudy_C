'''
Lab10
과제: 커피머신 프로그램
학번: 1815364
이름: 김도이
'''
#카페메뉴를 key로 하는 사전
cup = {}     #주문 내역
menu = {'아메리카노':1800, '카페라떼':2200, '카페모카':2800}
paid = 0     #결제 금액 
total = 0    #주문한 메뉴 총합
change = 0

# 커피머신 메뉴 출력
def printMenu() :
    print('')
    print('='*7, end='')
    print('Sookmyung Cafe', end='')
    print('='*7)

    print('\t1. 커피메뉴 선택')
    print('\t2. 주문내역 확인')
    print('\t3. 결제')
    print('\t4. 잔돈 계산')
    print('='*28)
    print('')
    
# 카페 메뉴 출력
def printCoffeeMenu():
    print('')
    print('[Cafe Menu]')
    for coffee, price in menu.items() :
        print(coffee, price, '원')

#주문할 커피메뉴와 커피개수 선택
def selectMenu():
    print('')
    while(True):
        ordered = str(input('메뉴를 입력해주세요.(엔터 입력시 종료) >>> '))
        if ordered == '' :
            return
        elif ordered not in menu :
            print('메뉴를 다시 입력해주세요.')
            continue
        
        else :
            while(True):
                count = int(input('몇 잔을 주문하시겠습니까? >>> '))
                if count < 0 :
                    print('잘못된 입력입니다.')
                else :
                    if cup.get(ordered) :
                        cup[ordered] += count;
                        break
                    else :
                        cup[ordered] = count;
                        break
            
    
#커피 주문 내역 출력
def checkOrder():
    print('')
    for drink, count in cup.items() :
        print('{}\t{}잔'.format(drink, count))
        

#총 가격계산 및 돈 지불
def calculatePrice():
    global paid
    global total
    
    print('')
    for drink, count in cup.items() :
        total += menu[drink] * count

    print('합계 : {}'.format(total))

    while(True):
        paid = int(input('지불할 돈 : '))
        if paid < total :
            print('{}원 이상의 돈을 지불하세요.'.format(total))
        else :
            print('지불 완료')
            break

    return
            

#잔돈 계산
def getChange():
    global paid
    global total
    
    print('')
    if paid == 0 :
        print('[3.결제]를 먼저 해주세요.')
        return

    else :
        change = paid-total
        print('잔돈은 {}원입니다.'.format(change))
        print('='*28)

        if change//5000 :
            print('5000원 : ', change//5000)
            change %= 5000
        if change//1000 :
            print('1000원 : ', change//1000)
            change %= 1000
        if change//500 :
            print('500원 : ', change//500)
            change %= 500
        if change//100 :
            print('100원 : ', change//100)

        print('')
        print('이용해주셔서 감사합니다.')
        


#여기서부터 메인

while(True):
    printMenu()
    
    select= int(input('메뉴를 선택해주세요 >>> '))

    if select == 1 :
        printCoffeeMenu()
        selectMenu()

    elif select == 2 :
        checkOrder()

    elif select == 3 :
        calculatePrice()

    elif select == 4 :
        getChange()
        break


    else :
        printf('잘못 입력하셨습니다.')
        continue

    
