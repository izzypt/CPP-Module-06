# CPP-Module-06
 This module is designed to help you understand the different casts in CPP. 


 # Table of Content

 - [Type Conversion](#conversion)
 - [Differences and profile of each Cast](#differences)
 - [std::numeric_imits](#limits)
 - [Static member functions and variables](#static)

<a id="conversion"></a>
# Type Conversion

In C++, type conversion refers to <ins>the process of converting a value from one data type to another</ins>. 

There are several types of type conversions in C++:

### 1. Implicit Conversion (Automatic Type Conversion):

```cpp

int intValue = 5;
float floatValue = intValue; // Implicit conversion from int to float
```

### 2. Explicit Conversion (Type Casting):

2.1 - C-Style Casting:

```cpp

double doubleValue = 3.14;
int intValue = (int)doubleValue; // C-style casting
```

2.2 - Functional Casting:

```cpp

double doubleValue = 3.14;
int intValue = int(doubleValue); // Functional casting
```

### 3. Static Cast:
The static_cast operator takes an expression as input, and returns the evaluated value converted to the type specified inside the angled brackets. 

static_cast is best used to convert one fundamental type into another.

```cpp

double doubleValue = 3.14;
int intValue = static_cast<int>(doubleValue); // Static cast
```

The main advantage of static_cast is that it provides compile-time type checking, making it harder to make an inadvertent error.

static_cast is also (intentionally) less powerful than C-style casts, so you can’t inadvertently remove const or do other things you may not have intended to do.

### 4. Dynamic Cast:

Although dynamic casts have a few different capabilities, by far the most common use for dynamic casting is for converting base-class pointers into derived-class pointers. 

This process is called downcasting

```cpp

class Base {
  // ...
};

class Derived : public Base {
  // ...
};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Dynamic cast
```

<a id="differences"></a>
# Differences and profile of each cast

### Static Cast:

  - Used for conversions between related types.
  - Resolved at compile-time.
  - Generally performs simple conversions, such as widening or narrowing of numeric types.
  - Safer than C-style casting but doesn't provide runtime type checking.

```cpp

double doubleValue = 3.14;
int intValue = static_cast<int>(doubleValue); // Static cast
```

### Dynamic Cast:

  - Primarily used in polymorphic class hierarchies (classes with at least one virtual function).
  - Performs a runtime check to ensure the conversion is valid.
  - Returns a null pointer if the conversion is not possible (when dealing with pointers), or throws a std::bad_cast exception (when dealing with references).
  - Provides a safer way to downcast within inheritance hierarchies.

```cpp

class Base {
  // ...
};

class Derived : public Base {
  // ...
};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Dynamic cast
```

### Const Cast:

 - Used to add or remove the const qualifier from a variable.
 - Allows modifying a variable that was originally declared as const.
 - Should be used with caution to avoid undefined behavior.

```cpp

const int constValue = 42;
int nonConstValue = const_cast<int>(constValue); // Remove const qualifier
```

### Reinterpret Cast:

 - Converts a pointer type to another pointer type, even if they are not related.
 - Often used for low-level casting, such as casting between pointers and integers.
 - Considered unsafe and should be used with caution.

```cpp

    int intValue = 42;
    double* doublePtr = reinterpret_cast<double*>(&intValue); // Reinterpret cast
```

In summary, each type of cast serves a specific purpose:

 - Static cast is a general-purpose cast for related types, performed at compile-time.
 - Dynamic cast is used for safe downcasting in polymorphic class hierarchies, with runtime type checking.
 - Const cast is used to add or remove the const qualifier.
 - Reinterpret cast is a low-level cast that is less safe and should be used carefully.

<a id="limits"></a>
# std::numeric_limits

`std::numeric_limits` is a template class in the C++ Standard Library that provides information about the properties of numeric types. 

It is defined in the `<limits>` header and is part of the `<limits>` header template library.

> The primary purpose of `std::numeric_limits` is to provide a standardized way to obtain information about the characteristics of numeric types, such as the minimum and maximum representable values, whether the type is signed or unsigned, and other properties.

Here are some common members of `std::numeric_limits`:

- **`min()` and `max()`**: These functions return the minimum and maximum finite representable values of a numeric type.

- **`lowest()`**: This function returns the most negative finite representable value for a floating-point type.

- **`is_integer`**: A boolean value indicating whether the type is an integer type (`true` for integer types, `false` for floating-point types).

- **`is_signed`**: A boolean value indicating whether the type is signed (`true` for signed types, `false` for unsigned types).

- **`digits` and `digits10`**: These members indicate the number of binary digits (bits) and decimal digits that can be represented exactly in the given numeric type.

- **`epsilon()`**: Returns the difference between 1 and the smallest value greater than 1 that is representable for the given floating-point type.

- **`infinity()` and `quiet_NaN()`**: Return positive infinity and a quiet NaN (Not a Number) for floating-point types.

Here's a simple example demonstrating the use of `std::numeric_limits`:

```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Is int signed? " << std::numeric_limits<int>::is_signed << std::endl;

    std::cout << "Minimum value for float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum value for float: " << std::numeric_limits<float>::max() << std::endl;

    return 0;
}
```

This program prints information about the minimum and maximum values and signedness of `int` and `float` types using `std::numeric_limits`.

<a id="static"></a>
# Static member functions

Static member functions in C++ are class-level functions that are associated with the class itself rather than with individual instances (objects) of the class. 

They are declared using the static keyword, and we can call such a function with a class name without the need to create an object.



<a id="static_members"></a>
# Static member variables

![image](https://github.com/izzypt/CPP-Module-06/assets/73948790/a45fa92f-c0b3-4874-8d9b-87d6ed2d2530)


Before we go into the static keyword as applied to member variables, first consider the following class:

```cpp

#include <iostream>

struct Something
{
    int value{ 1 };
};

int main()
{
    Something first{};
    Something second{};

    first.value = 2;

    std::cout << first.value << '\n';
    std::cout << second.value << '\n';

    return 0;
}
```

- When we instantiate a class object, each object gets its own copy of all normal member variables. 

- In this case, because we have declared two Something class objects, we end up with two copies of value: first.value, and second.value. first.value is distinct from second.value. Consequently, the program above prints:

```
2
1
```

Member variables of a class can be made static by using the static keyword. 

Unlike normal member variables, static member variables are shared by all objects of the class. Consider the following program, similar to the above:

```cpp
#include <iostream>

struct Something
{
    static int s_value; // now static
};

int Something::s_value{ 1 }; // initialize s_value to 1

int main()
{
    Something first{};
    Something second{};

    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';
    return 0;
}
```
This program produces the following output:
```cpp
2
2
```
Because s_value is a static member variable, s_value is shared between all objects of the class. 

Consequently, first.s_value is the same variable as second.s_value. The above program shows that the value we set using first can be accessed using second!
