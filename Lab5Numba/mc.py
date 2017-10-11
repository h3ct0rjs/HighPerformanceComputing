import numpy as np                         # numpy namespace
from timeit import default_timer as timer  # for timing
from matplotlib import pyplot              # for plotting
import math
from numbapro import vectorize

@vectorize(['float64(float64, float64, float64, float64, float64)'], target='gpu')
def step(price, dt, c0, c1, noise):
    return price * math.exp(c0 * dt + c1 * noise)

# Stock information parameters
StockPrice = 20.83
StrikePrice = 21.50
Volatility = 0.021
InterestRate = 0.20
Maturity = 5. / 12.

# monte-carlo simulation parameters
NumPath = 3000000
NumStep = 100

# plotting
MAX_PATH_IN_PLOT = 50

def driver(pricer, do_plot=False):
    paths = np.zeros((NumPath, NumStep + 1), order='F')
    paths[:, 0] = StockPrice
    DT = Maturity / NumStep

    ts = timer()
    pricer(paths, DT, InterestRate, Volatility)
    te = timer()
    elapsed = te - ts

    ST = paths[:, -1]
    PaidOff = np.maximum(paths[:, -1] - StrikePrice, 0)
    print 'Result'
    fmt = '%20s: %s'
    print fmt % ('stock price', np.mean(ST))
    print fmt % ('standard error', np.std(ST) / np.sqrt(NumPath))
    print fmt % ('paid off', np.mean(PaidOff))
    optionprice = np.mean(PaidOff) * np.exp(-InterestRate * Maturity)
    print fmt % ('option price', optionprice)

    print 'Performance'
    NumCompute = NumPath * NumStep
    print fmt % ('Mstep/second', '%.2f' % (NumCompute / elapsed / 1e6))
    print fmt % ('time elapsed', '%.3fs' % (te - ts))
    
    if do_plot:
        pathct = min(NumPath, MAX_PATH_IN_PLOT)
        for i in xrange(pathct):
            pyplot.plot(paths[i])
        print 'Plotting %d/%d paths' % (pathct, NumPath)
        pyplot.show()
