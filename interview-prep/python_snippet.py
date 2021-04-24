# integer input
a = int(input())
  
# print type
print(type(a))


# take multiple inputs in array
input_int_array = [ int(x) for x in input().split()]
  
print("array:", input_int_array)

# for x in input_int_array:
#     print(x)
input_int_array.append(5)
for x in input_int_array:
    print(x)

#string * string
str1 = int(input())
str2 = int(input())

print(str1*str2)
