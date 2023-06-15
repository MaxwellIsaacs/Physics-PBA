import matplotlib.pyplot as plt
import numpy as np

# Provided data
coil_turns = [125, 150, 175]
experimental_weight = [63, 75.6, 88.2]

# linear regression coefficients (from C++ script)
slope = 0.5571428571428572
intercept = -34.45714285714287

# scatter plot: Coil Turns vs Experimental Weight
plt.figure(figsize=(8, 6))
plt.scatter(coil_turns, experimental_weight, c='b', label='Data')
plt.xlabel('Coil Turns')
plt.ylabel('Experimental Weight (grams)')
plt.title('Coil Turns vs Experimental Weight')
plt.legend()

# line of best fit
x = np.array(coil_turns)
y = slope * x + intercept
plt.plot(x, y, color='r', label='Line of Best Fit')
plt.legend()

plt.show()
