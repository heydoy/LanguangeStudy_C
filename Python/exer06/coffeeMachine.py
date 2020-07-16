'''
이름 : 김도이
학번 : 1815364
과제명 : Lab06, coffeeMachine.py
내용 : 커피주문점 주문 프로그램

'''
#주문하는 함수
def process_order():
    while(1):
        order = str(input('주문을 계속하시겠습니까? (Y/N) >>> '))

        if(order == 'n' or order == 'N'):
            return order
        
        elif(order == 'y' or order == 'Y'):
            return order
        
        else :
            print("잘못 입력하셨습니다.")
            continue
        

#카페 메뉴 출력
print('='*6,'Sookmyung Cafe','='*6)
print('    1. 아메리카노 1800원')
print('    2. 카페라떼   2200원')
print('    3. 카페모카   2800원')
print('='*28)
print('')

americano = 0
latte = 0
mocha = 0
menu = 0
count = 0
menulist = []

while(1) :
    
    menu = int(input('메뉴를 선택해주세요 >>> '))

    if menu < 1 or menu > 3 :
        print('메뉴를 다시 선택해주세요.')
        continue

    if menu not in menulist: 
        menulist.append(menu)
        
    count = int(input('몇 잔을 주문하시겠습니까? >>> '))
    
        
    if menu==1 :
        americano += count

    elif menu==2 :
        latte += count

    elif menu==3 :
        mocha += count

    
    order = process_order()
    
    if(order == 'y' or order == 'Y') :
        continue
    elif(order == 'n' or order == 'N') :
        break
    
        
    
total = americano*1800 + latte*2200 + mocha*2800;

#주문내역 출력
print('')
print('='*5, '주 문 내 역','='*5)

for i in menulist :
    if i == 1 :
        print("    아메리카노 {} 잔".format(americano))
    elif i == 2 :
        print("    카페라떼 {} 잔".format(latte))
    elif i == 3 :
        print("    카페모카 {} 잔".format(mocha))
        
print('\n==총 {} 잔, {} 원==\n'.format(americano+latte+mocha,total))
print('이용해주셔서 감사합니다.')
