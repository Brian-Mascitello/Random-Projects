% Modified by Brian Mascitello to calculate x^3 polynomials
% and below.

function newtoncube(a, b, c, d, x0)
% function newton(a, b, c, d, x0) finds a root of the
% nonlinear function specified by f and fprime.
% y = a*x^3 + b*x^2 + c*x + d;
% yprime = 3*a*x^2 + 2*b*x + c;
% Result x is the root.
% Set Command Window to "format long" to see longer x values.

epsilon = eps; % governs precision of convergence where
% eps = machine epsilion in MATLAB

% sometimes can't achieve eps; can take epsilon = 10^-6 for example
x = x0;
xprev = 0;
k = 0;

% while abs(x-xprev) > epsilon*abs(x) && k < 20
while abs(f(x)) > epsilon*abs(f(x0)) && k < 20
    k = k+1
    xprev = x;
    x = x - f(x)/fprime(x)
    change = abs(x-xprev)
    residual = f(x)
end

    function y = f(x)
    y = a*x^3 + b*x^2 + c*x + d;
    end

    function yprime = fprime(x)
    yprime = 3*a*x^2 + 2*b*x + c;
    end

end