#include <stdio.h>
#include <stdlib.h>

#define COLLECTION_TEMPLATE(Type)                                              \
    typedef struct {                                                           \
        size_t length;                                                         \
        Type* elements;                                                        \
    } Collection_##Type;                                                       \
                                                                               \
    void construct_collection_##Type(Collection_##Type* self)                  \
    {                                                                          \
        *self = (Collection_##Type) {                                          \
            .length = 0,                                                       \
            .elements = NULL,                                                  \
        };                                                                     \
    }                                                                          \
                                                                               \
    void destroy_collection_##Type(Collection_##Type* self)                    \
    {                                                                          \
        if (self->elements != NULL)                                            \
            free(self->elements);                                              \
    }                                                                          \
                                                                               \
    void collection_##Type##_append(Collection_##Type* self, Type value)       \
    {                                                                          \
        self->length++;                                                        \
        if (self->elements != NULL)                                            \
            self->elements                                                     \
                = realloc(self->elements, sizeof(Type) * self->length);        \
        else                                                                   \
            self->elements = malloc(self->length * sizeof(Type));              \
        self->elements[self->length - 1] = value;                              \
    }                                                                          \
                                                                               \
    Type* collection_##Type##_at(Collection_##Type* self, size_t index)        \
    {                                                                          \
        if (index >= self->length)                                             \
            return NULL;                                                       \
        return &self->elements[index];                                         \
    }

COLLECTION_TEMPLATE(int)

typedef const char* ConstCharArray;
COLLECTION_TEMPLATE(ConstCharArray)

int main()
{
    Collection_int my_ints;
    construct_collection_int(&my_ints);

    collection_int_append(&my_ints, 1);
    printf("%d == 1\n", *collection_int_at(&my_ints, 0));

    collection_int_append(&my_ints, 2);
    collection_int_append(&my_ints, 3);
    printf("%d == 3\n", *collection_int_at(&my_ints, 2));
    printf("%d == 2\n", *collection_int_at(&my_ints, 1));

    destroy_collection_int(&my_ints);

    Collection_ConstCharArray my_strings;
    construct_collection_ConstCharArray(&my_strings);

    collection_ConstCharArray_append(&my_strings, "hello");
    const char** hello_string = collection_ConstCharArray_at(&my_strings, 0);
    printf("%s world!\n", *hello_string);

    destroy_collection_ConstCharArray(&my_strings);
}
