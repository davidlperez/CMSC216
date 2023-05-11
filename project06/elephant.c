#include "elephant.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Elephant *new_elephant(const char name[], enum type which_type, unsigned int id, unsigned short weight, float trunk_length) {
    Elephant *elephant_ptr;
    size_t name_len;
    
    if (name == NULL) {
        return NULL;
    }
    elephant_ptr = malloc(sizeof(Elephant));
    if (elephant_ptr == NULL) {
        return NULL;
    }
    name_len = strlen(name);
    elephant_ptr->name = malloc(name_len + 1);
    if (elephant_ptr->name == NULL) {
        free(elephant_ptr);
        return NULL;
    }
    strcpy(elephant_ptr->name, name);
    elephant_ptr->elephant_type = which_type;
    elephant_ptr->id = id;
    elephant_ptr->weight = weight;
    elephant_ptr->trunk_length = trunk_length;
    return elephant_ptr;
}

unsigned short get_type(const Elephant *const el_ptr, enum type *const type_ptr) {
    if (el_ptr == NULL || type_ptr == NULL) {
        return 0;
    }
    *type_ptr = el_ptr->elephant_type;
    return 1;
}

const char *get_name(const Elephant *const el_ptr) {
    size_t name_len;
    char *name_copy;

    if (el_ptr == NULL || el_ptr->name == NULL) {
        return NULL;
    }
    name_len = strlen(el_ptr->name);
    name_copy = malloc(name_len + 1);
    if (name_copy == NULL) {
        return NULL;
    }
    strcpy(name_copy, el_ptr->name);
    return name_copy;
}

void print_elephant(const Elephant *const el_ptr) {
    if (el_ptr == NULL || el_ptr->name == NULL) {
        return;
    }
    printf("%s ", el_ptr->name);
    switch (el_ptr->elephant_type) {
    case AFRICAN:
        printf("AFRICAN ");
        break;
    case ASIAN:
        printf("ASIAN ");
        break;
    }
    printf("%u %hu %g\n", el_ptr->id, el_ptr->weight, el_ptr->trunk_length);
}

short compare(const Elephant *const el_ptr1, const Elephant *const el_ptr2) {
    if (el_ptr1 == NULL || el_ptr1->name == NULL ||
        el_ptr2 == NULL || el_ptr2->name == NULL) {
        return -1;
    }
    if (el_ptr1 == el_ptr2) {
        return 1;
    }
    if (strcmp(el_ptr1->name, el_ptr2->name) != 0 ||
        el_ptr1->elephant_type != el_ptr2->elephant_type ||
        el_ptr1->id != el_ptr2->id ||
        el_ptr1->weight != el_ptr2->weight ||
        el_ptr1->trunk_length != el_ptr2->trunk_length) {
        return 0;
    }
    return 1;
}

unsigned short change_name(Elephant *const el_ptr, const char new_name[]) {
    if (el_ptr == NULL || new_name == NULL) {
        return 0;
    }
    if (el_ptr->name != NULL) {
        free(el_ptr->name);
    }
    el_ptr->name = malloc((strlen(new_name) + 1) * sizeof(char));
    if (el_ptr->name == NULL) {
        return 0;
    }
    strcpy(el_ptr->name, new_name);
    return 1;
}

unsigned short copy(Elephant *const el_ptr1, const Elephant *const el_ptr2) {
    if (el_ptr1 == NULL || el_ptr2 == NULL ||
        el_ptr2->name == NULL) {
        return 0;
    }
    free(el_ptr1->name);
    el_ptr1->name = malloc(strlen(el_ptr2->name) + 1);
    if (el_ptr1->name == NULL) {
        return 0;
    }
    strcpy(el_ptr1->name, el_ptr2->name);
    el_ptr1->elephant_type = el_ptr2->elephant_type;
    el_ptr1->id = el_ptr2->id;
    el_ptr1->weight = el_ptr2->weight;
    el_ptr1->trunk_length = el_ptr2->trunk_length;
    return 1;
}

