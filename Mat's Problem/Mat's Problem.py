# Created by Brian Mascitello to calculate a specific
# polynomial's root given to me by Mat at Intel.

def matsproblem(x0):
    """ function matsproblem(x0) finds a root of the nonlinear
        function specified by f and fprime. y = 2 ** x - 3 ** (x / 2) - 1;
        yprime = 0.693147 * (2 ** x) - (1.098612 * 3 ** (x / 2)) / 2; Result
        x is the root. """

    epsilon = 2.2204*10**-16
    """ governs precision of convergence
        where 2.2204*10**-16 = machine epsilion in python """
    
    x = x0
    xprevious = 0
    k = 0

    while abs(float(2 ** x - 3 ** (x / 2) - 1)) > epsilon*abs(float(2 ** x0 - 3 ** (x0 / 2) - 1)) and k < 20:
        k = k+1
        xprevious = x
        x = float(x) - (float(2 ** x - 3 ** (x / 2) - 1)/float(0.693147 * (2 ** x) - (1.098612 * 3 ** (x / 2)) / 2))
        change = abs(float(x - xprevious))
        residual = 2 ** x - 3 ** (x / 2) - 1
        print("Iteration: %d, Root: %f, Change: %f, Residual: %f" % (k,x,change,residual))
    
    print("Root at",x,"\n")

    return float(x)

print("y = 2 ** x - 3 ** (x / 2) - 1")
print("yprime = 0.693147 * (2 ** x) - (1.098612 * 3 ** (x / 2)) / 2")
print("Machine epsilon set as: 2.2204*10^-16")
x0 = float(input("Please enter your guess of the root: "))
matsproblem(x0)
