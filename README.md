# Simple Collections C

[![simple-collections-c](https://img.shields.io/wercker/ci/wercker/docs.svg)]()
[![simple-collections-c](https://img.shields.io/badge/release-v0.1.1-blue.svg)]()

A simple and easy library for C containers

### Prerequisites

A C89 compiler gcc and msvc are fine

### Installing

1. Go to releases and download the collections sources
2. Place it on your project folder
3. Include the module you want to use  ``#include "collections/stack.h"``

## Usage

### Stack

#### Create a stack type

``STACK(stack_name, type)`` This will create a stack of given type and it functions
```
STACK(stack_char, char)
```
#### Create an instance

``stack_char *object = stack_char_init()`` This will create a instance of the typed stack
```
stack_char *chars = stack_char_new();
```
#### Functions

``void stack_name_push(type item)`` Store a item passed by value
```
char c = 'a';
stack_char_push(chars, 'c');
```

``type stack_name_pop(type item)`` Get the last item pushed
```
char c = stack_char_pop(&object);
```

## Contributing

If you have a feature request, or have found a bug, feel free to open a new issue.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/alfr3dosv/simple-collections-c/tags).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details