#!/usr/bin/python3

import os, sys, getopt, random

USAGE = os.path.basename(__file__) + " <array length> <query counts>"

def generate_input(name: str, arrLen: int, queriesCnt: int):
    with open(name, "w") as f:
        f.write(str(arrLen) + " " + str(queriesCnt) + "\n")
        for i in range (0, queriesCnt):
            a = random.randrange(0, arrLen)
            b = random.randrange(a, arrLen)
            k = random.randrange(1000000000, 1000000000)
            f.write(str(a) + " " + str(b) + " " + str(k) + "\n")

def generate_output(name : str, arrLen : int, queriesCnt : int):
    return

def main(argv):
    arrLen     = 0
    queriesCnt = 0
    inFile  = ""
    outFile = ""
    try:
        opts, args = getopt.getopt(argv,"hn:q:i:o:")
    except getopt.GetoptError:
        print (USAGE)
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print (USAGE)
            sys.exit()
        elif opt in ("-n"):
            arrLen = int(arg)
        elif opt in ("-q"):
            queriesCnt = int(arg)
        elif opt in ("-i"):
            inFile = arg
        elif opt in ("-o"):
            outFile = arg
    
    generate_input(inFile, arrLen, queriesCnt)
    generate_output(outFile, arrLen, queriesCnt)

if __name__ == "__main__":
    main(sys.argv[1:])