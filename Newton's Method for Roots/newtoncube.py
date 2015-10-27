# Created by Brian Mascitello to calculate x^3 polynomials and below.

def newtoncube(a, b, c, d, x0):
    """ function newton(a, b, c, d, x0) finds a root of the nonlinear function
        specified by f and fprime. y = a*x^3 + b*x^2 + c*x + d;
        yprime = 3*a*x^2 + 2*b*x + c; Result x is the root. """

    epsilon = 2.2204*10**-16
    """ governs precision of convergence
        where 2.2204*10**-16 = machine epsilion in python """
        
    print "f(x) = %dx^3 + %dx^2 + %dx + %d" % (a, b, c, d)

    x = x0
    xprevious = 0
    k = 0

    while abs(float(a*x**3 + b*x**2 + c*x + d)) > epsilon*abs(float(a*x0**3 + b*x0**2 + c*x0 + d)) and k < 20:
        k = k+1
        xprevious = x
        x = float(x) - (float(a*x**3 + b*x**2 + c*x + d)/float(3*a*x**2 + 2*b*x + c))
        change = abs(float(x - xprevious))
        residual = a*x**3 + b*x**2 + c*x + d
        print "Iteration: %d, Root: %f, Change: %f, Residual: %f" % (k,x,change,residual)
    
    print "Root at",x,"\n"

    return float(x)

newtoncube(3, -2, 7, -1, 10)
newtoncube(1, -5, 0, -3, 10)
