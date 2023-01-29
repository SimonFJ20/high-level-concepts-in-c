#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct HasValuePredicate {
    void (*destroy)(struct HasValuePredicate*);
    bool (*call)(struct HasValuePredicate*, int);
} HasValuePredicate;

bool hasValue(int* values, size_t values_size, HasValuePredicate* predicate)
{
    for (size_t i = 0; i < values_size; ++i)
        if (predicate->call(predicate, values[i]))
            return true;
    return false;
}

typedef struct HasValuePredicate_ContainsTarget {
    void (*destroy)(struct HasValuePredicate_ContainsTarget*);
    bool (*call)(struct HasValuePredicate_ContainsTarget*, int);
    int target;
} HasValuePredicate_ContainsTarget;

void destroy_has_value_predicate_contains_target(
    HasValuePredicate_ContainsTarget* self)
{
    (void)self;
}

bool has_value_predicate_contains_target_call(
    HasValuePredicate_ContainsTarget* self, int value)
{
    return value == self->target;
}

void construc_has_value_predicate_contains_target(
    HasValuePredicate_ContainsTarget* self, int target)
{
    *self = (HasValuePredicate_ContainsTarget) {
        .destroy = destroy_has_value_predicate_contains_target,
        .call = has_value_predicate_contains_target_call,
        .target = target,
    };
}

int main()
{
    int target = 2;
    int values[] = { 1, 2, 3 };

    HasValuePredicate_ContainsTarget predicate;
    construc_has_value_predicate_contains_target(&predicate, 2);

    bool containsTarget
        = hasValue(values, sizeof(values), (HasValuePredicate*)&predicate);
    if (containsTarget)
        printf("contains '%d'\n", target);
}
