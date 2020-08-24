from collections import Counter
Dice = input().split()
Dice = [int(i) for i in Dice]

# The function that checks which element in the list is the most frequent
def most_frequent(List): 
    HowManyTimes = Counter(List) 
    return HowManyTimes.most_common(1)[0][0] 

FirstDice = Dice[0]
SecondDice = Dice[1]
ThirdDice = Dice[2]
# SumArray is the list which tracks all of the sums
SumArray = []

for i in range(FirstDice):
	for j in range(SecondDice):
		for k in range(ThirdDice):
			sum = i + j + k + 3
			SumArray.append(sum) 

print(most_frequent(SumArray))