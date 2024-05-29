#STEP FITTING
from matplotlib import pyplot as plt
import pandas as pd
import control
import numpy
import matplotlib.pyplot as plt
import tbcontrol
import scipy.optimize
from tbcontrol.responses import fopdt, sopdt
from ipywidgets import interact
import numpy as np


filename = "step_acq.xlsx"

df = pd.read_excel(filename)
time = np.arange(0, 19, 0.01)
Y_ref = df["ROLL_REF"][4700:6600]
Y     = df["ROLL"][4700:6600]+3.9*3.14/180
[K, tau, theta, y0], _ = scipy.optimize.curve_fit(fopdt, time, Y, [2, 4, 1, 10])
[K_2, tau_2, zeta_2, theta_2, y0_2], _ = scipy.optimize.curve_fit(sopdt, time, Y, [2, 2, 1.5, 1, 10])
plt.plot(time, Y)
plt.plot(time, Y_ref)
#plt.plot(time, fopdt(time, K, tau, theta, y0), color='red', label='FOPDT fit')
plt.plot(time, sopdt(time, K_2, tau_2, zeta_2, theta_2, y0_2), color='red', label='SOPDT fit')
plt.grid()
plt.show()


