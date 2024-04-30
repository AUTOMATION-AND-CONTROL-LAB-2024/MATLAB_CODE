import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
import numpy as np


def read_data(filename, num_sheet):
    data = []
    for i in range(num_sheet):
        temp_data = pd.read_excel(filename, sheet_name = 'Motor'+str(i+1))
        temp_data = temp_data.dropna(subset= ['PESO'])
        data.append(temp_data)
    return data

def plot_motor(data, ind):
    x = data['PWM']
    y = data['PESO']*g*gain
    plt.subplot(2,2,ind)
    plt.plot(x,y,'.')
    plt.xlabel('PWM')
    plt.ylabel('THRUST[N]')
    plt.title('WEIGHT-PWM COEFFICIENT')
    plt.grid()

def plot_motor_array(data):
    fig, axes = plt.subplots(2,2, constrained_layout=True)
    for ind, df in enumerate(data, start = 1):
        plot_motor(df, ind)
    plt.show()
    fig.savefig('plots/motor_array.png')

def plot_motor_comparison(data):
    legend = []
    for ind, df in enumerate(data, start = 1):
        x = df['PWM']
        y = df['PESO']*g*gain
        plt.scatter(x,y)
        plt.xlabel('PWM')
        plt.ylabel('THRUST[N]')
        plt.title('WEIGHT-PWM COEFFICIENT')
        legend.append('Motor'+str(ind))
    plt.legend(legend)
    plt.grid()
    plt.savefig('plots/motor_comparison.png')
    plt.show()
    

def plot_motor_LR(data, ind):
    x = data['PWM']
    y = data['PESO']*g*gain
    x = np.array(x).reshape(-1, 1)
    y = np.array(y).reshape(-1, 1)
    model = LinearRegression().fit(x, y)
    score = model.score(x, y)
    X_new = np.array([[100], [500]])
    y_pred = model.predict(X_new)
    plt.subplot(2,2,ind)
    plt.plot(x, y,'.')
    plt.plot(X_new, y_pred, color='red', label='Linear Regression')
    plt.xlabel('PWM')
    plt.ylabel('THRUST[N]')
    plt.title('LR SCORE: %.3f'%(score))
    plt.grid()

def plot_motor_array_LR(data):
    fig, axes = plt.subplots(2,2, constrained_layout=True)
    for ind, df in enumerate(data, start = 1):
        plot_motor_LR(df, ind)
    plt.show()
    fig.savefig('plots/motor_array_LR.png')

def plot_motor_POLY(data, ind):
    x = data['PWM']
    y = data['PESO']*g*gain
    x = np.array(x).reshape(-1, 1)
    y = np.array(y).reshape(-1, 1)
    x_ = PolynomialFeatures(degree=2, include_bias=False).fit_transform(x)
    model = LinearRegression().fit(x_, y)
    score = model.score(x_, y)
    y_pred = model.predict(x_)
    plt.subplot(2,2,ind)
    plt.plot(x, y,'.')
    plt.plot(x_, y_pred, color='red', label='Linear Regression')
    plt.xlabel('PWM')
    plt.ylabel('THRUST[N]')
    plt.title('POLY SCORE: %.3f'%(score))
    plt.grid()

def plot_motor_array_POLY(data):
    fig, axes = plt.subplots(2,2, constrained_layout=True)
    for ind, df in enumerate(data, start = 1):
        plot_motor_POLY(df, ind)
    plt.show()
    fig.savefig('plots/motor_array_POLY.png')


#main
filename = 'data.xlsx'
n_mot = 4
data = read_data(filename, n_mot)
g = 9.81
gain = 0.001
plot_motor_array(data)
plot_motor_comparison(data)
plot_motor_array_LR(data)
plot_motor_array_POLY(data)

