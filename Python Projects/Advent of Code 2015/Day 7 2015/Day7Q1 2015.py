# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/27/2017
School:     Arizona State University
Websites:   http://adventofcode.com/2015/day/7
Info:       --- Day 7: Some Assembly Required ---

    This year, Santa brought little Bobby Tables a set of wires and bitwise logic gates! Unfortunately, little Bobby is
    a little under the recommended age range, and he needs help assembling the circuit.

    Each wire has an identifier (some lowercase letters) and can carry a 16-bit signal (a number from 0 to 65535). A
    signal is provided to each wire by a gate, another wire, or some specific value. Each wire can only get a signal
    from one source, but can provide its signal to multiple destinations. A gate provides no signal until all of its
    inputs have a signal.

    The included instructions booklet describes how to connect the parts together: x AND y -> z means to connect wires x
    and y to an AND gate, and then connect its output to wire z.

    For example:

    123 -> x means that the signal 123 is provided to wire x.
    x AND y -> z means that the bitwise AND of wire x and wire y is provided to wire z.
    p LSHIFT 2 -> q means that the value from wire p is left-shifted by 2 and then provided to wire q.
    NOT e -> f means that the bitwise complement of the value from wire e is provided to wire f.
    Other possible gates include OR (bitwise OR) and RSHIFT (right-shift). If, for some reason, you'd like to emulate
    the circuit instead, almost all programming languages (for example, C, JavaScript, or Python) provide operators for
    these gates.

    For example, here is a simple circuit:

    123 -> x
    456 -> y
    x AND y -> d
    x OR y -> e
    x LSHIFT 2 -> f
    y RSHIFT 2 -> g
    NOT x -> h
    NOT y -> i
    After it is run, these are the signals on the wires:

    d: 72
    e: 507
    f: 492
    g: 114
    h: 65412
    i: 65079
    x: 123
    y: 456
    In little Bobby's kit's instructions booklet (provided as your puzzle input), what signal is ultimately provided to
    wire a?
"""

import re

regex_search_str = '([a-z0-9]+)? ?([A-Z]+)? ?(\S*) -> (\S+)'

with open('Day7Q1 2015 Input.txt') as openfile:

    all_lines = openfile.readlines()

    wires = dict()

    while not("a" in wires and wires["a"] is not None):

        for current_line in all_lines:

            # https://docs.python.org/3.6/library/re.html
            match = re.search(regex_search_str, current_line)

            first = match.group(1)
            bitwise_operator = match.group(2)
            second = match.group(3)
            wire_update = match.group(4)

            if first is not None:
                if first.isdigit():
                    first = int(first)
                else:
                    first = wires[first] if first in wires else None

            if second is not None:
                if second.isdigit():
                    second = int(second)
                else:
                    second = wires[second] if second in wires else None

            if bitwise_operator == 'AND':
                if first is not None and second is not None:
                    wires[wire_update] = first & second

            elif bitwise_operator == 'OR':
                if first is not None and second is not None:
                    wires[wire_update] = first | second

            elif bitwise_operator == 'LSHIFT':
                if first is not None and second is not None:
                    wires[wire_update] = first << second

            elif bitwise_operator == 'RSHIFT':
                if first is not None and second is not None:
                    wires[wire_update] = first >> second

            elif bitwise_operator == 'NOT':
                if second is not None:
                    wires[wire_update] = ~second

            else:
                wires[wire_update] = first

# Need to solve for wire a
print(wires['a'])  # 3176
