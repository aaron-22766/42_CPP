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
| **00 Megaphone** | <ul><li>Print the arguments in upper-case</li></ul> | <ul><li>what's a namespace</li><li>`std::string`</li><li>printing with `std::cout`</li><li>`for` loop</li></ul> |
| **01 My Awesome PhoneBook** | <ul><li>PhoneBook class with 8 Contacts that can ADD, SEARCH and EXIT</li><li>A Contact has: first name, last name, nickname, phone number, and darkest secret</li><li>ADD: prompts the user for Contact fields and it gets saved in the phonebook</li><li>SEARCH: display a list of all contact names with indexes, prompt for an index to print the corresponding contact</li></ul> | <ul><li>class syntax</li><li>`public` and `private` variables/methods</li><li>`static` functions</li><li>constructor and destructor</li><li>operator `<<` overloading</li><li>default function arguments</li><li>reading a line from stdin using `std::getline`</li><li>`do while` loop</li><li>more `std::string` methods</li></ul> |
| **02 The Job Of Your Dreams** | <ul><li>Recreate a Account.cpp file from a Account.hpp file to produce the correct output</li><li>Print deposits, withdrawals and status of an account</li><li>"bank's" total statistics as well</li></ul> | <ul><li>`static` variables</li><li>time formatting with `std::strftime`</li></ul> |

## CPP 01

<b><i>Memory allocation, pointers to members, references, switch statement</i></b>

| Exercise | Desription | Learnings |
|----------|------------|-----------|
