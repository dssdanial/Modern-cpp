### Instructions

The file `main.cpp` contains a test function for some classes, whose public interface is declared
in `Picker.h` and `theCollector.h`. Files  `Picker.cpp` and `theCollector.cpp` contain an incomplete implementation.



The objects works as follows.



The two `Picker` objects accept a full a set of `Item` objects, filter them by `Item::label` 
and give the filtered ones to the singleton `theCollector` which stores them in its internals.

At the end of the operation, the singleton `theCollector` prints the `Item::word` of the received
items using the specified ordering.

As an example, give the following `collection`

```C++
std::vector<Item> collection =
{
    {1, LABEL::one, "aaa"}, {3, LABEL::one, "ddd"}, {11,LABEL::one, "bbbb"}, {10, LABEL::four, "ddd"}, 
    {21, LABEL::six, "enjoy"}, {25, LABEL::six, "assigment!"}, {7, LABEL::two, "of"}, {22, LABEL::six, "your"}
};
```
 if the collector receives all the items with label `LABEL::six` it will print:

```
enjoy your assignment!
```



In order to successfully complete the assignment you have to:

- fill the implementation of the objects so that they do what explained above,
- add a brief explanation inside [docs/report.md](./docs/report.md),
- have a project which compiles without errors,
- have the proper binary `./y2023` which prints the correct message.



### Some help



#### To work in local:

```bash
git clone https://github.com/icub-training/<your-assignment-repo>.git
cd <your-assignment-repo>
```

#### To create the `solution` branch:

```bash
git checkout -b solution
git push -u origin solution
```

#### To add a newly created file `foo.h` to the `solution` branch:

```bash
git add foo.h
git commit -m "added foo.h¨
git push origin solution
```

Find out how https://github.com/icub-training/<your-assignment-repo> contains the new file within the solution branch.



#### To push changes to a file `file.cpp` into the `solution` branch:

```bash
git add file.cpp
git commit -m "changed file.h¨
git push origin solution
```

In https://github.com/icub-training/<your-assignment-repo>, the solution branch contains now the modifications.
