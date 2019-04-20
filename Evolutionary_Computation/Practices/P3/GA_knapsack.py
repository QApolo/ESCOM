import random
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from math import *

ALPHA = 4
def numToBinList(x, L):
	binary = [0 for i in range(0, L)]
	index = L - 1
	while x > 0 and index >= 0:
		binary[index] = (x % 2)
		x = x // 2
		index = index - 1
	print(binary)
	return binary
class GUI_plot:
	def __init__(self, x_min, x_max, ga1):
		plt.rcParams['legend.fontsize'] = 10

		fig = plt.figure()
		ax = fig.gca(projection='3d')

		# Prepare arrays x, y, z
		theta = np.linspace(-4 * np.pi, 4 * np.pi, 100)
		z = np.linspace(-2, 2, 100)
		r = z**2 + 1
		x = r * np.sin(theta)
		y = r * np.cos(theta)

		ax.plot(x, y, z, label='parametric curve')
		ax.legend()

		plt.show()


	def test(self):
		fig = plt.figure()
		ax = fig.add_subplot(111, projection='3d')

		# Grab some test data.
		#X, Y, Z = axes3d.get_test_data(0.05)


		print(f"x: {X}")
		print(f"y: {Y}")
		print(f"z: {Z}")

		# Plot a basic wireframe.
		ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10)

		plt.show()
	def f(self):
		list_vals = []
		list_weights = []
		for x in self.x_vals:
			val = 0
			weight = 0
			index = 0
			for i in x:
				val = val + i * self.knapsack.V[index] 
				weight = weight + i * self.knapsack.W[index]
			list_vals.append(val)
			list_weights.append(weight)	
		return [list_weights, list_vals]

class Knapsack:
	def __init__(self, V, W, capacity):
		self.V = V
		self.W = W
		self.capacity = capacity
	def getCapacity(self):
		return self.capacity
	def getV(self):
		return self.V
	def getW(self):
		return self.W

class GeneticAlgorithm:
	#knapsack object, pupulation size
	def __init__(self, knapsack, N, p_mutation = 0.5, p_selection = 0.5):
		self.knapsack = knapsack
		self.N = N
		self.p_selection = p_selection
		self.p_mutation = p_mutation
		self.L = len(knapsack.getV())
		
	def createPopulation(self):
		self.population = []
		for i in range(1, self.N):
			self.population.append(self.createChromosome())

	def createChromosome(self):
		chromosome = [random.randint(0, 1) for i in range(0, self.L)]
		return chromosome
	def fitnessPopulation(self):
		self.fitness = []
		for i in range(0, len(self.population)):
			self.fitness.append(self.getFitness(self.population[i], alpha = ALPHA))

	def getFitness(self, chromosome, alpha):
		current_weight = self.getWeight(chromosome)
		current_val = self.getVal(chromosome)
		return (current_val + alpha * (self.knapsack.getCapacity() - current_weight))

	def getWeight(self, chromosome):
		current_weight = 0
		for i in range(0, len(chromosome)):
			current_weight += (chromosome[i] * self.knapsack.getW()[i])	
		return current_weight
	def getVal(self, chromosome):
		current_val = 0
		for i in range(0, len(chromosome)):
			current_val += (chromosome[i] * self.knapsack.getV()[i])	
		return current_val

	def initTime(self, generations = 100):
		for gen in range(generations):
			self.createPopulation() #step 1
			self.fitnessPopulation() #step 2
			print(self.population)
			
			fit = 0
			best = [0 for i in range(0, self.L)]
			for c in self.population:
				cur_fit = self.getFitness(c, ALPHA)
				if cur_fit > fit:
					fit = cur_fit
					best = c[:]

			print("best solution so far: weight " + str(self.getWeight(best)) +  " value " + str(self.getVal(best)))
			self.offsprings = []
			while len(self.offsprings) < self.N:
				current_sel = self.selection()
				springoff = self.crossover(current_sel[0], current_sel[1])
				if random.random() <= 0.2:
					pos = random.randint(0, self.L-1)
					#print(springoff[0])
					springoff[0][pos] ^= springoff[0][pos]
					springoff[1][pos] ^= springoff[1][pos]
				self.offsprings.append(springoff[0])
				self.offsprings.append(springoff[1])
			self.population = self.offsprings[:]

	def crossover(self, A, B):
		mid = len(A) // 2
		C1 = [0 for i in range(0, len(A))]
		C2 = [0 for i in range(0, len(A))]
		C1[0: mid] = B[0: mid]
		C1[mid: len(A)] = A[mid: len(A)]

		C2[0: mid] = A[mid: len(A)]
		C2[mid: len(A)] = B[0: mid]
		print("parent A: ", *A)
		print("parentB: " , *B)
		print(C1)
		print(C2)
		return [C1, C2]

	def selection(self):
		maximum = max(self.fitness)
		minimum = min(self.fitness)
		per = (maximum - minimum)

		selected = []
		fitness_shift = [(val - minimum) for val in self.fitness]
		index = 0
		for val in fitness_shift:
			if len(selected) >= 2:
				break
			rate = val / per
			rand_val = random.random()
			if rate < rand_val:
				selected.append(self.population[index])
		return selected
			
if __name__ == '__main__':
	knapsack1 = Knapsack([60, 100, 120], [10, 20, 30], 50)
	ga1 = GeneticAlgorithm(knapsack1, 200)
	#ga1.initTime()
	gplot = GUI_plot(0, int(log2(50)), ga1)
	#gplot.test()