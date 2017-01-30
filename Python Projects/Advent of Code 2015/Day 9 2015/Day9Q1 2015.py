# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/30/2017
School:     Arizona State University
Websites:   http://adventofcode.com/2015/day/9
Info:       --- Day 9: All in a Single Night ---
Mathematica:    http://reference.wolfram.com/language/ref/EdgeWeight.html
                http://reference.wolfram.com/language/ref/FindHamiltonianPath.html
                http://reference.wolfram.com/language/GraphUtilities/ref/GraphDistance.html
"""

with open('Day9Q1 2015 Input.txt') as file:

    count = 0
    graph_str = 'Graph[{'
    edge_str = 'EdgeWeight -> {'

    for line in file:

        line = line.split()

        if count != 0:

            graph_str += ', '
            edge_str += ', '

        graph_str += line[0] + ' <-> ' + line[2]
        edge_str += line[4]
        count += 1

graph_str += '}, '
edge_str += '}]'

print(graph_str + edge_str)  # This should generate code to make an undirected, weighted graph in Mathematica 11.

"""
Graph[{Tristram <-> AlphaCentauri, Tristram <-> Snowdin, Tristram <-> Tambi, Tristram <-> Faerun, Tristram <-> Norrath,
Tristram <-> Straylight, Tristram <-> Arbre, AlphaCentauri <-> Snowdin, AlphaCentauri <-> Tambi, AlphaCentauri <->
Faerun, AlphaCentauri <-> Norrath, AlphaCentauri <-> Straylight, AlphaCentauri <-> Arbre, Snowdin <-> Tambi, Snowdin <->
Faerun, Snowdin <-> Norrath, Snowdin <-> Straylight, Snowdin <-> Arbre, Tambi <-> Faerun, Tambi <-> Norrath, Tambi <->
Straylight, Tambi <-> Arbre, Faerun <-> Norrath, Faerun <-> Straylight, Faerun <-> Arbre, Norrath <-> Straylight,
Norrath <-> Arbre, Straylight <-> Arbre}, EdgeWeight -> {34, 100, 63, 108, 111, 89, 132, 4, 79, 44, 147, 133, 74, 105,
95, 48, 88, 7, 68, 134, 107, 40, 11, 66, 144, 115, 135, 127}]
"""
