import numpy as np
import matplotlib.pyplot as plt
from random import *

def changeCoins(coins, val):
	coins.sort()
	index = len(coins) - 1

	used_coins = dict()
	for coin in range(0, len(coins)):
		used_coins[coin] = 0
	print(coins)
	counter = 0

	while val > 0 and index >= 0:
		while index > 0 and coins[index] > val:
			index = index - 1
		counter = counter + 1
		if coins[index] <= val:
			used_coins.update( {index: used_coins.get(index)  + 1})
			print(val, index)
		val = val - coins[index]

	print("coins used:")
	x = []
	f_x = []
	for ind, count in used_coins.items():
		x.append(coins[ind])
		f_x.append(count)
		if count > 0:
			print(coins[ind], count)
	plt.bar(x, f_x)
	plt.title('Total amount: ' + str(value))
	plt.xlabel('Coins denominations')
	plt.ylabel('Number of coins used')
	plt.xticks(x)
	plt.yticks(f_x)
	plt.show()

	return counter

if __name__ == '__main__':
	des = input('Do you want random values (y/n)?')
	if(des != 'y'):

		quant_coins = int(input('How many different coins do you have'))
		value = int(input('Insert the value that you want to change'))

		print('Insert the total number of coins')
		coins = []
		for i in range(0, quant_coins):
			coins.append(int(input('')))
	else:
		quant_coins = randrange(4, 50)
		value = randrange(20, 2000)
		s = set()
		ind = 0
		s.add(1)
		while len(s) + 1 < quant_coins:
			s.add(randrange(1, 100))
		coins = list(s)
		print(value)
		#print(coins)
	print(changeCoins(coins, value))