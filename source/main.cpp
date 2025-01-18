#include "Tag.h"
#include "Img.h"
#include "Paragraph.h"
#include <string>
#include <iostream>

using namespace std;

void simpleExample() {
    cout << P {
        IMG { "http://a.com/b.png" },
        IMG { "http://a.com/c.png" }
    } << endl;
}

void complexExample();
int main() {
    simpleExample();
    complexExample();
    
    return 0;
}