#include <stdio.h>

// You can take an existing type and make an alias for it with typedef
typedef int antelope; // typedef follows scoping rules, so this typedef is global
antelope x = 10;
//
// Now for some actual use cases:
//
// Sometimes a struct will be typedef'd to a new name to avoid having to type the
// word 'struct' over and over:
struct animal {
  char* name;
  int leg_count, speed;
};
//
//     original name  new name
//            |         |
//      |-----------| |----|
typedef struct animal animal;
struct animal y; // Without the typedef
animal z; // Using the typedef
//
// The above can be compressed into the following:
//
//     original name
//            |     
//      |---------| 
typedef struct car {
  char* make, model;
  int price;
} car; // <-- new name
//
// Another shortcut is using anonymoues strucures:
//
//    Anonymous struct! It has no name! 
//            |     
//      |----| 
typedef struct {
  int x, y;
} point; // <-- new name
// struct point p; // ERROR: no longer works, no such struct!
point p; // Works because "point" is an alias
//
// Using typedef with a simple type like int isn't completely useless. 
// It helps you abstrat the types to make them easier to change later. E.g.:
//
typedef float app_float;
app_float f1, f2, f3;
//
// If for some reason all float's needed to be changed to double's, we would
// simply only need to change the typedef.

int main(void) {

}
