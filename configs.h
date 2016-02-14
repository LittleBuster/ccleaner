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

#ifndef __CONFIGS_H__
#define __CONFIGS_H__

#include <string>

using namespace std;


typedef struct {
    unsigned delay;
    string folder1;
    string folder2;
} CleanCfg;


class IConfigs
{
public:
    virtual CleanCfg* getCleanCfg(void) = 0;
    virtual void load(const string &fname) = 0;
};


class Configs: public IConfigs
{
private:
    CleanCfg cc;

public:
    /*
     * Get configs
     */
    inline CleanCfg* getCleanCfg(void) {
        return &cc;
    }

    /*
     * Load configs from json file
     */
    void load(const string &fname);
};


#endif
