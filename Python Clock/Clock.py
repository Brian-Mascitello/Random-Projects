"""
Created by Brian Mascitello so I could tell when the UC Berkeley Webinars are in my time.
"""
import datetime
import pytz
import tkinter

# These are the timezones I am concerned with.
arizona = pytz.timezone("America/Phoenix")
california = pytz.timezone("America/Los_Angeles")
new_york = pytz.timezone("America/New_York")

"""
Function tick gets the current time from the user's local machine, finds the conversion to the timezones listed above,
and updates the clock gui with the most recent times every quarter of a second.
"""


def tick():
    # current time of the user's local machine
    local_time = datetime.datetime.now()

    # now is the current Coordinated Universal Time
    now = datetime.datetime.utcnow()

    # converts the times appropriately
    arizona_time = now + arizona.utcoffset(now)
    california_time = now + california.utcoffset(now)
    new_york_time = now + new_york.utcoffset(now)

    # changes the text of the clock to match the new times
    clock.config(
        text="Local Time: " + local_time.strftime("%r") + "\nArizona Time: " + arizona_time.strftime(
            "%r") + "\nCalifornia Time: " + california_time.strftime(
            "%r") + "\nNew York Time: " + new_york_time.strftime("%r"), justify="right")
    clock.after(250, tick)


# loops while the program is running to update the clock
root = tkinter.Tk()
root.title("Brian's Python Clock")
clock = tkinter.Label(root, font=('Verdana', 16))
clock.pack(fill='both', expand=1)
tick()
root.mainloop()
