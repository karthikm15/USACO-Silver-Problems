x = input().split()
x = [int(i) for i in x]

FarmerJohnLocation = x[0]
CowLocation = x[1]
count = 0
LeastMultiplied = int(CowLocation / 2)
SecondMultiplied = LeastMultiplied + 1
EvenMultiplied = int(CowLocation / 2)

while (FarmerJohnLocation != CowLocation):
	if ((FarmerJohnLocation * 2) < CowLocation):
		FarmerJohnLocation = FarmerJohnLocation * 2
		count += 1
	else:
		if (CowLocation % 2 == 0):
			w1 = abs(FarmerJohnLocation - CowLocation) 
			x1 = ((FarmerJohnLocation * 2) - CowLocation) + 1
			y1 = FarmerJohnLocation - LeastMultiplied + 2
			z1 = FarmerJohnLocation - SecondMultiplied + 2
			list1 = [w1, x1, y1, z1]
			minimum = min(list1)
			count += minimum
			FarmerJohnLocation = CowLocation
		else:
			w1 = abs(FarmerJohnLocation - CowLocation) 
			x1 = ((FarmerJohnLocation * 2) - CowLocation) + 1
			y1 = FarmerJohnLocation - EvenMultiplied + 1
			list2 = [w1, x1, y1]
			minimum = min(list2)
			print(w1, x1, y1, minimum)
			count += minimum
			FarmerJohnLocation = CowLocation

print(count)
