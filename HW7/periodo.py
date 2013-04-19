# Universidad de los Andes
# Fisica computacional
# Tarea 7
# Archivo con el programa para calcular el periodo de oscilacion en dias y el radio de equilibrio en cm
# Autores:
#	Andres Felipe Garcia Albarracin
#	Andrea Rozo Mendez

# Librerias
import os, sys
import numpy as np
import matplotlib.pyplot as plt
import pylab
import scipy
from scipy.fftpack import fft, fftfreq

# Lectura del archivo
c = np.loadtxt('fileOut.txt')

# Tamanio del archivo
(filas,columnas) = np.shape(c)


#Vector del radio
radio = (c[:,1])

#Valor medio de R
valorMedio = np.sum(radio)/filas

#Vector centrado
radioC = (radio-valorMedio)

# Transformada de Fourier
n = filas
dt = 1 							# 1Ks de intervalo
fft_radio = np.fft.fft(radioC)/n 			# Transformada de Fourier normalizada
freq = np.fft.fftfreq(n,dt)				# Vector de frecuencias
fft_radio_shift = np.fft.fftshift(fft_radio)
freq_shifted = np.fft.fftshift(freq)

# Espectro de potencias
f2 = abs(fft_radio_shift)

fig1 = plt.figure()
pylab.plot(freq_shifted,abs(f2))
pylab.xlabel('$algo$')
pylab.ylabel('$algo mas$')
pylab.title('$\mathrm{Espectro\ de\ potencias\ del\ numero\ de\ manchas}$', fontsize=20)
pylab.grid(True)
pylab.savefig('Graph1')

# Maximo
m = np.where(f2 == f2.max())
freqMax = float(freq_shifted[m[0][1]])
per = 1/freqMax
dias = (per*1000)/(24*3600)

# Creacion del archivo de salida

