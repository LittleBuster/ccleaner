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

#include "app.h"
#include <iostream>
#include <boost/thread.hpp>

using namespace std;


App::App(const shared_ptr<IConfigs> &cfg, const shared_ptr<ICleaner> &cleaner)
{
    m_cfg = cfg;
    m_cleaner = cleaner;
}

int App::start()
{
    try {
        m_cfg->load("/etc/ccleaner.cfg");
    }
    catch (const string &err) {
        cout << "[CONFIGS]: " + err << endl;
        return -1;
    }
    auto cc = m_cfg->getCleanCfg();
    m_cleaner->setParams(cc->delay, cc->folder1, cc->folder2);
    m_cleaner->start();

    for (;;) {
        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }
    return 0;
}
