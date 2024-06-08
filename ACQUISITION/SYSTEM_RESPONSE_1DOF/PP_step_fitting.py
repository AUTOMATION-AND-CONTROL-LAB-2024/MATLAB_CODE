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
from scipy.io import loadmat 

filename = "step_acq.xlsx"

df = pd.read_excel(filename, sheet_name = 'PP')
time = np.arange(0, 14, 0.01)
size = [18700,20100]
Y_ref = df["ROLL_REF"][size[0]:size[1]]#[4700:6600]
Y     = df["PITCH"][size[0]:size[1]]*-1-0.035

#TEST
# plt.plot(Y)
# plt.plot(Y_ref)
# plt.show()


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
    plt.title('1-dof PP Step Fitting')
    plt.grid()
    plt.legend()
    plt.show()
    return()

# LIBRARY TEST
step_fitting(Y)
