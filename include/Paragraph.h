#pragma once
#include "Tag.h"

struct P : Tag
{
    P(string const& text) : Tag("p", text) {}
    P(initializer_list<Tag> children) 
        : Tag("p", children) {}
};