
#include <map>
#include <string>

#include "rgoc/systemlib/objects.h"

#ifndef __RECT_DICTIONARIES_H_
#define __RECT_DICTIONARIES_H_

namespace rect_dictionaries {

    class Dictionary {

        public:

            Dictionary() {};

            int Set(class_String* p_key, class_Any* p_value);
            class_Any* Get(class_String* p_key);
            void Remove(class_String* p_key);
            void Clear();
            int Length();
            class_Array* Keys();

            ~Dictionary() {};

        private:
            std::map<std::string, class_Any*> _data;
    };
}

#endif // __RECT_DICTIONARIES_H_
