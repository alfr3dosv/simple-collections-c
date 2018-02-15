# Simple Collections C

[![simple-collections-c](https://img.shields.io/wercker/ci/wercker/docs.svg)]()
[![simple-collections-c](https://img.shields.io/badge/release-v0.1.1-blue.svg)]()

A simple and easy library for C containers written by a computer science student for other computer science students and the world

Use typed collections and a JQuery like syntax to access to methods
```
STACK_TYPE(int)

Stackint *stack_of_integers;

$(stack_of_integers).push(59);
```
#### But why?


After discussing with a teacher who believes that you can't have object oriented programming in C I created this macro monster.

### Prerequisites

A C89 compiler which has no problem with '$' in macros

### Installing

1. Go to releases and download the collections sources
2. Place it whetever you like
3. Include the module you want to use  ``#include "collections/stack.h"``

## Usage

### Stack

#### Create a stack type

``STACK_TYPE(type)`` This will create a stack of given type and it functions
```
STACK_TYPE(char)
```
#### Create an instance
``Stacktype *instance = Stacktype_init()`` This will create a instance of the typed stack
```
Stackchar *stack_of_chars = NewStackchar();
```
#### Functions
``push(item)`` Store a item passed by value
```
$(stack_of_chars).push('c');
```

``pop()`` Get the last item pushed
```
$(stack_of_chars).pop();
```

## Contributing

If you have a feature request, or have found a bug, feel free to open a new issue. 

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/alfr3dosv/simple-collections-c/tags). 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details