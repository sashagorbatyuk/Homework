import sys

list = []

#input number 1
while(True): 
    aString = input("Enter num 1: ")

    if(aString.isnumeric()): 
        list.insert(0, int(aString))
        break
    else:
        print(f"The entered value [{aString}] is not an number. Enter an number")
        continue

#input mathematical sign
while(True): 
    list.insert(1, (input("Enter mathematic sign: ")))
    if(list[1] == "+" or list[1] == "-" or list[1] == "*" or list[1] == "/"):
        break
    else:
        print(f"The entered value [{list[1]}] is not an number. Enter an number")
        continue

#input number 2
while(True):
    bString = input("Enter num 2: ")
    if(bString.isnumeric()):
        list.insert(2, int(bString))
        break
    else:
        print(f"The entered value [{bString}] is not an number. Enter an number")
        continue

#calculate
match list[1]:
    case "-":
         list.insert(3, list[0] - list[2])
    case "+":
         list.insert(3, list[0] + list[2])
    case "*":
         list.insert(3, list[0] * list[2])
    case "/":
         list.insert(3, list[0] / list[2])
    case":":
        print(f"{list[1]} is not an valid option")

#print result
print(f"{list[0]} {list[1]} {list[2]} = {list[3]}")

list.insert(56, 6 - 3)
print(list[56])