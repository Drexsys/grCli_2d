//
// Created by drexsys on 02.05.26.
//

#ifndef GRCLI_2D_SSTRING_H
#define GRCLI_2D_SSTRING_H

#include "Object.h"

class SString: public Object {

public:
    SString(short x, short y, const std::string &text);

    void setText(const std::string &text);
};


#endif //GRCLI_2D_SSTRING_H
