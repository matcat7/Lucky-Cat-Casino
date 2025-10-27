import json
import matplotlib.pyplot as plt
import sys

filename = sys.argv[1]
user = sys.argv[2]

with open (filename, 'r') as file:
    data = json.load(file)

balances = data['balance-history']
graphX = []
for i in range(len(balances)):
    graphX.append(f"Game {i + 1}")

ax = plt.subplot(111)

ax.plot(graphX, balances)

plt.gcf().canvas.manager.set_window_title("Balances")
plt.title(f"{user}'s Balance ($) Over Games Played")
plt.xlabel("Games played")
plt.ylabel("Balance in dollars")
plt.show()
