/* Cache cleaner
 *
 * Copyright (C) 2016 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence 3
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 */

#include "cleaner.h"
#include <iostream>
#include <boost/bind.hpp>
#include <boost/filesystem.hpp>

using namespace std;


void Cleaner::start()
{
    this->timer = make_shared<deadline_timer>(io, boost::posix_time::seconds(this->interval));
    this->timer->async_wait(boost::bind(&Cleaner::clean, this));
    io.run();
}

void Cleaner::clean()
{
    try {
        boost::filesystem::remove(boost::filesystem::path(folder1));
    }
    catch (...) {
        cout << "Can not delete folder \"" << folder1 << "\"" << endl;
    }
    try {
        boost::filesystem::remove(boost::filesystem::path(folder2));
    }
    catch (...) {
        cout << "Can not delete folder \"" << folder2 << "\"" << endl;
    }
    timer->expires_at(timer->expires_at() + boost::posix_time::seconds(this->interval));
    timer->async_wait(boost::bind(&Cleaner::clean, this));
}
