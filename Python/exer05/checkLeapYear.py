'''
Lab 05, Doy Kim, Wed 22 Apr, 2020
윤년판단 프로그램 (checkLeapYear.py)
'''

year = int(input('연도를 입력하세요 : '))

if(year %4 == 0 and year % 100 != 0) :
    print('{}년은 윤년입니다.'.format(year))

elif(year % 400 == 0) :
    print('{}년은 윤년입니다.'.format(year))

else :
    print('{}년은 윤년이 아닙니다.'.format(year))
