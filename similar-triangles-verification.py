#!/usr/bin/python
# -*- coding: utf-8 -*-


import sys
import getopt
import numpy as np
from datetime import datetime

#===========================================
def main():
#===========================================
    opts, argv = getopt.getopt(sys.argv[1:],'h',['help'])	
    print 'commandline parameters:'
    print 'argv:', type(argv), argv
    print 'opts:', type(opts), opts
    for o in opts:
    	if o in ("-h", "--help"):
	    helpInfo()
                        
    if len(argv) == 0:
    	helpInfo()
	exit()

    elif len(argv) != 6:
	helpInfo()
	exit()
    
    else:
	memory = [int(argv[0]), int(argv[1]), int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5])]

    index = 0
    R_1 = 0
    R_2 = 0
    product_1 = 0
    product_2 = 0

    while index < 2:
        if index == 1:
            bubbleSort(3, memory)
        else:
            bubbleSort(0, memory)
        index = index + 1

    R_1 = memory[0]
    R_2 = memory[4]
    product_1 = R_1 * R_2
    R_1 = memory[1]
    R_2 = memory[3]
    product_2 = R_1 * R_2
    if product_1 == product_2:
	R_1 = memory[0]
	R_2 = memory[5]
	product_1 = R_1 * R_2
	R_1 = memory[2]
	R_2 = memory[3]
	product_2 = R_1 * R_2
        if product_1 == product_2:
            print 'these 2 triangles are similar!'
        else:
	    print 'these 2 triangles are not similar!'
    else:
        print 'these 2 triangles are not similar!'


#===========================================
def bubbleSort(dataIndex, memory):
#===========================================
    R_1 = 0
    R_2 = 0
    flag = True
    while flag == True:
	dataCounter = dataIndex
	flag = False
	while dataCounter < dataIndex + 2:
	    R_1= memory[dataCounter]
	    R_2= memory[dataCounter + 1]
	    if memory[dataCounter] < memory[dataCounter + 1]:
		memory[dataCounter + 1] = R_1
		memory[dataCounter] = R_2
		flag = True
	    dataCounter = dataCounter + 1


#===========================================
def helpInfo():
#===========================================
    print 'input argument error, please input the side lengths of 2 triangles'
    #print 'tplr: calculate total packet loss rate, need parameter <router model> (APU or 150)'

if __name__ == '__main__':
    main()


