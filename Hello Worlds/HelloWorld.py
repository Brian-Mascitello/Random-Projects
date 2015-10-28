"""-------------------------------------------------------------------------
AUTHOR:		Brian Mascitello
DATE:		10/28/2015
EXERCISE:	HelloWorld
SPECIFICATION:	Python Practice - Get a user name and age, then print it back
    to them.
-------------------------------------------------------------------------"""

print("Welcome to Hello World on Python")
name = input("Please enter your first name: ") # variable to store user's name
age = int(input("Please enter your age: ")) # variable to store user's age
print("Hey %s, hope %d is a good year!" % (name, age))
