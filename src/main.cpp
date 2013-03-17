/*################################################################################
-*- coding: utf-8 -*-

Filename: main.cpp

Copyright (C) 2013 -  You-Tang Lee (YodaLee) <lc85301@gmail.com>
All Rights reserved.

This file is part of project: FDTD.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
################################################################################*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

#include "FDTD.h"

int usage()
{
	cerr << "usage:\n FDTD -C capacitance -L inductance -f frequency" << endl;
	exit(EXIT_FAILURE);
}

int main (int argc, char *argv[])
{
	double capacitance = 1;
	double inductance = 1;
	double frequency = 1;
	int sec = 20;
    char c;
    while((c=getopt(argc, argv, "hC:L:f:s:")) != -1)
    {
        switch(c)
        {
            case 'h':		//show help
				usage();
                return 0;
            case 'C':		//set structure capacitance
				capacitance = atof(optarg);
                break;
            case 'L':		//set structure inductance
                inductance = atof(optarg);
                break;
            case 'f':		//set simulation frequency
                frequency = atof(optarg);
                break;
			case 's':
				sec = atoi(optarg);
				break;
            default:
				cerr << "Wrong Command" << endl;
				return EXIT_FAILURE;
        }
    }

    FDTD fdtd (capacitance, inductance, frequency, sec);
    fdtd.solve ();

    return EXIT_SUCCESS;
}
