import matplotlib.pyplot as plt
import numpy as np

with open('datos.txt', 'r') as file:
    lines = file.readlines()

# número de grupos desde la primera linea
num_groups = int(lines[0])

# nombres de las etiquetas desde la 2da linea
labels = lines[1].split()

# almacenar los grupos de números flotantes
groups = [[] for _ in range(num_groups)]

# Inicializar una variable para rastrear el grupo actual
current_group = 0

# Procesa el archivo desde la 3ra linea y utiliza "//" para separar los grupos
for line in lines[2:]:
    line = line.strip()
    if line == "//":
        current_group += 1
    else:
        groups[current_group].append(float(line))

# Crear y mostrar los histogramas en ventanas separadas con etiquetas
# personalizadas para cada grupo
for i in range(num_groups):
    plt.figure()  # Crea una nueva ventana de graficos
    plt.hist(groups[i], bins=20, edgecolor='k')
    plt.title(f'Histograma de {labels[i]}')
    plt.xlabel('Valor')
    plt.ylabel('Frecuencia')

# Mostrar todas las ventanas de graficos
plt.show()
