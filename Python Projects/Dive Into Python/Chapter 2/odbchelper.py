"""
Example 2.1. odbchelper.py
If you have not already done so, you can download this and other examples
(http://diveintopython.org/download/diveintopython−examples−5.4.zip) used in this book.
"""

def buildConnectionString(params):
    """Build a connection string from a dictionary of parameters.
    Returns string."""
    
    return ";".join(["%s=%s" % (k, v) for k, v in params.items()])
    
if __name__ == "__main__":
    myParams = {"server":"mpilgrim", \
                "database":"master", \
                "uid":"sa", \
                "pwd":"secret" \
                }           
    print(buildConnectionString(myParams)) # Had to add parenthesis.
    
# Output is "pwd=secret;database=master;server=mpilgrim;uid=sa"