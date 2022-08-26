
#include "dictionaries/dictionaries.h"
#include "rgoc/systemlib/objects.h"
#include "rgoc/systemlib/exceptions.h"

#include <utility>

#define ITEM_NOT_FOUND() \
    std::string message = "Dictionary: item '";  \
    exc_Throw( (char*)(message + (const char*)p_key->buffer + "' not found").c_str() ); \

namespace rect_dictionaries {

    int Dictionary::Set(class_String* p_key, class_Any* p_value) {
        return _data.insert(std::make_pair((std::string)p_key->buffer, p_value)).second;
    }

    class_Any* Dictionary::Get(class_String* p_key) {
        std::map<std::string, class_Any*>::iterator item = _data.find(p_key->buffer);
        if (item == _data.end()) {
            ITEM_NOT_FOUND()
        }

        return item->second;
    }

    void Dictionary::Remove(class_String* p_key) {
        std::map<std::string, class_Any*>::iterator item = _data.find(p_key->buffer);
        if (item == _data.end()) {
            ITEM_NOT_FOUND()
        }

        _data.erase(item);
    }

    void Dictionary::Clear() {
        return _data.clear();
    }

    int Dictionary::Length() {
        return _data.size();
    }

    class_Array* Dictionary::Keys() {

    }
}
