# -*- coding: utf-8 -*-
"""
Author: Brian Mascitello
Date:   12/12/2015
School: Arizona State University
Info:   First test program using Spyder (Python 3.5) that is part of the
    Anaconda download. 

Anaconda = <https://www.continuum.io/downloads>

Numpy Reference = <http://docs.scipy.org/doc/numpy-1.10.0/reference/index.html>
"""

# Attempts to import numpy, exception if unable.
try:
    import numpy as np
    print("Numpy imported properly!")
except ImportError:
    print("FAILED numpy import!")

# Should work if numpy is imported = 3
print(np.add(1.0, 2.0))

# Should work either way = 7
print(3.0 + 4.0)