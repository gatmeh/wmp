#!/usr/bin/env python

import os, serial, argparse 
import matplotlib.pyplot as plt
import numpy as np



def main():
    # crate parser
    parser = argparse.ArgumentParser(description="Serial reader");
    # get expected argument
    parser.add_argument('--port', dest='port', required=True, help='serial port');
    parser.add_argument('--dir', dest='dir', required=False, default = '', help='destination directory');
    parser.add_argument('--output', dest='output', required=False, default = 'output.txt', help = 'name of output file');
    # parse
    args = parser.parse_args();

    # get port
    strPort = args.port;
    strDir = args.dir + args.output;

    print 'starting serial reader... \n'
    # create serial
    read_serial = True;
    ser = serial.Serial(strPort, 9600);

    sensor1 = []
    sensor2 = []
    sensor3 = []
    while read_serial:
        try:
            line = ser.readline();
            new_line = line.split("\t")

            if len(new_line)<3:
                print 'waiting for all sensors ...'
                print 'reading and storing serial...'
            else:
                #store values 
                sensor1.append(int(new_line[0]))
                sensor2.append(int(new_line[1]))
                sensor3.append(int(new_line[2]))
        except KeyboardInterrupt:
            read_serial = False
            rows = zip(sensor1,sensor2,sensor3)
            rows_arry = np.array(rows)
            print '\n writing data to', strDir
            np.savetxt(strDir, rows_arry)
            ser.flush();
            ser.close();
            print '\n exiting...'


# call main
if __name__ == '__main__':
    main()
