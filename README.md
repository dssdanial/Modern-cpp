
<!-- blank line kept intentionally
# assignment_modern-cpp
Repository hosting the assignment of the modern c++ course

This repository can be used with [GitHub Codespaces](https://docs.github.com/en/codespaces/overview) and is already configured to use CMake, gcc, gdb and Visual Studio Code to execute the assignment.

## How to complete the assignment 📖

- Open your Codespace and complete what described in [here](./y2023/TODO.md) .
- Once done commit and push on `solution` branch.
- Open a PR from `solution` against the `master` branch of your repo, one of the teachers will do a review of your work. 
 -->

## C++ Assignment Explanation and Implementation Guidline



### Instructions

The file `main.cpp` contains a test function for some classes, whose public interface is declared
in `Picker.h` and `theCollector.h`. Files  `Picker.cpp` and `theCollector.cpp` contain an incomplete implementation.

The objects works as follows. The two `Picker` objects accept a full a set of `Item` objects, filter them by `Item::label` 
and give the filtered ones to the singleton `theCollector` which stores them in its internals.

At the end of the operation, the singleton `theCollector` prints the `Item::word` of the received
items using the specified ordering.



## Solution
In the `Picker.cpp`, each Picker receives a list of Items and a list of LABELs and selects those items whose labels match the given criteria. I used a simple iteration combined with `std::find()` to determine if each Item should be passed on.

### 1- Changes made in the `Picker.cpp`:
We need to iterate over the full Item sets, then, filter items based on matching LABEL. Then for each match, calls add() to send the item to the collector. Here is the code:

```C

bool filter(const std::vector<Item>& set, const std::initializer_list<LABEL>& labels) {
    bool found = false;
    for (const auto& item : set) {
        if (std::find(labels.begin(), labels.end(), item.label) != labels.end()) {
            add(item); // here if it satisfies the creteria, will call add() to send the item to the collector.
            found = true;
        }
    }
    return found;
}
```

Using `std::initializer_list<LABEL>` gives the caller a syntax for passing one or more labels, such as:
```C++
filter(thewords, {LABEL::one, LABEL::two});

```
Some definition to store names:
```C
std::string m_name; // This will store the name of each Picker
Picker *m_owner;   // This will store a pointer to the Picker to identify who is sending to theCollector
```
Then, Initializes the Picker’s name and stores reference to the Picker.
```C++
Impl(const Config &config, Picker *o)
    : m_name(config.name), m_owner(o) {}

```

Then, the returning part didn't do anything and needed to be modified. So, the Picker's name will be return now:

```C++
std::string name() const {
    return m_name;
}
```

Then, we need to send a matching Item to the collector. So, we need to modify the function `add`. Then we use the `m_owner`, so the collector knows which Picker sent it.

```C
void add(const Item &item) {
    theCollector::getInstance().receive(item, m_owner);
}

```


### 2- Changes made in the `theCollector.cpp`:

The collector is a singleton object. I used `push_back` to send the picked items to the list while received.
```C++
bool receive(const Item& item, Picker* from) {
    items.push_back(item);
    return true;
}
```
Also, the function `clear` didn't work correctly. So, here is the changes made to clear all stored items:
```C++
bool clear() {
    items.clear();
    return true;
}
```
Then, for the printing part, it was just print a sentence nothing else. So, here is the changes I made to print each picked word based on sorted `id` and with a space between:
```C++
bool print(PrintMode pm) {
    if (pm == PrintMode::orderedBYid) {
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.id < b.id;
        });
        for (const auto& item : items) {
            std::cout << item.word << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

```

## Result
With this implementation, running the test will produce this command:

```html
the answer to the ultimate question of life the universe and everything is 42

```

## Conclusion
This assignment effectively demonstrates key modern C++ techniques to build a modular, and maintainable data-processing pipeline. The use of enums (enum class) ensures safe and scoped categorization of data, while the Pimpl encapsulates internal logic and apply better abstraction.

 Additionally, the use of smart pointers (std::unique_ptr) ensures proper resource management, which aligns with best practices in this modern C++ course.



