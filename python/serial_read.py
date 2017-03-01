#!/usr/bin/env python

import serial, argparse 
import matplotlib.pyplot as plt
import numpy as np


def main():
    # crate parser
    parser = argparse.ArgumentParser(description="LDR serial");
    # get expected argument
    parser.add_argument('--port', dest='port', required=True);
    # parse
    args = parser.parse_args();

    # get port
    strPort = args.port;

    print 'reading data... \n'
    # create serial
    read_serial = True;
    ser = serial.Serial(strPort, 9600);

    while read_serial:
        try:
            line = ser.readline();
            print line, '\n'
        except KeyboardInterrupt:
            read_serial = False
            ser.flush();
            ser.close();
            print '\n exiting...'


# call main
if __name__ == '__main__':
    main()
