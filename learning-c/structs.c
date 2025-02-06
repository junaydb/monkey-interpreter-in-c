#include <stdio.h>

// A struct is kind of like a class with no methods. It just has members. 
struct car {
  char* name;
  float price;
  int speed;
};

int set_price(float new_price, struct car* car) {
  car->price = new_price;
}

int main(void) {
  struct car honda = {"Honda Civic", 19999.99, 120}; // Initialising variable "honda" of type "struct car"
  printf("Name: %s\n", honda.name);
  printf("Price: %f\n", honda.price);
  printf("Speed: %d\n", honda.speed);

  struct car nissan = {.speed=120, .name="Nissan Skyline"}; // Order independant
  printf("Name: %s\n", nissan.name);
  printf("Price: %f\n", nissan.price); // Will be 0.0 because it's uninitialised
  printf("Speed: %d\n", honda.speed);

  set_price(90000, &nissan);
  printf("Price: %f\n", nissan.price); // Will be 0.0 because it's uninitialised
  
  struct car toyota;
  toyota = nissan; // Shallow copy 
}
