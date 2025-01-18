#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
struct Tag 
{
    std::string name;
    std::string text;
    std::string value;
    vector<Tag> children;
    vector< pair<string,string> > attributes;

    friend ostream& operator<<(ostream& os, Tag const& tag)
    {
        os << "<" << tag.name;

        for (auto const& att : tag.attributes)
            os << " " << att.first << "=\"" << att.second << "\"";

        if (tag.children.size() == 0 && tag.text.length() == 0)
        {
            os << "/>" << endl;
        }
        else
        {
            os << ">" << endl;

            if (tag.text.length())
                os << tag.text << endl;

            for (auto const& child : tag.children)
                os << child;

            os << "</" << tag.name << ">" << endl;
        }
        return os;
    }

    protected:

    public:
    Tag(string const& name, string const& text)
        : name(name), text(text) {}
    Tag(string const& name, vector<Tag> const& children)
        : name(name), children(children) {}
};