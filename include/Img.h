#pragma once
#include "Tag.h"

struct IMG : Tag
{
    explicit IMG(const string& url) : Tag("img", "")
    {
        attributes.emplace_back(make_pair("src", url));
    }
};