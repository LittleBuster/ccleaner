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

#ifndef __CLEANER_H__
#define __CLEANER_H__

#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;


class ICleaner
{
public:
    virtual void setParams(unsigned interval, const string &folder1, const string &folder2) = 0;
    virtual void start(void) = 0;
    virtual void clean(void) = 0;
};


class Cleaner: public ICleaner
{
private:
    io_service io;
    shared_ptr<deadline_timer> timer;
    unsigned interval;
    string folder1;
    string folder2;

public:
    /**
     * Set cleaner params
     * @interval: cleaner timer interval
     * @folder1: temp folder for clean #1
     * @folder1: temp folder for clean #2
     */
    inline void setParams(unsigned interval, const string &folder1, const string &folder2) {
        this->interval = interval;
        this->folder1 = folder1;
        this->folder2 = folder2;
    }

    /*
     * Start cleaner timer
     */
    void start(void);

    /*
     * Clean timer callback
     */
    void clean(void);
};


#endif
