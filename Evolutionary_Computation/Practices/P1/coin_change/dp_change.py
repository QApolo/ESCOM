import numpy as np
from random import *
import matplotlib.pyplot as plt


def changeCoins(coins, value):
	coins.sort()
	memo = np.full(value + 1, np.Inf)

	memo[0] = 0

	for i in range(1, value + 1):
		memo[i] = np.Inf

	for i in range(1, value + 1):
		for j in range(0, len(coins)):
			current = memo[i - coins[j]]

			if current != np.Inf and current + 1  < memo[i]:
				memo[i] = current + 1
	return int(memo[value])


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
		quant_coins = randrange(4, 10)
		value = randrange(20, 40)
		coins = [coin for coin in range(1, quant_coins)]

		np.random.shuffle(coins)
		print(value)
		print(coins)
	print(changeCoins(coins, value))