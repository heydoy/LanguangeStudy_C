#Lab 03, Doy Kim, Wed 8 Apr, 2020

import math

x1 = int(input("x1: "))
y1 = int(input("y1: "))
x2 = int(input("x2: "))
y2 = int(input("y2: "))

distance = math.sqrt((x2-x1)**2+(y2-y1)**2)

print("두 점 사이의 거리: ", distance)
