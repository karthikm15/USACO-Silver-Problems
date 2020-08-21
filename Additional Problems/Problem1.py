cows = input().split()
cows = [int(i) for i in cows]

CowOrder = True
count = 0
number = 1
number2 = 1
NumberOfCows = cows[0]
max = cows[0]
del cows[0]

while (number2 == 1):
	for i in range(cows[0]):
		if (cows[i] < cows[i-1]):
			number = 0
	if (number == 0):
		number2 = 0
	for i in range(cows[0]):
		if (cows[i] > cows[i-1]):
			var = cows[i-1]
			var2 = cows[i]
			cows[i-1] = var2
			cows[i] = var
		count += 1 

print(count - 1)



		



