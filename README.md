# Simple Collections C

[![simple-collections-c](https://img.shields.io/wercker/ci/wercker/docs.svg)]()
[![simple-collections-c](https://img.shields.io/badge/release-v0.1.1-blue.svg)]()

A type-safe collections for c using macros

### Prerequisites

A C89 compiler gcc and msvc are fine

### Installing

1. Go to releases and download the collections sources
2. Place it on your project folder
3. Include the module you want to use  ``#include "collections/stack.h"``

## Examples

### Stack

Functions
* new
* push
* pop
* free

``` c

#include "stack.h"

STACK(char, Chars, chars)
// type, struct name, function prefix

int main() {
    Chars* chars = chars_new();

    chars_push(chars, 'a');
    chars_push(chars, 'b');
    chars_push(chars, 'c');


    while(chars->size > 2) {
        char c = chars_pop(chars);
        printf("Char %c", c);
    }
    return 0;
}
```

### Linked list

Functions:

* append
* pop
* insert
* get
* remove

``` c
#include "linked_list.h"

LINKED_LIST(int, ListInt, list_int);
// type, struct name, function prefix

int main() {
    ListInt* list = listint_new();
    list_int_append(list, 1);
    list_int_append(list, 2);
    list_int_append(list, 3);

    // list, position, value;
    list_int_insert(list, 0, 0);

    //remove the last item
    int last = list_int_pop(list);
}
```

### Queue

Functions

* new
* enqueue
* dequeue
* free

``` c
#include "queue.h"

struct SomeData {
    char* name;
    int id;
};

QUEUE(struct SomeData, QueueSomeData, queue);
// type, struct name, function prefix

int main() {
    QueueSomeData* data = queue_new();
    SomeData sd;
    sd.name = malloc(sizeof(char) * 500);
    strcpy(sd.name, "Ragnar Lothbrok");
    sd.id = 1;
    queue_enqueue(data, sd);
    SomeData sd2 = queue_dequeue(data);
}
```

## Contributing

If you have a feature request, or have found a bug, feel free to open a new issue.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/alfr3dosv/simple-collections-c/tags).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
