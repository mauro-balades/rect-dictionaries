
#include <map>
#include <string>

#include "rgoc/systemlib/objects.h"

#ifndef __RECT_DICTIONARIES_H_
#define __RECT_DICTIONARIES_H_

namespace rect_dictionaries {

    template <class T>
    class Dictionary : public std::map<std::string, T> {

        public:

            Dictionary();

            void Set(class_String*, class_Any*);
            class_String* Get(class_String*);
            void Remove(class_String*);
            void Clear();
            int Length();
            class_Array* Keys();

            ~Dictionary();

        // private:

    };
}

#endif // __RECT_DICTIONARIES_H_
