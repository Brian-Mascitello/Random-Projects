"""
Author:     Brian Mascitello
Date:       12/1/2017
Websites:   http://adventofcode.com/2017/day/1
Info:       --- Day 1: Inverse Captcha ---
            --- Part Two ---
"""


def get_data(input_text):
    with open(input_text) as file:
        data_from_file = file.read()
    file.close()
    return data_from_file


data = get_data('Day1Q1 2017 Input.txt')

captcha_sum = 0
halfway_around = int(len(data) / 2)
for index in range(-1, len(data) - 1):
    if data[index] == data[(index + halfway_around) % len(data)]:
        captcha_sum += int(data[index])

print(captcha_sum)  # 1166
