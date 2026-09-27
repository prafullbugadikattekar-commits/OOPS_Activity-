# Object Oriented Programming (OOP) with C++ - Practical Codebook

## Student Profile

| Field | Details |
| :--- | :--- |
| **Student Name** | Prafull Bugadikattekar |
| **Course Name** | Object Oriented Programming with C++ |
| **Repository** | Cpp_Codebook |
| **Academic Year** | 2025–2026 |

---

## Repository Overview

This repository contains a comprehensive, structured collection of C++ programming practicals demonstrating the core tenets and advanced paradigms of **Object-Oriented Programming (OOP)**. Every program is verified for standard C++ compilation (`g++`), contains standard input/output handling, and includes real-world application problems and mini projects for each unit.

---

## 📁 Repository Structure

```text
Cpp_Codebook/
├── .gitignore
├── README.md
├── Unit-1/
│   ├── 01_basic_data_types.cpp
│   ├── 02_if_else.cpp
│   ├── 03_loop_and_array.cpp
│   ├── 04_functions.cpp
│   ├── 05_class_and_object.cpp
│   ├── 06_constructor_and_destructor.cpp
│   ├── 07_static_member.cpp
│   ├── 08_inline_and_friend_function.cpp
│   └── real_life_eg/
│       ├── 1st.cpp
│       ├── 2nd.cpp
│       ├── 3rd.cpp
│       └── mini_project1.cpp
├── Unit-2/
│   ├── 01_basic_single_inheritance.cpp
│   ├── 02_protected_member_access.cpp
│   ├── 03_public_versus_private_inheritance.cpp
│   ├── 04_multilevel_inheritance.cpp
│   ├── 05_hierarchical_inheritance.cpp
│   ├── 06_multiple_inheritance.cpp
│   ├── 07_resolving_multiple_inheritance_ambiguity.cpp
│   ├── 08_constructor_and_destructor_order.cpp
│   ├── 09_parameterized_base_constructor.cpp
│   ├── 10_function_overriding.cpp
│   ├── 11_abstract_class.cpp
│   ├── 12_virtual_base_class_and_diamond_inheritance.cpp
│   ├── 13_friend_class.cpp
│   ├── 14_nested_class.cpp
│   ├── 15_mini_project_vehicle_rental_system.cpp
│   ├── 16_mini_project_employee_payroll_system.cpp
│   └── real_life_eg/
│       ├── 4th.cpp
│       ├── 5th.cpp
│       ├── 6th.cpp
│       └── mini_project2.cpp
└── Unit-3/
    ├── 01_function_overloading.cpp
    ├── 02_area_calculator_using_function_overloading.cpp
    ├── 03_unary_minus_operator_overloading.cpp
    ├── 04_prefix_and_postfix_increment_operator_overloading.cpp
    ├── 05_binary_plus_operator_overloading_complex_numbers.cpp
    ├── 06_relational_operator_overloading.cpp
    ├── 07_friend_non_member_operator_overloading.cpp
    ├── 08_base_pointer_without_virtual_function.cpp
    ├── 09_base_pointer_with_virtual_function.cpp
    ├── 10_base_reference_with_virtual_function.cpp
    ├── 11_abstract_class_and_pure_virtual_function.cpp
    ├── 12_collection_of_polymorphic_shape_pointers.cpp
    ├── 13_virtual_destructor.cpp
    ├── 14_object_slicing_demonstration.cpp
    ├── 15_payment_processing_system.cpp
    ├── 16_employee_payroll_mini_project.cpp
    └── real_life_eg/
        ├── 7th.cpp
        ├── 8th.cpp
        ├── 9th.cpp
        └── mini_project3.cpp
```

---

## Unit 1: Basics of OOP

### Core Practicals

| # | Program Title | Program File | Brief Description |
| :-: | :--- | :--- | :--- |
| 1 | Program 1: Basic Data Types | [`01_basic_data_types.cpp`](./Unit-1/01_basic_data_types.cpp) | Demonstrates basic console I/O, variable initialization (`int`, `char`, `float`), and standard formatting. |
| 2 | Program 2: if-else | [`02_if_else.cpp`](./Unit-1/02_if_else.cpp) | Implements decision-making branching using `if-else` conditional control structure. |
| 3 | Program 3: Loop and Array | [`03_loop_and_array.cpp`](./Unit-1/03_loop_and_array.cpp) | Demonstrates fixed-size 1D array traversal using a standard `for` loop. |
| 4 | Program 4: Functions | [`04_functions.cpp`](./Unit-1/04_functions.cpp) | Demonstrates function declaration, definition, and call-by-value argument passing. |
| 5 | Program 5: Class and Object | [`05_class_and_object.cpp`](./Unit-1/05_class_and_object.cpp) | Defines a `Student` class with member attributes (`name`, `age`) and a member function `show()`. |
| 6 | Program 6: Constructor and Destructor | [`06_constructor_and_destructor.cpp`](./Unit-1/06_constructor_and_destructor.cpp) | Illustrates automatic constructor invocation upon object creation and destructor invocation at scope exit. |
| 7 | Program 7: Static Member | [`07_static_member.cpp`](./Unit-1/07_static_member.cpp) | Implements a static variable `count` shared across all class instances to track object creation count. |
| 8 | Program 8: Inline and Friend Function | [`08_inline_and_friend_function.cpp`](./Unit-1/08_inline_and_friend_function.cpp) | Demonstrates performance optimization via `inline` getter and external access to private data via `friend` function. |

### Real-Life Applications & Mini Project

| Program Title | Program File | Brief Description |
| :--- | :--- | :--- |
| Soil Sensor System | [`1st.cpp`](./Unit-1/real_life_eg/1st.cpp) | Agricultural IoT soil moisture monitoring using sensor data attributes and reading updates. |
| Student Attendance Management | [`2nd.cpp`](./Unit-1/real_life_eg/2nd.cpp) | Real-world student attendance tracker calculating percentage and status reports. |
| E-Commerce Product Catalog | [`3rd.cpp`](./Unit-1/real_life_eg/3rd.cpp) | Inventory catalog managing products, pricing, stock quantities, and static product counters. |
| **Mini Project 1: Smart Home Dashboard** | [`mini_project1.cpp`](./Unit-1/real_life_eg/mini_project1.cpp) | Smart home automation dashboard controlling multiple connected appliances (lights, thermostat, locks, camera). |

---

## Unit 2: Inheritance

### Core Practicals

| # | Concept Title | Program File | Brief Description |
| :-: | :--- | :--- | :--- |
| 1 | Concept 1: Basic Single Inheritance | [`01_basic_single_inheritance.cpp`](./Unit-2/01_basic_single_inheritance.cpp) | Derives `Student` from base class `Person` using constructor member initialization list. |
| 2 | Concept 2: Protected Member Access | [`02_protected_member_access.cpp`](./Unit-2/02_protected_member_access.cpp) | Demonstrates `protected` access specifier allowing derived class `Developer` to access base `Employee` data directly. |
| 3 | Concept 3: Public versus Private Inheritance | [`03_public_versus_private_inheritance.cpp`](./Unit-2/03_public_versus_private_inheritance.cpp) | Compares public inheritance with private inheritance using a public member wrapper to access base functionality. |
| 4 | Concept 4: Multilevel Inheritance | [`04_multilevel_inheritance.cpp`](./Unit-2/04_multilevel_inheritance.cpp) | Models a hierarchy: `Person` -> `Employee` -> `Manager`, chaining constructors across three levels. |
| 5 | Concept 5: Hierarchical Inheritance | [`05_hierarchical_inheritance.cpp`](./Unit-2/05_hierarchical_inheritance.cpp) | Derives multiple sub-classes (`Car` and `Bike`) from a common base class `Vehicle`. |
| 6 | Concept 6: Multiple Inheritance | [`06_multiple_inheritance.cpp`](./Unit-2/06_multiple_inheritance.cpp) | Demonstrates `Student` inheriting from two independent base classes (`Academic` and `Sports`) to compute total score. |
| 7 | Concept 7: Resolving Multiple-Inheritance Ambiguity | [`07_resolving_multiple_inheritance_ambiguity.cpp`](./Unit-2/07_resolving_multiple_inheritance_ambiguity.cpp) | Resolves member name collisions from multiple parent classes using explicit scope resolution operator `::`. |
| 8 | Concept 8: Constructor and Destructor Order | [`08_constructor_and_destructor_order.cpp`](./Unit-2/08_constructor_and_destructor_order.cpp) | Demonstrates order of constructor execution (base first) and destructor execution (derived first, reverse order). |
| 9 | Concept 9: Parameterized Base Constructor | [`09_parameterized_base_constructor.cpp`](./Unit-2/09_parameterized_base_constructor.cpp) | Passes arguments from derived class constructor directly into base class parameterized constructor. |
| 10 | Concept 10: Function Overriding | [`10_function_overriding.cpp`](./Unit-2/10_function_overriding.cpp) | Demonstrates function overriding by redefining `move()` across `Car` and `Boat` derived from `Vehicle`. |
| 11 | Concept 11: Abstract Class | [`11_abstract_class.cpp`](./Unit-2/11_abstract_class.cpp) | Defines pure virtual function `area() = 0` in abstract class `Shape`, implemented in `Rectangle` and `Circle`. |
| 12 | Concept 12: Virtual Base Class and Diamond Inheritance | [`12_virtual_base_class_and_diamond_inheritance.cpp`](./Unit-2/12_virtual_base_class_and_diamond_inheritance.cpp) | Resolves diamond multipath inheritance using `virtual public Person` in `TeachingAssistant`. |
| 13 | Concept 13: Friend Class | [`13_friend_class.cpp`](./Unit-2/13_friend_class.cpp) | Grants class `Auditor` complete access to private member `balance` of class `Account`. |
| 14 | Concept 14: Nested Class | [`14_nested_class.cpp`](./Unit-2/14_nested_class.cpp) | Declares and instantiates an inner class `University::Department` encapsulated within outer class scope. |
| 15 | Concept 15: Mini-Project Vehicle Rental System | [`15_mini_project_vehicle_rental_system.cpp`](./Unit-2/15_mini_project_vehicle_rental_system.cpp) | Real-world vehicle rental application with base `Vehicle` and specialized discount logic in `Car` and `Bike`. |
| 16 | Concept 16: Mini-Project - Employee Payroll System | [`16_mini_project_employee_payroll_system.cpp`](./Unit-2/16_mini_project_employee_payroll_system.cpp) | Computes salary across `PermanentEmployee` and `ContractEmployee` through abstract base contract `Employee`. |

### Real-Life Applications & Mini Project

| Program Title | Program File | Brief Description |
| :--- | :--- | :--- |
| Employee Payroll System | [`4th.cpp`](./Unit-2/real_life_eg/4th.cpp) | Hierarchy of full-time, part-time, and intern employees with polymorphic salary computation. |
| Digital Payment Gateway | [`5th.cpp`](./Unit-2/real_life_eg/5th.cpp) | Secure payment processing supporting credit card, UPI, and net banking using abstract interfaces. |
| Vehicle Fleet Management | [`6th.cpp`](./Unit-2/real_life_eg/6th.cpp) | Fleet management tracking trucks, delivery vans, and bikes with capacity and status management. |
| **Mini Project 2: Bank Account System** | [`mini_project2.cpp`](./Unit-2/real_life_eg/mini_project2.cpp) | Banking transaction system with savings accounts, current accounts with overdraft, and fixed deposits. |

---

## Unit 3: Polymorphism

### Core Practicals

| # | Concept Title | Program File | Brief Description |
| :-: | :--- | :--- | :--- |
| 1 | Concept 1: Function Overloading | [`01_function_overloading.cpp`](./Unit-3/01_function_overloading.cpp) | Overloads `add()` for different parameter counts and distinct types (`int`, `double`). |
| 2 | Concept 2: Area Calculator Using Function Overloading | [`02_area_calculator_using_function_overloading.cpp`](./Unit-3/02_area_calculator_using_function_overloading.cpp) | Computes area of square, rectangle, and circle using polymorphic signatures for `calculateArea()`. |
| 3 | Concept 3: Unary Minus Operator Overloading | [`03_unary_minus_operator_overloading.cpp`](./Unit-3/03_unary_minus_operator_overloading.cpp) | Overloads unary operator `operator-()` to invert object sign for `Number`. |
| 4 | Concept 4: Prefix and Postfix Increment Operator Overloading | [`04_prefix_and_postfix_increment_operator_overloading.cpp`](./Unit-3/04_prefix_and_postfix_increment_operator_overloading.cpp) | Overloads `++` operator for both pre-increment (`operator++()`) and post-increment (`operator++(int)`). |
| 5 | Concept 5: Binary + Operator Overloading for Complex Numbers | [`05_binary_plus_operator_overloading_complex_numbers.cpp`](./Unit-3/05_binary_plus_operator_overloading_complex_numbers.cpp) | Overloads `operator+` to compute component-wise sum of two `Complex` numbers. |
| 6 | Concept 6: Relational Operator Overloading | [`06_relational_operator_overloading.cpp`](./Unit-3/06_relational_operator_overloading.cpp) | Overloads boolean comparison operator `operator>` to compare two `Distance` objects. |
| 7 | Concept 7: Friend/Non-Member Operator Overloading | [`07_friend_non_member_operator_overloading.cpp`](./Unit-3/07_friend_non_member_operator_overloading.cpp) | Enables commutative binary addition `int + Complex` using non-member friend function. |
| 8 | Concept 8: Base Pointer Without a Virtual Function | [`08_base_pointer_without_virtual_function.cpp`](./Unit-3/08_base_pointer_without_virtual_function.cpp) | Demonstrates compile-time static binding when invoking member function via base class pointer without `virtual`. |
| 9 | Concept 9: Base Pointer With a Virtual Function | [`09_base_pointer_with_virtual_function.cpp`](./Unit-3/09_base_pointer_with_virtual_function.cpp) | Demonstrates runtime dynamic binding and polymorphism using base pointer `Animal*` pointing to `Dog` and `Cat`. |
| 10 | Concept 10: Base Reference With a Virtual Function | [`10_base_reference_with_virtual_function.cpp`](./Unit-3/10_base_reference_with_virtual_function.cpp) | Dynamically invokes specialized `area()` methods via polymorphic base reference `const Shape&`. |
| 11 | Concept 11: Abstract Class and Pure Virtual Function | [`11_abstract_class_and_pure_virtual_function.cpp`](./Unit-3/11_abstract_class_and_pure_virtual_function.cpp) | Implements pure virtual function interface for `Rectangle` derived from abstract `Shape`. |
| 12 | Concept 12: Collection of Polymorphic Shape Pointers | [`12_collection_of_polymorphic_shape_pointers.cpp`](./Unit-3/12_collection_of_polymorphic_shape_pointers.cpp) | Manages heterogeneous polymorphic objects using `std::vector<std::unique_ptr<Shape>>`. |
| 13 | Concept 13: Virtual Destructor | [`13_virtual_destructor.cpp`](./Unit-3/13_virtual_destructor.cpp) | Prevents undefined behavior and resource leak by ensuring derived destructor executes when deleting via base pointer. |
| 14 | Concept 14: Object Slicing Demonstration | [`14_object_slicing_demonstration.cpp`](./Unit-3/14_object_slicing_demonstration.cpp) | Demonstrates object slicing caused by pass-by-value versus polymorphic preservation via pass-by-reference. |
| 15 | Concept 15: Payment Processing System | [`15_payment_processing_system.cpp`](./Unit-3/15_payment_processing_system.cpp) | Models an extensible payment processing architecture using abstract interface `Payment` and concrete implementations. |
| 16 | Concept 16: Employee Payroll Mini-Project | [`16_employee_payroll_mini_project.cpp`](./Unit-3/16_employee_payroll_mini_project.cpp) | Formats and outputs polymorphic employee payroll through `const Employee&`. |

### Real-Life Applications & Mini Project

| Program Title | Program File | Brief Description |
| :--- | :--- | :--- |
| CAD Shape Drawing System | [`7th.cpp`](./Unit-3/real_life_eg/7th.cpp) | Computer-Aided Design shape renderer calculating areas and drawing circles, rectangles, and triangles. |
| Complex Number Calculator | [`8th.cpp`](./Unit-3/real_life_eg/8th.cpp) | Mathematical complex number calculations using overloaded operators `+`, `-`, `*`, and `==`. |
| Input Validation Service | [`9th.cpp`](./Unit-3/real_life_eg/9th.cpp) | Function overloading to validate numeric grades, transaction amounts, and customer names. |
| **Mini Project 3: Multimedia Player** | [`mini_project3.cpp`](./Unit-3/real_life_eg/mini_project3.cpp) | Polymorphic media player playlist managing audio, video streams, and image viewer components. |

---

## 🛠️ How to Compile & Run

All programs use standard C++ (compatible with C++11, C++14, and C++17) and can be compiled using `g++` (MinGW / GCC) or `clang++`.

### Compiling Any Specific Program

```bash
# Example : Compile and run Unit 1 practical
g++ Unit-1/01_basic_data_types.cpp -o run.exe
./run.exe

```

---

