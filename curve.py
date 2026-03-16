import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 1. Chargement des données (supposons X en col 1, Y en col 2)
data = np.loadtxt("result.dat")
x = data[:, 0]
y = data[:, 1]

# 2. Préparation de la figure
fig, ax = plt.subplots(figsize=(8, 6))
ax.set_xlim(np.min(x), np.max(x)) # Limites fixes pour éviter que l'axe saute
ax.set_ylim(np.min(y) - 1, np.max(y) + 1)
ax.set_xlabel("Axe X")
ax.set_ylabel("Axe Y")
ax.set_title("Évolution temporelle / spatiale")
ax.grid(True)

# Ligne vide qui va se remplir petit à petit
ligne, = ax.plot([], [], 'b-', linewidth=2)

# 3. Fonction d'initialisation
def init():
    ligne.set_data([], [])
    return ligne,

# 4. Fonction de mise à jour (appelée à chaque image de l'animation)
def update(frame):
    # On trace les données du début jusqu'à l'indice 'frame'
    ligne.set_data(x[:frame], y[:frame])
    return ligne,

# 5. Création de l'animation
# frames = len(x) signifie qu'il y aura autant d'images que de points
ani = FuncAnimation(fig, update, frames=len(x), init_func=init, blit=True, interval=50)

# 6. Affichage direct ou Sauvegarde en GIF
plt.show() 
# Pour sauvegarder en GIF, décommente la ligne suivante :
ani.save('mon_animation.gif', writer='pillow', fps=20)