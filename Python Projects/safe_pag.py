import pyautogui as pag
import time


def break_loop_top_screen():
    """
    Use in other files with:

    import pyautogui as pag
    import safe_pag_functions as spag
    if spag.break_loop_top_screen():
        break

    to check if the cursor is located at the top of the screen, and will break the loop running pyautogui.
    :return: True if cursor is located at the top of the screen. Otherwise False.
    """

    current_mouse_x, current_mouse_y = pag.position()
    if current_mouse_y == 0:
        print('Exited loop via mouse position.')
        return True
    else:
        return False


def center_mouse_on_screen():
    screen_width, screen_height = get_screen_dimensions(print_on=False)
    pag.moveTo(screen_width // 2, screen_height // 2)


def get_screen_dimensions(print_on=True):
    screen_width, screen_height = pag.size()

    if print_on:
        print(f'Screen width: {screen_width} pixels.')
        print(f'Screen height: {screen_height} pixels.')

    return screen_width, screen_height


def run_first(delay=3, failsafe=True, pause=0.5, printer=True):
    screen_width, screen_height = get_screen_dimensions(print_on=printer)
    setup_failsafes(pause_float=pause, failsafe_boolean=failsafe)
    start_delay(time_in_seconds=delay)
    return screen_width, screen_height


def setup_failsafes(pause_float=0.10, failsafe_boolean=True):
    # Set up a pause_float second pause after each PyAutoGUI call:
    pag.PAUSE = pause_float

    # When fail-safe mode is True, moving the mouse to the upper-left will raise a pyautogui.FailSafeException
    # that can abort your program:
    pag.FAILSAFE = failsafe_boolean

    print(f'PAUSE: {pause_float} seconds.')
    print(f'FAILSAFE: {failsafe_boolean}.')


def start_delay(time_in_seconds=3):
    print(f'Starting in {time_in_seconds} seconds...')

    while time_in_seconds > 0:
        print(f'{time_in_seconds}')
        time.sleep(1.0)
        time_in_seconds = time_in_seconds - 1

    print('Program Commencing!')
