/*
*   Calvin Neo
*   Copyright (C) 2017  Calvin Neo <calvinneo@calvinneo.com>
*   https://github.com/CalvinNeo/ARPC
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include "helloworld.pb.h"

using namespace std;

int main(){
    lm::helloworld msg1; 
    msg1.set_id(101); 
    msg1.set_str("hello");
    int size = msg1.ByteSize();
     
    // fstream output("./a.log", ios::out | ios::trunc | ios::binary); 
    // if (!msg1.SerializeToOstream(&std::cout)) { 
    //     puts("Write Failed");
    // }
    // puts("");

    char buf[1000];
    printf("SerializeToArray %d \n", msg1.SerializeToArray((void *)buf, 1000));

    lm::helloworld msg2;
    if(msg2.ParseFromArray((void *)buf, size)){
        printf("ParseFromArray str = %s \n", msg2.str().c_str());
    }else{
        puts("Read Failed");
    }
    return 0;
}
