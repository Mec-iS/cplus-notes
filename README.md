# C++ basic reference examples

## Concepts

* _copying policies_: see `copy_move/` directory. Default behaviour is to use shallow
 copying for constructing and assignment. This can be changed by implementing copying
 policies.
* _memory allocation_: see `mem_management/` directory.
* _access specifier_: see `access_spec/` directory.
* _abstract classes_: see `virtual_methods/` directory.
* _lambdas_: see `lambdas`,
* _concurrency_: see `concurrency`

## Debug

### Basics

* "When printing information for debugging purposes, use std::cerr instead of std::cout" [link](https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/).
* [strategy for debugging](https://www.learncpp.com/cpp-tutorial/a-strategy-for-debugging/)

### Valgrind examples

* *memory leaks*: `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/home/workspace/valgrind-out.txt /home/workspace/a.out` (check for section "LEAK SUMMARY")

## Links
* [RAII - Resource Acquisition Is Initialization](https://en.cppreference.com/w/cpp/language/raii)
