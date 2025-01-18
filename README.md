# Groovy-Style Builder Pattern

This project demonstrates the Groovy-Style Builder pattern in C++. The pattern is used to create complex objects step-by-step, often used for constructing HTML or XML documents. The builder pattern allows for a more readable and maintainable way to create nested structures.

## Code Explanation

### `Tag.h`

1. **Definition of the `Tag` structure**:
    ```cpp
    struct Tag 
    {
        std::string name;
        std::string text;
        std::string value;
        vector<Tag> children;
        vector< pair<string,string> > attributes;
    ```
    - `name`: Name of the HTML tag.
    - `text`: Text content inside the tag.
    - `children`: List of child tags.
    - `attributes`: List of tag attributes.

2. **Overloading the `<<` operator**:
    ```cpp
    friend ostream& operator<<(ostream& os, Tag const& tag)
    ```
    - Allows printing the `Tag` structure as a formatted HTML string.

3. **Constructors of `Tag`**:
    ```cpp
    Tag(string const& name, string const& text) : name(name), text(text) {}
    Tag(string const& name, vector<Tag> const& children) : name(name), children(children) {}
    ```
    - Initialize a tag with a name and text, or with a name and a list of children.

### `Paragraph.h`

1. **Definition of the [P](http://_vscodecontentref_/0) structure**:
    ```cpp
    struct P : Tag
    {
        P(string const& text) : Tag("p", text) {}
        P(initializer_list<Tag> children) 
            : Tag("p", children) {}
    };
    ```
    - [P](http://_vscodecontentref_/1) inherits from `Tag` and represents an HTML `<p>` tag.
    - It has two constructors:
        - One that initializes with text.
        - Another that initializes with a list of children.

### `Img.h`

1. **Definition of the [IMG](http://_vscodecontentref_/2) structure**:
    ```cpp
    struct IMG : Tag
    {
        explicit IMG(const string& url) : Tag("img", "")
        {
            attributes.emplace_back(make_pair("src", url));
        }
    };
    ```
    - [IMG](http://_vscodecontentref_/3) inherits from `Tag` and represents an HTML `<img>` tag.
    - The constructor initializes the tag with a `src` attribute containing the image URL.

### [main.cpp](http://_vscodecontentref_/4)

1. **[main](http://_vscodecontentref_/5) function**:
    ```cpp
    int main() {
        cout << P {
            IMG { "http://a.com/b.png" },
            IMG { "http://a.com/c.png" }
        } << endl;
        
        return 0;
    }
    ```
    - Creates an instance of [P](http://_vscodecontentref_/6) with two child [IMG](http://_vscodecontentref_/7) tags.
    - Prints the generated HTML structure.

### Calls and Program Flow

1. **Creating [IMG](http://_vscodecontentref_/8)**:
    ```cpp
    IMG { "http://a.com/b.png" }
    ```
    - Calls the [IMG](http://_vscodecontentref_/9) constructor with the URL.
    - The [IMG](http://_vscodecontentref_/10) constructor calls the `Tag` constructor with `"img"` and an empty string.
    - Adds the `src` attribute with the provided URL.

2. **Creating [P](http://_vscodecontentref_/11)**:
    ```cpp
    P {
        IMG { "http://a.com/b.png" },
        IMG { "http://a.com/c.png" }
    }
    ```
    - Calls the [P](http://_vscodecontentref_/12) constructor with an initializer list of `Tag`.
    - The [P](http://_vscodecontentref_/13) constructor calls the `Tag` constructor with `"p"` and the list of children.

3. **Printing [P](http://_vscodecontentref_/14)**:
    ```cpp
    cout << P { ... } << endl;
    ```
    - Calls the overloaded `<<` operator for `Tag`.
    - The operator constructs the HTML string by iterating over attributes and children.

This is the complete flow of the program and how each call relates to the others.