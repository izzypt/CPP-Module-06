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

Choosing the right cast depends on the specific needs and constraints of the code, and it's important to use them judiciously to ensure correctness and maintainability.
