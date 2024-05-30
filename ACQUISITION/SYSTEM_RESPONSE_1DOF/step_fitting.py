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
from tbcontrol.numeric import skogestad_half


filename = "step_acq.xlsx"

df = pd.read_excel(filename)
time = np.arange(0, 19, 0.01)
Y_ref = df["ROLL_REF"][4700:6600]
Y     = df["ROLL"][4700:6600]+3.9*3.14/180

def plotstep(G, D, T=None):
    t, y = control.step_response(G, T=15)
    new_t = numpy.concatenate([[0], t + D])
    new_y = numpy.concatenate([[0], y])
    plt.plot(new_t, new_y)

def step_fitting(Y):
    [K, tau, theta, y0], _ = scipy.optimize.curve_fit(fopdt, time, Y, [2, 4, 1, 10])
    [K_2, tau_2, zeta_2, theta_2, y0_2], _ = scipy.optimize.curve_fit(sopdt, time, Y, [2, 2, 1.5, 1, 10])
    plt.plot(time, Y)
    plt.plot(time, Y_ref)
    plt.plot(time, sopdt(time, K_2, tau_2, zeta_2, theta_2, y0_2), color='red', label='SOPDT fit')
    print([K_2, tau_2, zeta_2, theta_2, y0_2])
    plt.grid()
    plt.show()
    return()

# LIBRARY TEST
step_fitting(Y)
print()
