
#include "dictionaries/dictionaries.h"
#include "rgoc/systemlib/objects.h"

extern "C" {

    // Typedefs for convenience
    typedef struct class_Dictionary  class_Dictionary;
    typedef struct Dictionary_vTable Dictionary_vTable;

    // Method declarations
    void Dictionary_public_Constructor(class_Dictionary*);
    void Dictionary_public_Die(void*);

    // The class' vTable (must contain these three things)
    struct Dictionary_vTable {
            const Any_vTable *parentVTable;
            const char *className;
            DiePointer dieFunction;
    };

    // The class' struct
    struct class_Dictionary {
        // these things MUST be the first things in your struct
        const Dictionary_vTable *vtable;
        int referenceCounter;

        rect_dictionaries::Dictionary* _instance;
    };

    // This constant holds the values of your vTable
    const Dictionary_vTable Dictionary_vTable_Const = { NULL, "Dictionary", &Dictionary_public_Die };

    // Method definitions
    // ==================
    void Dictionary_public_Constructor(class_Dictionary* self) {
        self->vtable = &Dictionary_vTable_Const;
        self->referenceCounter = 0;

        self->_instance = new rect_dictionaries::Dictionary();
    }

    int Dictionary_public_Set(class_Dictionary* self, class_String* p_key, class_Any* p_value) {
        return self->_instance->Set(p_key, p_value);
    }

    class_String* Dictionary_public_Get(class_Dictionary* self, class_String* p_key) {
        self->_instance->Get(p_key);
    }

    void Dictionary_public_Remove(class_Dictionary* self, class_String* p_key) {
        self->_instance->Remove(p_key);
    }

    void Dictionary_public_Clear(class_Dictionary* self) {
        self->_instance->Clear();
    }

    int Dictionary_public_Length(class_Dictionary* self) {
        return self->_instance->Length();
    }

    class_Array* Dictionary_public_Keys(class_Dictionary* self) {
        return self->_instance->Keys();
    }

    void Dictionary_public_Die(void *self) {
        // nothing to do here
    }
}
