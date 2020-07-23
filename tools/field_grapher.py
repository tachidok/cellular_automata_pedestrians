import os
import sys
import argparse
import matplotlib.pyplot as plt

def graph_field(file_name):
    
    infile = open(file_name+".txt", 'r')
    matrix = []
    temp = []
    temp_numb = []
    for word in infile:
        temp_numb.clear()
        temp = word.rstrip('\n').split(':')
        for i in temp:
            temp_numb.append(float(i))
        matrix.append(temp_numb[:])
    
    plt.imshow(matrix, cmap='gray', interpolation='nearest')
    plt.show()
    
def main():
    
    # Create the parser to deal with the arguments
    parser = argparse.ArgumentParser("Plot room states")
    
    # Set the positional arguments
    parser.add_argument('--RESLT_PATH', dest='RESLT_PATH', type=str, required=True, help='The path with the results')
    
    # parse args
    args = parser.parse_args()
    
    # RESLT folder
    RESLT = args.RESLT_PATH

    print(f"Path to folder: {RESLT}")
    
    graph_field(RESLT + "staticField")
    graph_field(RESLT + "initialPosition")
    graph_field(RESLT + "finalPosition")

if __name__ == '__main__':
    main()
