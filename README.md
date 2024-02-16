<h1 align="center">
	<p>
	C++ Modules
	</p>
	<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/cppe.png">
</h1>

<p align="center">
	<b><i>C "enhanced, enhanced"</i></b><br><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/aaron-22766/42_cpp?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/aaron-22766/42_cpp?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/aaron-22766/42_cpp?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/aaron-22766/42_cpp?color=green" />
</p>

---

## 📯 General info

* We have to use C++98 and compile with the `-std=c++98` flag (be careful, the macOS `c++` compiler sometimes doesn't warns you if you're using newer features, so make sure to compile on Linux to be safe)
* No norm 🥳
* Class names must be in UpperCamelCase format. Files containing class code will always be named according to the class name.
* You are allowed to use almost everything from the standard library. Thus, instead of sticking to what you already know, it would be smart to use as much as possible the C++-ish versions of the C functions you are used to.
* Forbidden: `Boost` libraries, `*printf()`, `*alloc()`, `free()`, `using namespace <ns_name>` (but `using <namespace>::<class>` is allowed), `friend` keyword
* **Containers** and **Algorithms** (`<algorithm>` header) are only allowed in Module 08 and 09
* Avoid memory leaks
* From Module 02 to 09, your classes must be designed in the **Orthodox Canonical Form**, except when explicitely stated otherwise
* No function implementation in a header file
* Headers must have **include guards**

## CPP 00

<b><i>Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Megaphone** | <ul><li>Print the arguments in upper-case</li></ul> | <ul><li>what's a namespace</li><li>`std::string`</li><li>printing with `std::cout`</li><li>`for` loop</li></ul> |
| **01: My Awesome PhoneBook** | <ul><li>PhoneBook class with 8 Contacts that can ADD, SEARCH and EXIT</li><li>A Contact has: first name, last name, nickname, phone number, and darkest secret</li><li>ADD: prompts the user for Contact fields and it gets saved in the phonebook</li><li>SEARCH: display a list of all contact names with indexes, prompt for an index to print the corresponding contact</li></ul> | <ul><li>class syntax</li><li>`public` and `private` variables/methods</li><li>`static` functions</li><li>constructor and destructor</li><li>operator `<<` overloading</li><li>default function arguments</li><li>reading a line from stdin using `std::getline`</li><li>`do while` loop</li><li>more `std::string` methods</li></ul> |
| **02: The Job Of Your Dreams** | <ul><li>Recreate a Account.cpp file from a Account.hpp file to produce the correct output</li><li>Print deposits, withdrawals and status of an account</li><li>total statistics are tracked as well</li></ul> | <ul><li>`static` variables</li><li>time formatting with `std::strftime`</li></ul> |

## CPP 01

<b><i>Memory allocation, pointers to members, references, switch statement</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: BraiiiiiiinnnzzzZ** | <ul><li>Zombie with name can **announce** himself</li><li>**newZombie** returns a heap allocated Zombie</li><li>**randomChump** makes a new Zombie that announces himself</li></ul> | <ul><li>initializer list on an argument constructor</li><li>class pointers</li><li>`new` keyword to allocate</li><li>`delete` to free the memory</li></ul> |
| **01: Moar brainz!** | <ul><li>**zombieHorde** returns a heap allocated array of Zombies</li></ul> | <ul><li>allocating arrays using `new`</li><li>using getters and setters for private variables rather than making them public</li></ul> |
| **02: HI THIS IS BRAIN** | <ul><li>Print addresses and values of string, string reference and string pointer</li></ul> | <ul><li>what's a reference and how it compares to a pointer</li></ul> |
| **03: Unnecessary violence** | <ul><li>HumanA and HumanB classes both have a Weapon</li><li>HumanB may not always have a Weapon, whereas HumanA will always be armed</li><li>Solution: HumanA has a reference to Weapon and HumanB has a pointer to Weapon (which can be NULL)</li></ul> | <ul><li>When to use pointers vs references</li></ul> |
| **04: Sed is for losers** | <ul><li>Creates a copy of the file in the argument with each occurence of a given string replaced by another</li><li>`std::string::replace` is forbidden</li></ul> | <ul><li>working with files using `std::ifstream` and `std::ofstream`</li><li>`std::string` methods i.e. `erase`, `substr`</li></ul> 
| **05: Harl 2.0** | <ul><li>Harl (aka Karen) can **complain** on the four levels "DEBUG", "INFO", "WARNING" and "ERROR", that just print out a message</li><li>You must use **pointers to member functions** and it is forbidden to make a large `if/else` tree</li></ul> | <ul><li>how to work with **pointers to member functions**</li></ul> |
| **06: Harl filter** | <ul><li>Prints all messages from the given level and above</li></ul> | <ul><li>`switch` statement and "fall-through"</li></ul> |

## CPP 02

<b><i>Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: My First Class in Orthodox Canonical Form** | <ul><li>simple Fixed class with integer for raw bist</li><li>static variable defines number of fractional bits to always 8</li></ul> | <ul><li>**Orthodox Canonical Form**</li><li>copy constructor</li><li>copy assignment overload</li></ul> |
| **01: Towards a more useful fixed-point number class** | <ul><li>`int` and `float` construcors</li><li>toFloat and toInt conversion methods</li><li>operator `<<` overload for printing Fixed as a `float`</li></ul> | <ul><li>conversion between Fixed and other types using **bit-shifting**, math and `roundf`</li></ul> |
| **02: Now we’re talking** | <ul><li>overoads for comparison operators: `>`, `<`, `>=`, `<=`, `==` and `!=`</li><li>overoads for arithmetic operators: `+`, `-`, `*` and `/`</li><li>overoads for increment/decrement operators (both pre and post)</li><li>static min and max methods with both const and non-const arguments</li></ul> | <ul><li>good practice to make comparison operators depend on each other</li><li>how pre and post increment/decrement operators work on system level</li><li>**ternary operator**</li><li>printing boolean as a word using `std::boolalpha`</li></ul> |
| **03: BSP** | <ul><li>BSP stands for Binary space partitioning, though I didn't use that as it isn't really efficient for this use case</li><li>Point has const Fixed x and y variables</li><li>reconstruction in the copy assignment operator</li><li>checks if point is in triangle using vector formular</li></ul> | <ul><li>what's reconstruction and why to avoid it</li><li>always check if an algorithm is as efficient as possible for your specific use case</li></ul> |

## CPP 03

<b><i>Inheritance</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Aaaaand... OPEN!** | <ul><li>ClapTrap class with name, health, energy and damage private attributes</li><li>attack, takeDamage and beRepaired methods alter the attributes and print a pretty message</li></ul> | <ul><li>simple exercise but I tried allocating an object for the first time</li></ul> |
| **01: Serena, my love!** | <ul><li>ScavTrap inherits ClapTrap but has different values</li><li>overloads attack method for specific print message</li><li>adds guardGate method for printing a message</li></ul> | <ul><li>inheritance syntax</li><li>`virtual` keyword for making a base class method overloadable</li><li>why having a virtual destructor is important</li></ul> |
| **02: Repetitive work** | <ul><li>FragTrap inherits ClapTrap with different values again</li><li>adds highFivesGuys method for printing a message</li></ul> |  |
| **03: Now it’s weird!** | <ul><li>DiamondTrap inherits both ScavTrap and FragTrap</li><li>adds name attribute and adds suffix to ClapTrap's name</li><li>uses health and damage from FagTrap and energy, as well as attack method from ScavTrap</li><li>adds whoAmI method that prints name and ClapTrap's name</li><li>ClapTrap subobject must only be created once</li></ul> | <ul><li>**Diamond Problem** when doing multiple inheritance</li><li>`using` keyword to choose from which subclass to take method</li><li>**virtual inheritance** to only create one subobject</li></ul> |

## CPP 04

<b><i>Subtype polymorphism, abstract classes, interfaces</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Polymorphism** | <ul><li>simple Animal class gets inherited by Dog and Cat classes</li><li>Animal has makeSound method that prints nothing, but Dog and Cat overrides the function to print an applicaple message</li><li>WrongAnimal and WrongCat proove understanding of method overriding</li></ul> | <ul><li>implicitly casting pointer of derived class to pointer of base class</li><li>deepened the knowledge of the `virtual` keyword</li></ul> |
| **01: I don’t want to set the world on fire** | <ul><li>Brain class has an array of `std::string` ideas </li><li>Dog and Cat get pointer to Brain attribute that gets allocated on construction and freed on destruction<li></li>copy of ideas must be deep copies</li></ul> | <ul><li>why constructors and destructors are awesome for managing allocated memory</li></ul> |
| **02: Abstract class** | <ul><li>Animal's makeSound method is made **pure virtual**</li></ul> | <ul><li>**pure virtual** functions make classes abstract and non-instantiable, derived classed need to provide implementation if instatiation is desired</li></ul> |
| **03: Interface & recap** | <ul><li>Ice, Cure, Character and MateriaSource inherit provided abstract class AMateria and interfaces ICharacter and IMateriaSource respectively</li><li>they all have attributes and methods that take the objects (pointers) as arguments</li></ul> | <ul><li>pure abstract classes are called 'interfaces' even though they don't exist as a data structure in C++ as in other programming languages</li><li>more working with object pointers and references, as well as arrays and memory allocation with classes</li></ul> |

## CPP 05

<b><i>Repetition and Exceptions</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Mommy, when I grow up, I want to be a bureaucrat!** | <ul><li>Bureaucrat class with grade attribute and increment/decrement methods</li><li>if a Bureaucreat is constructed or the grade is increment/decrement beyond the range, a Bureaucrat::GradeTooHighException or Bureaucrat::GradeTooLowException are thrown</li></ul> | <ul><li>**exceptions** for handling errors</li><li>writing my own exception class that overrides the what function, which provides the reason for the exception</li><li>`throw` keyword, can also throw simple data types, though `std::exception` is preferred</li><li>`try catch` block</li></ul> |
| **01: Form up, maggots!** | <ul><li>Form class has name, isSigned, signGrade and executeGrade attributes</li><li>has beSigned method that signs the form if the grade of the Bureaucrat is valid according to the Form attributes, otherwise throws exceptions</li><li>signForm method is added to the Bureaucreat that calls beSigned on the provided From</li></ul> |  |
| **02: No, you need form 28B, not 28C...** | <ul><li>Form gets pure virtual execute method that makes the class abstract</li><li>ShrubberyCreationForm, RobotomyRequestForm and PresidentialPardonForm are derived from AForm with different values and implementation for the execute method</li><li>adds executeForm to the Bureaucrat</li></ul> |  |
| **03: At least this beats coffee-making** | <ul><li>Intern class has a makeForm method that takes a name of a form and returns a pointer to the correct heap allocated object</li></ul> |  |

## CPP 06

<b><i>C++ casts</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Conversion of scalar types** | <ul><li>ScalarConverter class contains static method convert which converts a string representation of `char`, `int`, `float` and `double` as literal to all four data types and prints them out</li><li>pseudo literals `inf` (positive or negative) and `nan`, both float (`inff`) or double, have to be handled as well</li></ul> | <ul><li>`static_cast` to change the datatype and keep the value</li></ul> |
| **01: Serialization** | <ul><li>Serializer class has two static methods: serialize converts Data pointer to uintptr_t, deserialize converts uintptr_t to Data pointer</li><li>Data is just an example class to proove that it works</li></ul> | <ul><li>`reinterpret_cast` changes the data type but keeping the exact same value</li></ul> |
| **02: Identify real type** | <ul><li>A, B, C classes are derived from Base class</li><li>generate function returns a random class as a Base pointer</li><li>identify prints the name of the derived class - has two implementations, one taking a Base pointer, the other taking a Base reference</li></ul> | <ul><li>`dynamic_cast` to cast at runtime</li><li>returns NULL when casting pointer, throws exception when casting object (reference)</li></ul> |

## CPP 07

<b><i>C++ templates</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Start with a few functions** | <ul><li>swap template function swaps the two given arguments</li><li>min and max template functions return the right value</li></ul> | <ul><li>**template** syntax</li></ul> |
| **01: Iter** | <ul><li>iter template function iterates over an array of any type and applies the provided function to each element</li></ul> |  |
| **02: Array** | <ul><li>Array template class has pointer that allocates an array of the provided type with the size provided at construction</li><li>operator `[]` overload lets you access elements inside the array</li><li>throws exception if index is out of bounds</li></ul> | <ul><li>template classes</li></ul> |

## CPP 08

<b><i>Templated containers, iterators, algorithms</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Easy find** | <ul><li>template function easyfind takes any container on integers and returns an iterator to the provided integer</li></ul> | <ul><li>what are **containers** and **iterators**</li><li>`std::find` algorithm to do the job</li></ul> |
| **01: Span** | <ul><li>Span class has a `std::vector` of integers with the maximum size specified on construction</li><li>addNumber and addRange (using iterators) let you add numbers to the vector</li><li>shortestSpan and longestSpan calculate the distance between any numbers in the vector</li></ul> | <ul><li>`std::sort` for faster calculation of the shortest span</li><li>`std::min_element` and `std::max_element` for very easy calculation of longest span</li></ul> |
| **02: Mutated abomination** | <ul><li>template class MutantStack inherits from `std::stack` (defaults to `std::deque` container) and adds iterator and const_iterator</li><li>begin and end methods return the corresponding iterator</li></ul> | <ul><li>multiple typenames for a template class</li><li>how iterators work in more detail</li></ul> |

## CPP 09

<b><i>STL</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
| **00: Bitcoin Exchange** | <ul><li>btc program takes file as argument which is a list of dates and values</li><li>prints the value multiplied the exchange rate according to the date indicated in a database 'csv' file</li></ul> | <ul><li>`std::map` for key-value pairs</li><li>`std:lower_bound` returns the first element smaller than value</li><li>`std::string::compare`</li><li>`std::runtime_error` for clean exception throwing</li><li>overall working on a larger project with many C++ features</li></ul> |
| **01: Reverse Polish Notation** | <ul><li>RPN program takes string of digits and operations `+`, `-`, `*` and `/` and calculates the result in **Reverse Polish Notation**</li></ul> | <ul><li>what **Reverse Polish Notation** is</li><li>`std::stack` is ideal for pushing numbers ontop then popping and calculating the top two when there is an operation and pushing pushing the result back</li></ul> |
| **02: PmergeMe** | <ul><li>PmergeMe program takes a positive integer sequence and uses **merge-insertion-sort** aka **Ford Johnson** algorithm on two containers to print a sorted sequence as well as the time it took</li><li>algorithm: splits sequence into pairs, sorts each pair, recursively **merge-sort**s the pairs according to the first value, creates a sequence of all firsts of the pairs, uses **Jacobsthal** sequence to efficiently insert the sequence of seconds of the pairs into the result sequence using **insertion-sort**</li></ul> | <ul><li>**Ford Johnson** algorithm is one of the best when it comes to low number of comparisons</li><li>what's the **Jacobsthal** sequence and why does it make the algorithm efficient</li><li>`std::vector` and `std::deque` with their methods</li><li>`std::upper_bound` which is implemented as **binary-search** (required for insersion-sort)</li></ul> |
