# CPP-Module-06
 This module is designed to help you understand the different casts in CPP. 

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

```cpp

double doubleValue = 3.14;
int intValue = static_cast<int>(doubleValue); // Static cast
```

### 4. Dynamic Cast:

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
