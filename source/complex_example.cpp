#include "Tag.h"
#include "Img.h"
#include "Paragraph.h"
#include <string>
#include <iostream>

using namespace std;

void complexExample() {
    Tag html("html", {
        Tag("head", {
            Tag("title", "Complex HTML Document")
        }),
        Tag("body", {
            Tag("header", {
                Tag("h1", "Welcome to My Website"),
                Tag("nav", {
                    Tag("ul", {
                        Tag("li", "Home"),
                        Tag("li", "About"),
                        Tag("li", "Contact")
                    })
                })
            }),
            Tag("main", {
                P("This is the main content area."),
                Tag("section", {
                    Tag("h2", "Section 1"),
                    P("This is a paragraph in section 1."),
                    Tag("div", {
                        Tag("h3", "Subsection 1.1"),
                        P("This is a paragraph in subsection 1.1."),
                        Tag("div", {
                            Tag("h4", "Sub-subsection 1.1.1"),
                            P("This is a paragraph in sub-subsection 1.1.1.")
                        })
                    })
                }),
                Tag("section", {
                    Tag("h2", "Section 2"),
                    P("This is a paragraph in section 2."),
                    IMG("http://a.com/d.png")
                })
            }),
            Tag("footer", {
                P("This is the footer.")
            })
        })
    });

    cout << html << endl;
}