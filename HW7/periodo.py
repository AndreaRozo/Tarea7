# Universidad de los Andes
# Fisica computacional
# Tarea 7
# Archivo con el programa para calcular el periodo de oscilacion en dias y el radio de equilibrio en cm
# Autores:
#	Andres Felipe Garcia Albarracin
#	Andrea Rozo Mendez

# Librerias
import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pylab
import scipy
from scipy.fftpack import fft, fftfreq

if (len(sys.argv)!= 2):
	print "Se necesita un parametro"
	sys.exit()
    
# Lectura del archivo
c = np.loadtxt('%s'%sys.argv[1])

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

# Periodo - Hallar el Maximo
m = np.where(f2 == f2.max())
freqMax = float(freq_shifted[m[0]])
per = 1/freqMax
dias = (per*1000)/(24*3600)

# Creacion del archivo de salida
archivoSalida = open('period_amplitude.txt','w')
archivoSalida.write('Periodo: %.6f dias\n'%dias)
archivoSalida.write('Radio de equilibrio: %.6f cm\n'%valorMedio)
archivoSalida.close()

