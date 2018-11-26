import matplotlib.pyplot as plt

file = open("data.txt",'r')
points = file.read()
file.close()

control = points.strip().split(" ")
control = [float(i) for i in control]
x = list(range(len(control)))

file = open("data-alr-9999.txt",'r')
points = file.read()
file.close()

alr9999 = points.strip().split(" ")
alr9999 = [float(i) for i in alr9999]

file = open("data-alr-99992.txt",'r')
points = file.read()
file.close()

alr99992 = points.strip().split(" ")
alr99992 = [float(i) for i in alr99992]

file = open("data-alr-99993.txt",'r')
points = file.read()
file.close()

alr99993 = points.strip().split(" ")
alr99993 = [float(i) for i in alr99993]

file = open("data-alr-99993-wmin.txt",'r')
points = file.read()
file.close()

alr99993_wmin = points.strip().split(" ")
alr99993_wmin = [float(i) for i in alr99993_wmin]

file = open("data-alr-99992-wmin.txt",'r')
points = file.read()
file.close()

alr99992_wmin = points.strip().split(" ")
alr99992_wmin = [float(i) for i in alr99992_wmin]

plt.title("Percentage Change w/ EDA Learning Rates") #Exponentialy Decaying Adaptive
plt.ylabel('Percentage Change (%)')
plt.xlabel('Number of Generations (hundreds)')
plt.ylim((50,100))
# 'b', 'g', 'r', 'c', 'm', 'y', 'k', 'w'
plt.plot(x, control, 'b', label='control')
plt.plot(x, alr9999, 'g', label='alr9999')
plt.plot(x, alr99992, 'r', label='alr99992')
plt.plot(x, alr99993, 'c', label='alr99993')
plt.plot(x, alr99992_wmin, 'y', label='alr99992_wmin')
plt.plot(x, alr99993_wmin, 'k', label='alr99993_wmin')
plt.legend()
plt.show()

# x = list(range(500))
# learning_rate = [0.999**(i) for i in x]#[(1/(0.9995**(i)) - 1) for i in x] #0.995
# plt.plot(x, learning_rate)
# plt.show()