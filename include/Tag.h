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
        static int indent = 0;
        string indentation(indent * 2, ' ');

        os << indentation << "<" << tag.name;

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
                os << indentation << "  " << tag.text << endl;

            indent++;
            for (auto const& child : tag.children)
                os << child;
            indent--;

            os << indentation << "</" << tag.name << ">" << endl;
        }
        return os;
    }

    protected:

    public:
        Tag(string const& name, string const& text) : name(name), text(text) {}
        Tag(string const& name, vector<Tag> const& children) : name(name), children(children) {}
};