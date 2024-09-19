#include <stdio.h>
#include <stdint.h>
#include "cvector/cvector.h"

typedef struct Person {
  char name[30];
  int age;
} Person;

// Define vector type
DEFINE_VECTOR(Person)

int main() {
  // Initialise vector with Vector_[Type] var_name = cvector_init_[Type]();
  Vector_Person* persons = cvector_init_Person();
  
  // to push back elements into vector
  cvector_push_back_Person(persons, (Person){.name = "Aarav", .age=25});
  cvector_push_back_Person(persons, (Person){.name = "Ishika", .age=32});
  cvector_push_back_Person(persons, (Person){.name = "Karthik", .age=29});
  cvector_push_back_Person(persons, (Person){.name = "Meera", .age=21});
  cvector_push_back_Person(persons, (Person){.name = "Rohan", .age=30});
  cvector_push_back_Person(persons, (Person){.name = "Anjali", .age=26});
  cvector_push_back_Person(persons, (Person){.name = "Virat", .age=27});
  cvector_push_back_Person(persons, (Person){.name = "Priya", .age=23});
  cvector_push_back_Person(persons, (Person){.name = "Dev", .age=35});
  cvector_push_back_Person(persons, (Person){.name = "Sana", .age=19});
  cvector_push_back_Person(persons, (Person){.name = "Amit", .age=40});
  cvector_push_back_Person(persons, (Person){.name = "Nisha", .age=28});
  cvector_push_back_Person(persons, (Person){.name = "Rahul", .age=31});
  cvector_push_back_Person(persons, (Person){.name = "Sneha", .age=22});
  cvector_push_back_Person(persons, (Person){.name = "Aryan", .age=24});
  cvector_push_back_Person(persons, (Person){.name = "Neha", .age=20});
  cvector_push_back_Person(persons, (Person){.name = "Siddharth", .age=34});
  cvector_push_back_Person(persons, (Person){.name = "Pooja", .age=27});
  cvector_push_back_Person(persons, (Person){.name = "Ravi", .age=36});
  cvector_push_back_Person(persons, (Person){.name = "Tanya", .age=18});

  // Get total elements in vector
  printf("Length of vector -> %ld\n", persons->length);
  
  // Get total size of vector in memory (to keep O(n) time complexity)
  printf("Capacity of vector -> %ld\n", persons->capacity);

  // Printing all elements in array
  // Works as normal arrays
  for (uint32_t i = 0; i < persons->length; i++) {
    printf("Person %d, Name -> %s, Age -> %d\n", (i+1), persons->data[i].name, persons->data[i].age);
  }

  // To shrink vector to save space
  cvector_shrink_to_fit_Person(persons);
  
  printf("Capacity after shrink => %d\n", persons->capacity);

  printf("First element -> %s\n", cvector_front_Person(persons).name);
  printf("Last element -> %s\n", cvector_back_Person(persons).name);
}
