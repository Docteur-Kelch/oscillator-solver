import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

data = np.loadtxt("result.dat")
x = data[:, 0]
y = data[:, 1]

fig, ax = plt.subplots(figsize=(8, 6))
ax.set_xlim(np.min(x), np.max(x))
ax.set_ylim(np.min(y) - 1, np.max(y) + 1)
ax.set_xlabel("Axe X")
ax.set_ylabel("Axe Y")
ax.set_title("Évolution temporelle / spatiale")
ax.grid(True)

ligne, = ax.plot([], [], 'b-', linewidth=2)

def init():
    ligne.set_data([], [])
    return ligne,

def update(frame):
    ligne.set_data(x[:frame], y[:frame])
    return ligne,

ani = FuncAnimation(fig, update, frames=len(x), init_func=init, blit=True, interval=50)

plt.show() 
ani.save('mon_animation.gif', writer='pillow', fps=20)